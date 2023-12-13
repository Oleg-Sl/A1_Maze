#ifndef __MAZE_MODEL_FILEREADER_H_
#define __MAZE_MODEL_FILEREADER_H_

#include <cstddef>
#include <fstream>
#include <vector>

#include "maze.h"

namespace s21 {

class FileReader {
 public:
  Maze loadMaze(const std::string filename);
};

}  // namespace s21

#endif  // __MAZE_MODEL_FILEREADER_H_