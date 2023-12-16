#ifndef __MAZE_MODEL_MAZE_H__
#define __MAZE_MODEL_MAZE_H__

#include <cstddef>
#include <iostream>
#include <random>
#include <vector>

#include "cell.h"

namespace s21 {

class Maze {
 public:
  enum class WallPosition { kUp, kDown, kLeft, kRight };

 public:
  Maze(std::vector<std::vector<Cell>> grid);
  Maze(std::vector<std::vector<int>> right_walls,
       std::vector<std::vector<int>> down_walls);
  Maze();

  std::vector<std::vector<int>> getWallMatrix(WallPosition position);
  std::vector<std::vector<Cell>> getGrid() const;
  size_t getM() const;
  size_t getN() const;

  void setGrid(const std::vector<std::vector<Cell>> &grid);

  void print();

 private:
  size_t M_{0};
  size_t N_{0};
  std::vector<std::vector<Cell>> grid_{};
};

}  // namespace s21

#endif  // __MAZE_MODEL_MAZE_H__
