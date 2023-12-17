#include <iostream>

#include "maze.h"

namespace s21 {

Maze::Maze() {}

Maze::Maze(const std::vector<std::vector<Cell>> &grid)
    : M_(grid.size()), N_(grid[0].size()), grid_(grid) {}

Maze::Maze(const std::vector<std::vector<int>> &right_walls,
           const std::vector<std::vector<int>> &down_walls) {
  size_t M = right_walls.size();
  size_t N = M == 0 ? 0 : right_walls[0].size();

  if (M != down_walls.size() || N != down_walls[0].size()) {
    return;
  }

  grid_.resize(M, std::vector<Cell>());
  M_ = M;
  N_ = N;

  for (size_t i = 0; i < M; i++) {
    for (size_t j = 0; j < N; j++) {
      Cell cell{static_cast<bool>(right_walls[i][j]),
                static_cast<bool>(down_walls[i][j])};
      grid_[i].push_back(cell);
    }
  }
}

std::vector<std::vector<int>> Maze::getWallMatrix(WallPosition position) const {
  std::vector<std::vector<int>> result(M_, std::vector<int>(N_, 0));

  for (size_t row = 0; row < M_; row++) {
    for (size_t col = 0; col < N_; col++) {
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

Maze::size_type Maze::getM() const { return M_; }

Maze::size_type Maze::getN() const { return N_; }

void Maze::print() const {
  for (size_t i = 0; i < M_; i++) {
    for (size_t j = 0; j < N_; j++) {
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
