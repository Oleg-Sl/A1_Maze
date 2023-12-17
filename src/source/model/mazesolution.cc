#include "mazesolution.h"

namespace s21 {

std::vector<std::pair<int, int>> MazeSolution::findPath(Maze maze, int x1,
                                                        int y1, int x2,
                                                        int y2) {
  size_t M = maze.getM();
  size_t N = maze.getN();

  std::vector<std::vector<int>> grid_paths(M, std::vector<int>(N, -1));
  std::vector<std::vector<Cell>> grid_walls = maze.getGrid();
  std::vector<std::pair<int, int>> path;

  grid_paths[y1][x1] = 0;

  int move_counter = 0;

  bool stop = false;
  while (!stop && grid_paths[y2][x2] == -1) {
    stop = true;

    for (size_t row = 0; row < M; ++row) {
      for (size_t col = 0; col < N; ++col) {
        if (grid_paths[row][col] == move_counter) {
          for (int k = 0; k < 4; ++k) {
            bool right_wall = grid_walls[row][col].right_wall;
            bool left_wall = grid_walls[row][col].left_wall;
            bool up_wall = grid_walls[row][col].up_wall;
            bool down_wall = grid_walls[row][col].down_wall;

            int dx[4] = {!right_wall, 0, -(!left_wall), 0};
            int dy[4] = {0, !down_wall, 0, -(!up_wall)};

            int iy = row + dy[k], ix = col + dx[k];
            if (iy >= 0 && iy < static_cast<int>(M) && ix >= 0 &&
                ix < static_cast<int>(N) && grid_paths[iy][ix] == -1) {
              stop = false;
              grid_paths[iy][ix] = move_counter + 1;
            }
          }
        }
      }
    }
    move_counter++;
  }

  int x = x2;
  int y = y2;

  move_counter = grid_paths[x2][y2];
  while (move_counter > 0) {
    path.push_back({y, x});
    move_counter--;

    for (int k = 0; k < 4; ++k) {
      int dx[4] = {1, 0, -1, 0};
      int dy[4] = {0, 1, 0, -1};

      int iy = y + dy[k];
      int ix = x + dx[k];

      if (iy >= 0 && iy < static_cast<int>(M) && ix >= 0 &&
          ix < static_cast<int>(N)) {
        {
          if (grid_paths[iy][ix] == move_counter) {
            if ((k == 0 && grid_walls[y][x].right_wall) ||
                (k == 1 && grid_walls[y][x].down_wall) ||
                (k == 2 && grid_walls[y][x].left_wall) ||
                (k == 3 && grid_walls[y][x].up_wall)) {
              continue;
            }
            x = ix;
            y = iy;
            break;
          }
        }
      }
    }
  }

  path.push_back({y, x});

  return path;
}

}  // namespace s21