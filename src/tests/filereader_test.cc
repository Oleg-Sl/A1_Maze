#include <gtest/gtest.h>

#include <cstddef>
#include <stdexcept>
#include <vector>

#include "model/maze/maze.h"
#include "model/maze/mazefilemanager.h"

namespace s21 {

const std::string kAssetsDir = std::string(ASSETS_DIR) + "/";

TEST(MazeReader, CorrectFile3x3) {
  size_t M = 3;
  size_t N = 3;

  std::vector<std::vector<Cell>> grid(M, std::vector<Cell>(N, {1, 0, 0, 0}));

  Maze test_maze(grid);
  Maze loaded_maze(MazeFileManager::loadMaze(kAssetsDir + "maze_3x3.txt"));

  ASSERT_EQ(test_maze.getRows(), loaded_maze.getRows());
  ASSERT_EQ(test_maze.getCols(), loaded_maze.getCols());
  ASSERT_EQ(test_maze.getGrid(), loaded_maze.getGrid());
}

TEST(MazeReader, CorrectFile50x50) {
  size_t M = 50;
  size_t N = 50;

  Maze test_maze(M, N);
  Maze loaded_maze(MazeFileManager::loadMaze(kAssetsDir + "maze_50x50.txt"));

  ASSERT_EQ(test_maze.getRows(), loaded_maze.getRows());
  ASSERT_EQ(test_maze.getCols(), loaded_maze.getCols());
}

TEST(MazeReader, CorrectFile0x0) {
  ASSERT_THROW(MazeFileManager::loadMaze(kAssetsDir + "maze_0x0.txt"),
               std::invalid_argument);
}

TEST(MazeReader, ThrowNotExistFile) {
  ASSERT_THROW(MazeFileManager::loadMaze("not_exist_file"),
               std::invalid_argument);
}

TEST(MazeReader, ThrowFileWithoutSizeLine) {
  ASSERT_THROW(MazeFileManager::loadMaze(kAssetsDir + "maze_without_size.txt"),
               std::invalid_argument);
}

}  // namespace s21
