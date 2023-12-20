#include <cstddef>
#include <fstream>
#include <stdexcept>
#include <vector>

#include "filereader.h"
#include "maze.h"

namespace s21 {

std::vector<std::vector<Cell>> FileReader::loadMaze(
    const std::string& filename) const {
  std::ifstream filestream(filename);
  size_t rows, cols;

  if (!filestream.is_open()) {
    throw std::invalid_argument("File opening error");
  }

  filestream >> rows >> cols;

  std::vector<std::vector<Cell>> maze(rows,
                                      std::vector<Cell>(cols, {0, 0, 0, 0}));

  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < cols; j++) {
      if (i == 0) maze[i][j].up_wall = 1;
      if (j == 0) maze[i][j].left_wall = 1;

      int curr_value;
      filestream >> curr_value;
      maze[i][j].right_wall = curr_value;
      if (j < cols - 1) maze[i][j + 1].left_wall = curr_value;
    }
  }

  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < cols; j++) {
      int curr_value;
      filestream >> curr_value;
      maze[i][j].down_wall = curr_value;
      if (i < cols - 1) maze[i + 1][j].up_wall = curr_value;
    }
  }

  return maze;
}

}  // namespace s21