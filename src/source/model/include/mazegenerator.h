#ifndef __MAZE_MODEL_MAZEGENERATOR_H__
#define __MAZE_MODEL_MAZEGENERATOR_H__

#include "basemazegenerator.h"
#include "maze.h"

namespace s21 {

class MazeGenerator : BaseMazeGenerator {
 public:
  Maze generateMaze(size_t M, size_t N);

 private:
  void genPreprocessing(std::vector<std::vector<Cell>>& grid, size_t num_row);
  void genRightWalls(std::vector<Cell>& curr_row);
  void genDownWalls(std::vector<Cell>& curr_row);
  void genPostprocessing(std::vector<Cell>& curr_row);

 private:
  std::random_device rd_{};
  std::mt19937 gen_{rd_()};
  std::uniform_int_distribution<> dist_{0, 1};
};

}  // namespace s21

#endif  // __MAZE_MODEL_MAZEGENERATOR_H__