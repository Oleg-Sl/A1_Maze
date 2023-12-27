#include "mazesolver.h"

#include <iostream>
#include <queue>

namespace s21 {

std::vector<Point2D> MazeSolver::getMoves(const Cell& cell,
                                          const Point2D& coords) const {
  std::vector<Point2D> moves;
  int x = coords.x;
  int y = coords.y;

  if (!cell.down_wall) {
    moves.push_back({x, y + 1});
  }
  if (!cell.up_wall) {
    moves.push_back({x, y - 1});
  }
  if (!cell.left_wall) {
    moves.push_back({x - 1, y});
  }
  if (!cell.right_wall) {
    moves.push_back({x + 1, y});
  }

  return moves;
}

std::vector<std::vector<int>> MazeSolver::generateWave(
    const Maze& maze, Point2D start_point, Point2D end_point) const {
  size_t rows = maze.getRows();
  size_t cols = maze.getCols();
  int kNotVisited = -1;

  std::vector<std::vector<int>> wave_grid(rows,
                                          std::vector<int>(cols, kNotVisited));
  std::queue<Point2D> wave_generation_points;

  wave_grid[start_point.y][start_point.x] = 0;
  wave_generation_points.push(start_point);

  int wave_distance = 0;

  while (!wave_generation_points.empty() &&
         wave_grid[end_point.y][end_point.x] == kNotVisited) {
    size_t curr_size = wave_generation_points.size();
    for (size_t i = 0; i < curr_size; i++) {
      auto curr_point = wave_generation_points.front();
      for (const Point2D& move :
           getMoves(maze(curr_point.y, curr_point.x), curr_point)) {
        int x = move.x;
        int y = move.y;

        if (y >= 0 && y < static_cast<int>(rows) && x >= 0 &&
            x < static_cast<int>(cols) && wave_grid[y][x] == kNotVisited) {
          wave_grid[y][x] = wave_distance + 1;
          wave_generation_points.push({x, y});
        }
      }

      wave_generation_points.pop();
    }
    wave_distance++;
  }

  return wave_grid;
}

std::vector<Point2D> MazeSolver::reconstructPath(
    const Maze& maze, const std::vector<std::vector<int>>& grid_paths,
    Point2D start) const {
  std::vector<Point2D> path;

  int x = start.x;
  int y = start.y;

  int move_counter = grid_paths[start.y][start.x];
  while (move_counter >= 0) {
    path.push_back({x, y});
    move_counter--;

    for (Point2D& move : getMoves(maze(y, x), {x, y})) {
      if (grid_paths[move.y][move.x] == move_counter) {
        x = move.x;
        y = move.y;
        break;
      }
    }
  }

  return path;
}

bool MazeSolver::validateParams(const Maze& maze, Point2D start,
                                Point2D end) const {
  int cols = static_cast<int>(maze.getCols());
  int rows = static_cast<int>(maze.getRows());

  return cols > 0 && rows > 0 && start.x >= 0 && start.y >= 0 && end.x >= 0 &&
         end.y >= 0 && start.x < cols && end.x < cols && start.y < rows &&
         end.y < rows;
}

std::vector<Point2D> MazeSolver::findPath(const Maze& maze, Point2D start,
                                          Point2D end) const {
  if (!validateParams(maze, start, end)) {
    return std::vector<Point2D>();
  }

  std::vector<std::vector<int>> grid_paths = generateWave(maze, start, end);
  return reconstructPath(maze, grid_paths, end);
}

}  // namespace s21