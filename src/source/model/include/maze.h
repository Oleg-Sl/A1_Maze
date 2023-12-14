#ifndef __MAZE_MODEL_MAZE_H__
#define __MAZE_MODEL_MAZE_H__

#include <cstddef>
#include <iostream>
#include <random>
#include <vector>

namespace s21 {

struct Cell {
  bool right_wall = 0;
  bool down_wall = 0;
  int set_id = 0;

  bool operator==(const Cell &other) const;
};

class Maze {
 public:
  Maze(std::vector<std::vector<Cell>> grid);
  Maze(std::vector<std::vector<int>> right_walls,
       std::vector<std::vector<int>> down_walls);

  std::vector<std::vector<Cell>> getGrid();
  size_t getM();
  size_t getN();

  void print();

 private:
  size_t M_{0};
  size_t N_{0};
  std::vector<std::vector<Cell>> grid_{};
};

}  // namespace s21

#endif  // __MAZE_MODEL_MAZE_H__