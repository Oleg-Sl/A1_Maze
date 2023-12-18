#ifndef __MAZE_SOURCE_MODEL_MAZE_H__
#define __MAZE_SOURCE_MODEL_MAZE_H__

#include <cstddef>
#include <random>
#include <vector>

#include "cell.h"

namespace s21 {

class Maze {
 public:
  using size_type = size_t;

  enum class WallPosition { kUp, kDown, kLeft, kRight };

  Maze();
  Maze(size_type rows, size_type cols);
  Maze(const std::vector<std::vector<Cell>> &grid);
  Maze(const std::vector<std::vector<int>> &right_walls,
       const std::vector<std::vector<int>> &down_walls);

  Cell operator()(size_t row, size_t col) const;
  Cell &operator()(size_t row, size_t col);

  std::vector<std::vector<int>> getWallMatrix(WallPosition position) const;
  std::vector<std::vector<Cell>> getGrid() const;
  size_type getM() const;
  size_type getN() const;

  void setGrid(const std::vector<std::vector<Cell>> &grid);

  void print() const;

 private:
  size_type rows_{0};
  size_type cols_{0};
  std::vector<std::vector<Cell>> grid_{};
};

}  // namespace s21

#endif  // __MAZE_SOURCE_MODEL_MAZE_H__