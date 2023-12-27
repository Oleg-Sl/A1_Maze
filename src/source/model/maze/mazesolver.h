#ifndef __MAZE_SOURCE_MODEL_MAZE_MAZESOLVER_H__
#define __MAZE_SOURCE_MODEL_MAZE_MAZESOLVER_H__

#include <vector>

#include "common/point2d.h"
#include "maze.h"

namespace s21 {
class MazeSolver {
 public:
  std::vector<Point2D> findPath(const Maze& maze, Point2D start,
                                Point2D end) const;

 private:
  bool validateParams(const Maze& maze, Point2D start, Point2D end) const;
  std::vector<Point2D> getMoves(const Cell& cell, const Point2D& coords) const;
  std::vector<std::vector<int>> generateWave(const Maze& maze, Point2D start,
                                             Point2D end) const;
  std::vector<Point2D> reconstructPath(
      const Maze& maze, const std::vector<std::vector<int>>& grid_paths,
      Point2D start) const;
};
}  // namespace s21

#endif  // __MAZE_SOURCE_MODEL_MAZE_MAZESOLVER_H__