#include "mazegenerator.h"

namespace s21 {

Maze MazeGenerator::generateMaze(size_t M, size_t N) {
  std::vector<std::vector<Cell>> grid(M, std::vector<Cell>(N, {0}));

  for (size_t row = 0; row < M; row++) {
    genPreprocessing(grid, row);
    genRightWalls(grid[row]);
    genDownWalls(grid[row]);
  }
  genPostprocessing(grid);

  return Maze(grid);
}

void MazeGenerator::genPreprocessing(std::vector<std::vector<Cell>>& grid,
                                     size_t num_row) {
  size_t N = grid[0].size();

  if (num_row == 0) {
    for (size_t i = 0; i < N; i++) {
      grid[num_row][i].set_id = i;
    }
  } else {
    grid[num_row] = grid[num_row - 1];

    for (size_t col = 0; col < N; col++) {
      int new_set = num_row * N + col;

      if (grid[num_row][col].down_wall == 1) {
        grid[num_row][col].set_id = new_set;
      }

      grid[num_row][col].right_wall = 0;
      grid[num_row][col].down_wall = 0;
    }
  }
}

void MazeGenerator::genRightWalls(std::vector<Cell>& curr_row) {
  size_t N = curr_row.size();

  for (size_t element = 0; element < N - 1; element++) {
    if (dist_(gen_)) {
      curr_row[element].right_wall = 1;
    } else {
      if (curr_row[element].set_id == curr_row[element + 1].set_id) {
        curr_row[element].right_wall = 1;
      } else {
        for (size_t i = 0; i < N; i++) {
          if (curr_row[i].set_id == curr_row[element + 1].set_id) {
            curr_row[i].set_id = curr_row[element].set_id;
          }
        }
      }
    }
  }
}

void MazeGenerator::genDownWalls(std::vector<Cell>& curr_row) {
  size_t N = curr_row.size();

  for (size_t element = N - 1; static_cast<int>(element) >= 0; element--) {
    if (!dist_(gen_)) {
      curr_row[element].down_wall = 0;
    } else {
      int count_down_walls = 0;
      for (size_t i = 0; i < N; i++) {
        if (curr_row[element].set_id == curr_row[i].set_id &&
            !curr_row[i].down_wall) {
          count_down_walls++;
        }
      }

      if (count_down_walls > 1) {
        curr_row[element].down_wall = 1;
      }
    }
  }
}

void MazeGenerator::genPostprocessing(std::vector<std::vector<Cell>>& grid) {
  size_t N = grid.size();
  size_t M = grid[0].size();

  for (size_t element = 0; element < N - 1; element++) {
    grid[N - 1][element].down_wall = 1;

    if (grid[N - 1][element].set_id != grid[N - 1][element + 1].set_id) {
      grid[N - 1][element].right_wall = 0;
    }

    for (size_t i = 0; i < N; i++) {
      if (grid[N - 1][i].set_id == grid[N - 1][element + 1].set_id) {
        grid[N - 1][i].set_id = grid[N - 1][element].set_id;
      }
    }
  }

  for (size_t i = 0; i < N; i++) {
    grid[0][i].up_wall = 1;
    grid[N - 1][i].down_wall = 1;
  }

  for (size_t i = 0; i < M; i++) {
    grid[i][0].left_wall = 1;
    grid[i][N - 1].right_wall = 1;
  }
}

}  // namespace s21