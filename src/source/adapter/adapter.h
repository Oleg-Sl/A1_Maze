#ifndef __MAZE_SOURCE_ADAPTER_ADAPTER_H__
#define __MAZE_SOURCE_ADAPTER_ADAPTER_H__

#include "maze.h"
#include "mazegenerator.h"
#include "mazecell.h"

namespace s21 {

class Adapter {
 public:
  std::vector<std::vector<MazeCell>> generateMaze(const int M, const int N) const;
};
}  // namespace s21

#endif  // __MAZE_SOURCE_ADAPTER_ADAPTER_H__