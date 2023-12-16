#ifndef __MAZE_SOURCE_MODEL_FILEREADER_H__
#define __MAZE_SOURCE_MODEL_FILEREADER_H__

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

#endif  // __MAZE_SOURCE_MODEL_FILEREADER_H__