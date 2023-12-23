#include <cstddef>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>

#include "filereader.h"
#include "maze.h"

namespace s21 {

std::vector<std::vector<Cell>> FileReader::loadMaze(
    const std::string& filename) const {
  std::ifstream file(filename);

  if (!file.is_open()) {
    throw std::invalid_argument("Unable to open file: " + filename);
  }

  std::string line;
  std::getline(file, line);
  std::istringstream iss(line);
  size_t rows, cols;

  if (!(iss >> rows >> cols) || iss.rdbuf()->in_avail() != 0) {
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

}  // namespace s21