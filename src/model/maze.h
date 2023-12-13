#ifndef __MAZE_MODEL_MAZE_H__
#define __MAZE_MODEL_MAZE_H__

#include <cstddef>
#include <iostream>
#include <vector>

namespace s21 {

struct Cell {
  bool right_wall;
  bool down_wall;
};

class Maze {
 public:
  Maze(std::vector<std::vector<Cell>>&& grid)
      : grid_(std::move(grid)), M_(grid_.size()), N_(grid_[0].size()) {}

  Maze(std::vector<std::vector<int>> right_walls,
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

  std::vector<std::vector<Cell>> getGrid() { return grid_; }

  size_t getM() { return M_; }

  size_t getN() { return N_; }

  void Print() {
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

 private:
  size_t M_{0};
  size_t N_{0};
  std::vector<std::vector<Cell>> grid_{};
};

}  // namespace s21

#endif  // __MAZE_MODEL_MAZE_H__