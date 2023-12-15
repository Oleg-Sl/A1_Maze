#ifndef __MAZE_SOURCE_CONTROLLER_MAZECONTROLLER_H__
#define __MAZE_SOURCE_CONTROLLER_MAZECONTROLLER_H__

#include "maze.h"
#include "mazegenerator.h"

namespace s21 {

class MazeController {
    public:
  Maze generateMaze(const int M, const int N) const;
};
}  // namespace s21

#endif  // __MAZE_SOURCE_CONTROLLER_MAZECONTROLLER_H__