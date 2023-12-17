#include "adapter.h"

namespace s21 {

std::vector<std::vector<Cell>> Adapter::generateMaze(const int M,
                                                     const int N) const {
  return MazeGenerator().generateMaze(M, N).getGrid();
}

std::vector<Point2D> Adapter::solutionMaze(std::vector<std::vector<Cell>> maze,
                                           Point2D start, Point2D end) const {
  return MazeSolution().findPath(maze, start, end);
}

}  // namespace s21