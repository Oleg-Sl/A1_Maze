#ifndef __MAZE_SOURCE_MODEL_MAZESOLUTION_H__
#define __MAZE_SOURCE_MODEL_MAZESOLUTION_H__

#include <vector>

#include "maze.h"
#include "point2d.h"

namespace s21 {
class MazeSolution {
 public:
  std::vector<Point2D> findPath(const Maze& maze, Point2D start,
                                Point2D end) const;

 private:
  std::vector<Point2D> getMoves(const Cell& cell, const Point2D& coords) const;
  std::vector<std::vector<int>> generateWave(const Maze& maze, Point2D start,
                                             Point2D end) const;
  std::vector<Point2D> reconstructPath(
      const Maze& maze, const std::vector<std::vector<int>>& grid_paths,
      Point2D start, Point2D end) const;
};
}  // namespace s21

#endif  // __MAZE_SOURCE_MODEL_MAZESOLUTION_H__
