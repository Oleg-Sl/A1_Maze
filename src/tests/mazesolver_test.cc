#include "model/maze/mazesolver.h"

#include "gtest/gtest.h"

namespace s21 {

TEST(MazeSolverTest, NotPath) {
  Maze maze(3, 3);

  maze.buildWall(0, 0, Maze::WallPosition::kRight);
  maze.buildWall(1, 0, Maze::WallPosition::kRight);
  maze.buildWall(2, 0, Maze::WallPosition::kRight);

  // s|
  //  |e
  //  |

  std::vector<Point2D> path = MazeSolver().findPath(maze, {0, 0}, {1, 1});

  ASSERT_EQ(path.size(), 0);
}

TEST(MazeSolverTest, ValidPath) {
  Maze maze(3, 3);

  maze.buildWall(0, 0, Maze::WallPosition::kRight);
  maze.buildWall(1, 0, Maze::WallPosition::kRight);

  maze.buildWall(2, 1, Maze::WallPosition::kDown);
  maze.buildWall(2, 2, Maze::WallPosition::kDown);

  Point2D p_1{2, 2};
  Point2D p_2{1, 2};
  Point2D p_3{0, 2};
  Point2D p_4{0, 1};
  Point2D p_5{0, 0};

  // s|
  //  |___
  //     e

  std::vector<Point2D> path = MazeSolver().findPath(maze, {0, 0}, {2, 2});

  ASSERT_EQ(path.size(), 5);
  ASSERT_EQ(path[0], p_1);
  ASSERT_EQ(path[1], p_2);
  ASSERT_EQ(path[2], p_3);
  ASSERT_EQ(path[3], p_4);
  ASSERT_EQ(path[4], p_5);
}

TEST(MazeSolverTest, IncorrectPoint) {
  Maze maze(3, 3);

  std::vector<Point2D> path = MazeSolver().findPath(maze, {0, 0}, {10, 10});

  ASSERT_EQ(path.size(), 0);
}

}  // namespace s21
