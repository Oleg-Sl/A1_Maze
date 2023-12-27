
#include "maze.h"

#include <iostream>

namespace s21 {

Maze::Maze() {}

Maze::Maze(size_t rows, size_t cols) {
  grid_.resize(rows, std::vector<Cell>(cols, {0, 0, 0, 0}));

  rows_ = rows;
  cols_ = cols;

  buildMazeBorder();
}

Maze::Maze(const std::vector<std::vector<Cell>> &grid)
    : rows_(grid.size()),
      cols_(grid.size() == 0 ? 0 : grid[0].size()),
      grid_(grid) {
  buildMissingWalls();
  buildMazeBorder();
}

std::vector<std::vector<int>> Maze::getWallMatrix(WallPosition position) const {
  std::vector<std::vector<int>> result(rows_, std::vector<int>(cols_, 0));

  for (size_t row = 0; row < rows_; row++) {
    for (size_t col = 0; col < cols_; col++) {
      if (position == WallPosition::kUp) {
        result[row][col] = grid_[row][col].up_wall;
      } else if (position == WallPosition::kDown) {
        result[row][col] = grid_[row][col].down_wall;
      } else if (position == WallPosition::kLeft) {
        result[row][col] = grid_[row][col].left_wall;
      } else if (position == WallPosition::kRight) {
        result[row][col] = grid_[row][col].right_wall;
      }
    }
  }

  return result;
}

Cell Maze::operator()(size_t row, size_t col) const {
  validatePosition(row, col);
  return grid_[row][col];
}

std::vector<std::vector<Cell>> Maze::getGrid() const { return grid_; }

size_t Maze::getRows() const { return rows_; }

size_t Maze::getCols() const { return cols_; }

void Maze::buildWall(size_t row, size_t col, WallPosition pos) {
  validatePosition(row, col);

  if (pos == WallPosition::kUp) {
    grid_[row][col].up_wall = 1;
    if (row != 0) grid_[row - 1][col].down_wall = 1;
  } else if (pos == WallPosition::kLeft) {
    grid_[row][col].left_wall = 1;
    if (col != 0) grid_[row][col - 1].right_wall = 1;
  } else if (pos == WallPosition::kRight) {
    grid_[row][col].right_wall = 1;
    if (col != grid_[row].size() - 1) grid_[row][col + 1].left_wall = 1;
  } else if (pos == WallPosition::kDown) {
    grid_[row][col].down_wall = 1;
    if (row != grid_.size() - 1) grid_[row + 1][col].up_wall = 1;
  }
}

void Maze::removeWall(size_t row, size_t col, WallPosition pos) {
  validatePosition(row, col);

  if (pos == WallPosition::kUp && row != 0) {
    grid_[row][col].up_wall = 0;
    grid_[row - 1][col].down_wall = 0;
  } else if (pos == WallPosition::kLeft && col != 0) {
    grid_[row][col].left_wall = 0;
    grid_[row][col - 1].right_wall = 0;
  } else if (pos == WallPosition::kRight && col != cols_ - 1) {
    grid_[row][col].right_wall = 0;
    grid_[row][col + 1].left_wall = 0;
  } else if (pos == WallPosition::kDown && row != rows_ - 1) {
    grid_[row][col].down_wall = 0;
    grid_[row + 1][col].up_wall = 0;
  }
}

void Maze::buildMazeBorder() {
  for (size_t row = 0; row < rows_; row++) {
    grid_[row][0].left_wall = 1;
    grid_[row][cols_ - 1].right_wall = 1;
  }

  for (size_t col = 0; col < cols_; col++) {
    grid_[0][col].up_wall = 1;
    grid_[rows_ - 1][col].down_wall = 1;
  }
}

void Maze::buildMissingWalls() {
  for (size_t row = 0; row < rows_; row++) {
    for (size_t col = 0; col < cols_; col++) {
      Cell &curr = grid_[row][col];

      if (row != 0) {
        grid_[row - 1][col].down_wall = curr.up_wall;
      }

      if (col != 0) {
        grid_[row][col - 1].right_wall = curr.left_wall;
      }

      if (row != rows_ - 1) {
        grid_[row + 1][col].up_wall = curr.down_wall;
      }

      if (col != cols_ - 1) {
        grid_[row][col + 1].left_wall = curr.right_wall;
      }
    }
  }
}

void Maze::validatePosition(size_t row, size_t col) const {
  if (row >= rows_ || col >= cols_) {
    throw std::invalid_argument("Invalid col or row");
  }
}

}  // namespace s21
