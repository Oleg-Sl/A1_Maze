#ifndef __MAZE_SOURCE_ADAPTER_ADAPTER_H__
#define __MAZE_SOURCE_ADAPTER_ADAPTER_H__

#include <string>
#include <vector>

#include "cell.h"
#include "point2d.h"

namespace s21 {

class Adapter {
 public:
  std::vector<std::vector<Cell>> generateMaze(const int M, const int N) const;
  std::vector<Point2D> solutionMaze(std::vector<std::vector<Cell>> maze,
                                    Point2D start, Point2D end) const;
  std::vector<std::vector<Cell>> loadMazeFromFile(std::string filename) const;
  void saveMazeFile(const std::vector<std::vector<Cell>>& maze,
                    const std::string& filename) const;
};
}  // namespace s21

#endif  // __MAZE_SOURCE_ADAPTER_ADAPTER_H__