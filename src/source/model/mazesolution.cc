#include <iostream>

#include "mazesolution.h"

namespace s21 {

std::vector<Point2D> MazeSolution::getMoves(const Cell& cell,
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

std::vector<std::vector<int>> MazeSolution::generateWave(const Maze& maze,
                                                         Point2D start,
                                                         Point2D end) const {
  size_t rows = maze.getM();
  size_t cols = maze.getN();

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

std::vector<Point2D> MazeSolution::reconstructPath(
    const Maze& maze, const std::vector<std::vector<int>>& grid_paths,
    Point2D start, Point2D end) const {
  std::vector<Point2D> path;

  int x = end.x;
  int y = end.y;

  int move_counter = grid_paths[end.y][end.x];
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

std::vector<Point2D> MazeSolution::findPath(const Maze& maze, Point2D start,
                                            Point2D end) const {
  std::vector<std::vector<int>> grid_paths = generateWave(maze, start, end);
  return reconstructPath(maze, grid_paths, start, end);
}

}  // namespace s21
