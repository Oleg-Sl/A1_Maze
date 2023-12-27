#include "model/maze/maze.h"

#include <gtest/gtest.h>

#include <cstddef>
#include <stdexcept>
#include <vector>

namespace s21 {

TEST(MazeFunctions, BuildWall) {
  Maze maze(3, 3);

  maze.buildWall(0, 0, Maze::WallPosition::kRight);

  ASSERT_EQ(maze(0, 0).right_wall, 1);
  ASSERT_EQ(maze(0, 1).left_wall, 1);
}

TEST(MazeFunctions, RemoveWall) {
  Maze maze(3, 3);

  maze.buildWall(0, 0, Maze::WallPosition::kRight);
  maze.removeWall(0, 0, Maze::WallPosition::kRight);

  ASSERT_EQ(maze(0, 0).right_wall, 0);
  ASSERT_EQ(maze(0, 1).left_wall, 0);
}

TEST(MazeFunctions, DefaultConstructor) {
  Maze maze;

  ASSERT_EQ(maze.getRows(), 0);
  ASSERT_EQ(maze.getCols(), 0);
}

TEST(MazeFunctions, ConstructorWithSize) {
  Maze maze(4, 4);

  ASSERT_EQ(maze.getRows(), 4);
  ASSERT_EQ(maze.getCols(), 4);
}

TEST(MazeFunctions, ConstructorWithGrid) {
  std::vector<std::vector<Cell>> initial_grid = {{Cell()}, {Cell()}};

  Maze maze(initial_grid);

  ASSERT_EQ(maze.getRows(), initial_grid.size());
  ASSERT_EQ(maze.getCols(), initial_grid[0].size());
}

TEST(MazeFunctions, OperatorParentheses) {
  Maze maze(3, 3);
  Cell cell = maze(1, 1);

  ASSERT_EQ(cell.up_wall, 0);
  ASSERT_EQ(cell.down_wall, 0);
  ASSERT_EQ(cell.left_wall, 0);
  ASSERT_EQ(cell.right_wall, 0);
}

TEST(MazeFunctions, ThrowOperatorParenthesesGreaterRowsSize) {
  Maze maze(5, 3);
  ASSERT_THROW(maze(maze.getRows() + 1, 1), std::invalid_argument);
}

TEST(MazeFunctions, ThrowOperatorParenthesesGreaterColsSize) {
  Maze maze(3, 5);
  ASSERT_THROW(maze(1, maze.getCols() + 1), std::invalid_argument);
}

TEST(MazeFunctions, ThrowOperatorParenthesesRowLessZero) {
  Maze maze(3, 5);
  ASSERT_THROW(maze(-1, 1), std::invalid_argument);
}

TEST(MazeFunctions, ThrowOperatorParenthesesColLessZero) {
  Maze maze(3, 5);
  ASSERT_THROW(maze(1, -5), std::invalid_argument);
}

}  // namespace s21
