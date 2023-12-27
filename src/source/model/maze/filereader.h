#ifndef __MAZE_SOURCE_MODEL_MAZE_FILEREADER_H__
#define __MAZE_SOURCE_MODEL_MAZE_FILEREADER_H__

#include <string>
#include <vector>

#include "common/cell.h"

namespace s21 {

class FileReader {
 public:
  std::vector<std::vector<Cell>> loadMaze(const std::string& filename) const;
};

}  // namespace s21

#endif  // __MAZE_SOURCE_MODEL_MAZE_FILEREADER_H__