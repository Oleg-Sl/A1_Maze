#include <fstream>

#include "filesaver.h"

namespace s21 {

void FileSaver::saveMaze(const Maze& maze, const std::string& filename) const {
  std::vector<std::vector<int>> right_walls =
      maze.getWallMatrix(Maze::WallPosition::kRight);
  std::vector<std::vector<int>> down_walls =
      maze.getWallMatrix(Maze::WallPosition::kDown);

  std::ofstream fs(filename);

  size_t rows = maze.getRows();
  size_t cols = maze.getCols();

  fs << rows << " " << cols << std::endl;

  for (size_t row = 0; row < rows; row++) {
    for (size_t col = 0; col < cols; col++) {
      fs << right_walls[row][col] << " ";
    }
    fs << std::endl;
  }

  fs << std::endl;

  for (size_t row = 0; row < rows; row++) {
    for (size_t col = 0; col < cols; col++) {
      fs << down_walls[row][col] << " ";
    }
    fs << std::endl;
  }
}
}  // namespace s21