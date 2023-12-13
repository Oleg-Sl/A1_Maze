#ifndef __MAZE_MODEL_INCLUDE_BASEMAZEGENERATOR_H__
#define __MAZE_MODEL_INCLUDE_BASEMAZEGENERATOR_H__

#include "maze.h"

namespace s21 {

class BaseMazeGenerator {
 public:
  virtual Maze generateMaze(size_t M, size_t N) const = 0;
};

}  // namespace s21

#endif  // __MAZE_MODEL_INCLUDE_BASEMAZEGENERATOR_H__