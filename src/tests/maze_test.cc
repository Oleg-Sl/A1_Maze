#include <gtest/gtest.h>

#include <cstddef>
#include <stdexcept>
#include <vector>

#include "filereader.h"

TEST(MazeReader, CorrectFile) {
  s21::FileReader reader;
  size_t M = 3;
  size_t N = 3;

  std::vector<std::vector<int>> right_walls(M, std::vector<int>(N, 1));
  std::vector<std::vector<int>> down_walls(M, std::vector<int>(N, 0));

  s21::Maze test_maze(right_walls, down_walls);
  s21::Maze loaded_maze = reader.loadMaze("source/map_examples/maze_3x3.txt");

  ASSERT_EQ(test_maze.getM(), loaded_maze.getM());
  ASSERT_EQ(test_maze.getM(), loaded_maze.getM());
  ASSERT_EQ(test_maze.getGrid(), loaded_maze.getGrid());
}

TEST(MazeReader, ThrowNotExistFile) {
  s21::FileReader reader;

  ASSERT_THROW(reader.loadMaze("not_exist"),
               std::invalid_argument);
}

// TEST(MazeReader, FileWithoutSizeLine) {
//   s21::FileReader reader;
//   size_t M = 3;
//   size_t N = 3;

//   std::vector<std::vector<int>> right_walls(M, std::vector<int>(N, 1));
//   std::vector<std::vector<int>> down_walls(M, std::vector<int>(N, 0));

//   s21::Maze test_maze(right_walls, down_walls);
//   s21::Maze loaded_maze = reader.loadMaze("map_examples/maze_without_size.txt");

//   ASSERT_EQ(test_maze.getM(), loaded_maze.getM());
//   ASSERT_EQ(test_maze.getM(), loaded_maze.getM());
//   ASSERT_EQ(test_maze.getGrid(), loaded_maze.getGrid());
// }



