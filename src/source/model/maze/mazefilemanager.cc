#include "mazefilemanager.h"

#include <cstddef>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>

namespace s21 {

std::vector<std::vector<Cell>> MazeFileManager::loadMaze(
    const std::string& filename) {
  std::ifstream file(filename);

  if (!file.is_open()) {
    throw std::invalid_argument("Unable to open file: " + filename);
  }

  std::string line;
  std::getline(file, line);
  std::istringstream iss(line);
  size_t rows, cols;

  if (!(iss >> rows >> cols) || iss.rdbuf()->in_avail() != 0 || rows == 0 ||
      cols == 0) {
    throw std::invalid_argument(
        "Invalid format in the first line. Expected two integers.");
  }

  std::vector<std::vector<Cell>> maze(rows,
                                      std::vector<Cell>(cols, {0, 0, 0, 0}));

  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j) {
      if (!(file >> maze[i][j].right_wall)) {
        throw std::invalid_argument("Error reading matrix element at (" +
                                    std::to_string(i) + ", " +
                                    std::to_string(j) + ")");
      }
    }
  }

  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j) {
      if (!(file >> maze[i][j].down_wall)) {
        throw std::invalid_argument("Error reading matrix element at (" +
                                    std::to_string(i) + ", " +
                                    std::to_string(j) + ")");
      }
    }
  }

  file.close();

  return maze;
}

void MazeFileManager::saveMaze(const Maze& maze, const std::string& filename) {
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