#include "maze.h"

namespace s21 {

Maze::Maze() {}

Maze::Maze(std::vector<std::vector<Cell>> grid)
    : M_(grid.size()), N_(grid[0].size()), grid_(grid) {}

Maze::Maze(std::vector<std::vector<int>> right_walls,
           std::vector<std::vector<int>> down_walls) {
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

std::vector<std::vector<int>> Maze::getWallMatrix(WallPosition position) {
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

std::vector<std::vector<Cell>> Maze::getGrid() const { return grid_; }

void Maze::setGrid(const std::vector<std::vector<Cell>> &grid) { grid_ = grid; }

size_t Maze::getM() const { return M_; }

size_t Maze::getN() const { return N_; }

void Maze::print() {
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
}

}  // namespace s21
