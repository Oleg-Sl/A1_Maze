#include "adapter.h"

namespace s21 {

std::vector<std::vector<MazeCell>> Adapter::generateMaze(const int M,
                                                         const int N) const {
  Maze maze = MazeGenerator().generateMaze(M, N);

  auto grid = maze.getGrid();
  std::vector<std::vector<MazeCell>> view_grid(
      maze.getM(), std::vector<MazeCell>(maze.getN(), {0, 0, 0, 0}));

  for (size_t i = 0; i < maze.getM(); i++) {
    for (size_t j = 0; j < maze.getN(); j++) {
      bool down = grid[i][j].down_wall;
      bool up = grid[i][j].up_wall;
      bool left = grid[i][j].left_wall;
      bool right = grid[i][j].right_wall;
      view_grid[i][j] = {up, down, right, left};
    }
  }

  return view_grid;
}

std::vector<std::pair<int, int>> Adapter::solutionMaze(
    std::vector<std::vector<MazeCell>> maze, int x1, int y1, int x2, int y2) {
  size_t M = maze.size();
  size_t N = maze[0].size();

  std::vector<std::vector<Cell>> grid(M, std::vector<Cell>(N, {0, 0, 0, 0}));

  for (size_t i = 0; i < M; i++) {
    for (size_t j = 0; j < N; j++) {
      grid[i][j].down_wall = maze[i][j].down_wall;
      grid[i][j].up_wall = maze[i][j].up_wall;
      grid[i][j].left_wall = maze[i][j].left_wall;
      grid[i][j].right_wall = maze[i][j].right_wall;
    }
  }

  return MazeSolution().findPath(Maze(grid), x1, y1, x2, y2);
}

}  // namespace s21