#include "model/maze/mazegenerator.h"

#include "gtest/gtest.h"

namespace s21 {

TEST(MazeGeneratorTest, GenerateMazeValidDimensions) {
  size_t rows = 5;
  size_t cols = 5;
  s21::MazeGenerator generator;
  s21::Maze maze = generator.generateMaze(rows, cols);

  EXPECT_EQ(maze.getRows(), rows);
  EXPECT_EQ(maze.getCols(), cols);
}

TEST(MazeGeneratorTest, GenerateMazeInvalidDimensions) {
  s21::MazeGenerator generator;
  s21::Maze maze = generator.generateMaze(1, 1);

  EXPECT_EQ(maze.getRows(), 0);
  EXPECT_EQ(maze.getCols(), 0);
}

TEST(MazeGeneratorTest, GenerateMazeZeroRows) {
  s21::MazeGenerator generator;
  s21::Maze maze = generator.generateMaze(0, 5);

  EXPECT_EQ(maze.getRows(), 0);
  EXPECT_EQ(maze.getCols(), 0);
}

TEST(MazeGeneratorTest, GenerateMazeZeroCols) {
  s21::MazeGenerator generator;
  s21::Maze maze = generator.generateMaze(5, 0);

  EXPECT_EQ(maze.getRows(), 0);
  EXPECT_EQ(maze.getCols(), 0);
}

}  // namespace s21
