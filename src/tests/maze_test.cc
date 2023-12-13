#include <gtest/gtest.h>

#include <cstddef>
#include <vector>

#include "../model/filereader.h"

TEST(MazeReader, CorrectFile) {
  s21::FileReader reader;
  size_t M = 3;
  size_t N = 3;

  std::vector<std::vector<int>> right_walls(M, std::vector<int>(N, 1));
  std::vector<std::vector<int>> down_walls(M, std::vector<int>(N, 0));

  s21::Maze test_maze(right_walls, down_walls);
  s21::Maze loaded_maze = reader.loadMaze("../map_examples/maze_3x3.txt");

  ASSERT_EQ(test_maze.getM(), loaded_maze.getM());
  ASSERT_EQ(test_maze.getM(), loaded_maze.getM());
  ASSERT_EQ(test_maze.getGrid(), loaded_maze.getGrid());
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
