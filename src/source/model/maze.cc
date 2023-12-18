#include <iostream>

#include "maze.h"

namespace s21 {

Maze::Maze() {}

Maze::Maze(size_type rows, size_type cols) {
  grid_.resize(rows, std::vector<Cell>(cols, {0, 0, 0, 0}));

  rows_ = rows;
  cols_ = cols;
}

Maze::Maze(const std::vector<std::vector<Cell>> &grid)
    : rows_(grid.size()),
      cols_(grid.size() == 0 ? 0 : grid[0].size()),
      grid_(grid) {}

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

Cell Maze::operator()(size_t row, size_t col) const { return grid_[row][col]; }

Cell &Maze::operator()(size_t row, size_t col) { return grid_[row][col]; }

std::vector<std::vector<Cell>> Maze::getGrid() const { return grid_; }

void Maze::setGrid(const std::vector<std::vector<Cell>> &grid) { grid_ = grid; }

Maze::size_type Maze::getRows() const { return rows_; }

Maze::size_type Maze::getCols() const { return cols_; }

void Maze::print() const {
  for (size_t i = 0; i < rows_; i++) {
    for (size_t j = 0; j < cols_; j++) {
      bool right = grid_[i][j].right_wall;
      bool down = grid_[i][j].down_wall;

      if (right && down) {
        std::cout << "_|";
      } else if (right) {
        std::cout << " |";
      } else if (down) {
        std::cout << "__";
      } else {
        std::cout << "  ";
      }
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

}  // namespace s21
