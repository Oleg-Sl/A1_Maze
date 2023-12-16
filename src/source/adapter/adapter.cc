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
};

}  // namespace s21