#ifndef __MAZE_SOURCE_ADAPTER_ADAPTER_H__
#define __MAZE_SOURCE_ADAPTER_ADAPTER_H__

#include "cell.h"
#include "maze.h"
#include "mazegenerator.h"
#include "mazesolution.h"

namespace s21 {

class Adapter {
 public:
  std::vector<std::vector<Cell>> generateMaze(const int M, const int N) const;
  std::vector<Point2D> solutionMaze(std::vector<std::vector<Cell>> maze,
                                    Point2D start, Point2D end) const;
};
}  // namespace s21

#endif  // __MAZE_SOURCE_ADAPTER_ADAPTER_H__