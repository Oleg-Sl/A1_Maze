#ifndef __MAZE_SOURCE_MODEL_BASEMAZEGENERATOR_H__
#define __MAZE_SOURCE_MODEL_BASEMAZEGENERATOR_H__

#include "maze.h"

namespace s21 {

class BaseMazeGenerator {
 public:
  virtual Maze generateMaze(Maze::size_type rows, Maze::size_type cols) = 0;
};

}  // namespace s21

#endif  // __MAZE_SOURCE_MODEL_BASEMAZEGENERATOR_H__