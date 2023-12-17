#ifndef __MAZE_SOURCE_ADAPTER_ADAPTER_H__
#define __MAZE_SOURCE_ADAPTER_ADAPTER_H__

#include "maze.h"
#include "mazecell.h"
#include "mazegenerator.h"
#include "mazesolution.h"

namespace s21 {

class Adapter {
 public:
  std::vector<std::vector<MazeCell>> generateMaze(const int M,
                                                  const int N) const;
  std::vector<std::pair<int, int>> solutionMaze(
      std::vector<std::vector<MazeCell>> maze, int x1, int y1, int x2, int y2);
};
}  // namespace s21

#endif  // __MAZE_SOURCE_ADAPTER_ADAPTER_H__