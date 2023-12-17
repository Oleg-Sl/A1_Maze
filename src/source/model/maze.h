#ifndef __MAZE_SOURCE_MODEL_MAZE_H__
#define __MAZE_SOURCE_MODEL_MAZE_H__

#include <cstddef>
#include <iostream>
#include <random>
#include <vector>

#include "cell.h"

namespace s21 {

class Maze {
 public:
  using size_type = size_t;

 public:
  enum class WallPosition { kUp, kDown, kLeft, kRight };

 public:
  Maze(std::vector<std::vector<Cell>> grid);
  Maze(std::vector<std::vector<int>> right_walls,
       std::vector<std::vector<int>> down_walls);
  Maze();

  Cell operator()(size_t row, size_t col) const;
  Cell &operator()(size_t row, size_t col);

  std::vector<std::vector<int>> getWallMatrix(WallPosition position);
  std::vector<std::vector<Cell>> getGrid() const;
  size_type getM() const;
  size_type getN() const;

  void setGrid(const std::vector<std::vector<Cell>> &grid);

  void print();

 private:
  size_type M_{0};
  size_type N_{0};
  std::vector<std::vector<Cell>> grid_{};
};

}  // namespace s21

#endif  // __MAZE_SOURCE_MODEL_MAZE_H__