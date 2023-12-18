#ifndef __MAZE_SOURCE_MODEL_FILESAVER_H__
#define __MAZE_SOURCE_MODEL_FILESAVER_H__

#include "maze.h"

namespace s21 {

class FileSaver {
 public:
  void saveMaze(const Maze& maze, const std::string& filename) const;
};

}  // namespace s21

#endif  // __MAZE_SOURCE_MODEL_FILESAVER_H__