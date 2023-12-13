#ifndef __MAZE_MODEL_MAZEGENERATOR_H__
#define __MAZE_MODEL_MAZEGENERATOR_H__

#include "basemazegenerator.h"
#include "maze.h"

namespace s21 {

class MazeGenerator : BaseMazeGenerator {
 public:
  Maze generateMaze(size_t M, size_t N);

 private:
  void gen_preprocessing(std::vector<std::vector<Cell>>& grid, size_t num_row);
  void gen_right_walls(std::vector<Cell>& curr_row);
  void gen_down_walls(std::vector<Cell>& curr_row);
  void gen_postprocessing(std::vector<Cell>& curr_row);

 private:
  std::random_device rd{};
  std::mt19937 gen{rd()};
  std::uniform_int_distribution<> dist{0, 1};
};

}  // namespace s21

#endif  // __MAZE_MODEL_MAZEGENERATOR_H__