#include <cstddef>
#include <fstream>
#include <stdexcept>
#include <vector>

#include "filereader.h"

namespace s21 {

Maze FileReader::loadMaze(const std::string& filename) {
  std::ifstream filestream(filename);
  Maze::size_type M, N;

  if (!filestream.is_open()) {
    throw std::invalid_argument("Incorrect filename");
  }

  filestream >> M >> N;

  std::vector<std::vector<int>> right_walls(M, std::vector<int>());
  std::vector<std::vector<int>> down_walls(M, std::vector<int>());

  for (size_t i = 0; i < M; i++) {
    for (size_t j = 0; j < N; j++) {
      int curr_value;
      filestream >> curr_value;
      right_walls[i].push_back(curr_value);
    }
  }

  for (size_t i = 0; i < M; i++) {
    for (size_t j = 0; j < N; j++) {
      int curr_value;
      filestream >> curr_value;
      down_walls[i].push_back(curr_value);
    }
  }

  return Maze(right_walls, down_walls);
}

}  // namespace s21