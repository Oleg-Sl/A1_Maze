#ifndef __MAZE_SOURCE_MODEL_MAZE_BASEMAZEGENERATOR_H__
#define __MAZE_SOURCE_MODEL_MAZE_BASEMAZEGENERATOR_H__

#include "maze.h"

namespace s21 {

class BaseMazeGenerator {
 public:
  virtual Maze generateMaze(size_t rows, size_t cols) = 0;
};

}  // namespace s21

#endif  // __MAZE_SOURCE_MODEL_MAZE_BASEMAZEGENERATOR_H__