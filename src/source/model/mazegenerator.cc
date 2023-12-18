#include <algorithm>
#include <numeric>
#include <vector>

#include "cell.h"
#include "mazegenerator.h"

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
  size_t rows = maze.getRows();
  size_t cols = maze.getCols();

  if (row == 0) maze(row, col).up_wall = 1;
  if (row == rows - 1) maze(row, col).down_wall = 1;
  if (col == 0) maze(row, col).left_wall = 1;
  if (col == cols - 1) maze(row, col).right_wall = 1;

  if (col != cols - 1) {
    bool sets_equal = sets[row][col] == sets[row][col + 1];

    if (dist_(gen_) == 1 || sets_equal) {
      maze(row, col).right_wall = 1;
      if (col < cols - 1) maze(row, col + 1).left_wall = 1;
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
    maze(row, col).down_wall = 1;
    if (row < rows - 1) {
      maze(row + 1, col).up_wall = 1;
      sets[row + 1][col] = (row + 1) * cols + col;  // form next string
    }
  } else {
    if (row < rows - 1)
      sets[row + 1][col] = sets[row][col];  // form next string
  }
}

void MazeGenerator::initializeFirstRow(Maze& maze,
                                       std::vector<std::vector<size_t>>& sets) {
  for (size_t col = 0; col < maze.getCols(); col++) {
    sets[0][col] = col;
  }
}

void MazeGenerator::genRows(Maze& maze,
                            std::vector<std::vector<size_t>>& sets) {
  Maze::size_type rows = maze.getRows();
  Maze::size_type cols = maze.getCols();

  for (size_t row = 0; row < rows; row++) {
    for (size_t col = 0; col < cols; col++) {
      buildWalls(maze, sets, row, col);
    }
  }
}

void MazeGenerator::genLastRow(Maze& maze,
                               std::vector<std::vector<size_t>>& sets) {
  size_t last_row = maze.getRows() - 1;

  for (size_t col = 0; col < maze.getCols() - 1; col++) {
    maze(last_row, col).down_wall = 1;
    if (sets[last_row][col] != sets[last_row][col + 1]) {
      maze(last_row, col).right_wall = 0;
      if (col < maze.getCols() - 1) maze(last_row, col + 1).left_wall = 0;
    }

    unionSets(sets[last_row], sets[last_row][col], sets[last_row][col + 1]);
  }
}

Maze MazeGenerator::generateMaze(Maze::size_type rows, Maze::size_type cols) {
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
