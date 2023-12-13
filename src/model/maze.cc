#include "include/maze.h"

namespace s21 {

bool Cell::operator==(const Cell &other) const {
  return right_wall == other.right_wall && down_wall == other.down_wall &&
         set_id == other.set_id;
}

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

std::vector<std::vector<Cell>> Maze::getGrid() { return grid_; }

size_t Maze::getM() { return M_; }

size_t Maze::getN() { return N_; }

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