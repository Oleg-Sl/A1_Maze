#ifndef __MAZE_MODEL_FILEREADER_H_
#define __MAZE_MODEL_FILEREADER_H_

#include <cstddef>
#include <fstream>
#include <vector>

#include "maze.h"

namespace s21 {

class FileReader {
 public:
  Maze loadMaze(const std::string filename) {
    std::ifstream filestream(filename);
    size_t M, N;

    if (!filestream.is_open()) {
      std::cout << "Not openned";
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
};

}  // namespace s21

#endif  // __MAZE_MODEL_FILEREADER_H_