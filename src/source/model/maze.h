#ifndef __MAZE_SOURCE_MODEL_MAZE_H__
#define __MAZE_SOURCE_MODEL_MAZE_H__

#include <cstddef>
#include <random>
#include <vector>

#include "cell.h"

namespace s21 {

class Maze {
 public:
  enum class WallPosition { kUp, kDown, kLeft, kRight };

  Maze();
  Maze(size_t rows, size_t cols);
  Maze(const std::vector<std::vector<Cell>> &grid);

  Cell operator()(size_t row, size_t col) const;
  Cell &operator()(size_t row, size_t col);

  std::vector<std::vector<int>> getWallMatrix(WallPosition position) const;
  std::vector<std::vector<Cell>> getGrid() const;
  size_t getRows() const;
  size_t getCols() const;

  void setGrid(const std::vector<std::vector<Cell>> &grid);

  void print() const;

 private:
  size_t rows_{0};
  size_t cols_{0};
  std::vector<std::vector<Cell>> grid_{};
};

}  // namespace s21

#endif  // __MAZE_SOURCE_MODEL_MAZE_H__