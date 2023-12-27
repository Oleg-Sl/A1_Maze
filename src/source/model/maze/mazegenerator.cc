
#include "mazegenerator.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

#include "common/cell.h"

namespace s21 {

void MazeGenerator::unionSets(std::vector<size_t>& sets, size_t set1,
                              size_t set2) {
  for (size_t i = 0; i < sets.size(); i++) {
    if (sets[i] == set2) sets[i] = set1;
  }
}

void MazeGenerator::buildWalls(Maze& maze,
                               std::vector<std::vector<size_t>>& sets,
                               size_t row, size_t col) {
  size_t cols = maze.getCols();

  if (col < cols - 1) {
    bool sets_equal = sets[row][col] == sets[row][col + 1];

    if (dist_(gen_) == 1 || sets_equal) {
      maze.buildWall(row, col, Maze::WallPosition::kRight);
    } else {
      unionSets(sets[row], sets[row][col], sets[row][col + 1]);
    }
  }

  int cells_without_down = 0;
  for (size_t k = 0; k < cols; k++) {
    if (sets[row][k] == sets[row][col] && maze(row, k).down_wall == 0) {
      cells_without_down++;
    }
  }

  if (dist_(gen_) == 1 && cells_without_down > 1) {
    maze.buildWall(row, col, Maze::WallPosition::kDown);
  }
}

void MazeGenerator::initializeFirstRow(const Maze& maze,
                                       std::vector<std::vector<size_t>>& sets) {
  for (size_t col = 0; col < maze.getCols(); col++) {
    sets[0][col] = col;
  }
}

void MazeGenerator::genRows(Maze& maze,
                            std::vector<std::vector<size_t>>& sets) {
  size_t rows = maze.getRows();
  size_t cols = maze.getCols();

  for (size_t row = 0; row < rows; row++) {
    for (size_t col = 0; col < cols; col++) {
      buildWalls(maze, sets, row, col);
    }

    if (row < rows - 1) {
      for (size_t col = 0; col < cols; col++) {
        if (maze(row, col).down_wall) {
          sets[row + 1][col] = (row + 1) * cols + col;
        } else {
          sets[row + 1][col] = sets[row][col];
        }
      }
    }
  }
}

void MazeGenerator::genLastRow(Maze& maze,
                               std::vector<std::vector<size_t>>& sets) {
  size_t last_row = maze.getRows() - 1;

  for (size_t col = 0; col < maze.getCols() - 1; col++) {
    maze.buildWall(last_row, col, Maze::WallPosition::kDown);
    if (sets[last_row][col] != sets[last_row][col + 1]) {
      maze.removeWall(last_row, col, Maze::WallPosition::kRight);
    }

    unionSets(sets[last_row], sets[last_row][col], sets[last_row][col + 1]);
  }
}

Maze MazeGenerator::generateMaze(size_t rows, size_t cols) {
  if (rows <= 1 || cols <= 1) {
    return Maze();
  }

  Maze maze(rows, cols);
  std::vector<std::vector<size_t>> sets(rows, std::vector<size_t>(cols, 0));

  initializeFirstRow(maze, sets);
  genRows(maze, sets);
  genLastRow(maze, sets);

  return maze;
}

}  // namespace s21
