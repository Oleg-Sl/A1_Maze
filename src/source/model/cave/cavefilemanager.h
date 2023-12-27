#ifndef __MAZE_SOURCE_MODEL_CAVE_CAVEFILEMANAGER_H__
#define __MAZE_SOURCE_MODEL_CAVE_CAVEFILEMANAGER_H__

#include <fstream>
#include <iostream>
#include <vector>

namespace s21 {

class MatrixFileHandler {
 public:
  static std::vector<std::vector<bool>> load(const std::string &filename);
  static void save(const std::vector<std::vector<bool>> &matrix,
                   const std::string &filename);
};

}  // namespace s21

#endif  // __MAZE_SOURCE_MODEL_CAVE_CAVEFILEMANAGER_H__