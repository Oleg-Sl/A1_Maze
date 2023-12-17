#ifndef __MAZE_SOURCE_MODEL_MAZESOLUTION_H__
#define __MAZE_SOURCE_MODEL_MAZESOLUTION_H__

#include <cstddef>
#include <vector>

#include "maze.h"

namespace s21 {
class MazeSolution {
 public:
  std::vector<std::pair<int, int>> findPath(Maze maze, int x1, int y1, int x2,
                                            int y2);
};
}  // namespace s21

#endif  // __MAZE_SOURCE_MODEL_MAZESOLUTION_H__