#include <iostream>

#include "mazesolver.h"

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

std::vector<std::vector<int>> MazeSolver::generateWave(const Maze& maze,
                                                       Point2D start,
                                                       Point2D end) const {
  size_t rows = maze.getRows();
  size_t cols = maze.getCols();

  std::vector<std::vector<int>> grid_paths(rows, std::vector<int>(cols, -1));

  grid_paths[start.y][start.x] = 0;

  int move_counter = 0;

  bool stop = false;
  while (!stop && grid_paths[end.y][end.x] == -1) {
    stop = true;

    for (size_t row = 0; row < rows; ++row) {
      for (size_t col = 0; col < cols; ++col) {
        if (grid_paths[row][col] == move_counter) {
          for (Point2D move :
               getMoves(maze(row, col),
                        {static_cast<int>(col), static_cast<int>(row)})) {
            int x = move.x;
            int y = move.y;

            if (y >= 0 && y < static_cast<int>(rows) && x >= 0 &&
                x < static_cast<int>(cols) && grid_paths[y][x] == -1) {
              stop = false;
              grid_paths[y][x] = move_counter + 1;
            }
          }
        }
      }
    }
    move_counter++;
  }

  return grid_paths;
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

    for (Point2D move : getMoves(maze(y, x), {x, y})) {
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
