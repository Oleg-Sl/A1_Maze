#include <algorithm>
#include <numeric>
#include <vector>

#include "cell.h"
#include "mazegenerator.h"

namespace s21 {

// TODO: Разбить на функции, упростить

void MazeGenerator::unionSets(std::vector<size_t>& sets, size_t set1,
                              size_t set2) {
  for (size_t i = 0; i < sets.size(); i++) {
    if (sets[i] == set2) sets[i] = set1;
  }
}

Maze MazeGenerator::generateMaze(Maze::size_type rows, Maze::size_type cols) {
  std::vector<std::vector<Cell>> maze(rows, std::vector<Cell>(cols, {0, 0}));

  std::vector<std::vector<size_t>> sets(rows, std::vector<size_t>(cols, 0));

  std::iota(sets[0].begin(), sets[0].end(), 0);

  for (size_t row = 0; row < rows; row++) {
    for (size_t col = 0; col < cols; col++) {
      bool sets_equal = sets[row][col] == sets[row][col + 1];

      if (dist_(gen_) || sets_equal) {
        maze[row][col].right_wall = 1;

        if (col != cols - 1) maze[row][col + 1].left_wall = 1;
      } else {
        unionSets(sets[row], sets[row][col], sets[row][col + 1]);
      }

      int counter = 0;
      for (size_t k = 0; k < cols; k++) {
        if (sets[row][k] == sets[row][col] && maze[row][k].down_wall == 0) {
          counter++;
        }
      }

      if (dist_(gen_) == 1 && counter > 1) {
        maze[row][col].down_wall = 1;
        if (row != rows - 1) maze[row + 1][col].up_wall = 1;
      }

      if (col == 0) maze[row][col].left_wall = 1;
      if (col == rows - 1) maze[row][col].right_wall = 1;
      if (row == 0) maze[row][col].up_wall = 1;
      if (row == rows - 1) maze[row][col].down_wall = 1;
    }

    for (size_t col = 0; col < cols; col++) {
      if (row < rows - 1) {
        if (maze[row][col].down_wall == 1) {
          sets[row + 1][col] = (row + 1) * rows + col;
        } else {
          sets[row + 1][col] = sets[row][col];
        }
      }
    }

    for (size_t col = 0; col < cols - 1; col++) {
      if (row == rows - 1) {
        if (sets[row][col] != sets[row][col + 1]) {
          maze[row][col].right_wall = 0;
          if (col != cols - 1) maze[row][col + 1].left_wall = 0;
        }
        unionSets(sets[row], sets[row][col], sets[row][col + 1]);
      }
    }
  }

  return Maze(maze);
}

}  // namespace s21
