#ifndef __MAZE_SOURCE_MODEL_MAZE_MAZEFILEMANAGER_H__
#define __MAZE_SOURCE_MODEL_MAZE_MAZEFILEMANAGER_H__

#include <string>
#include <vector>

#include "common/cell.h"
#include "maze.h"

namespace s21 {

class MazeFileManager {
 public:
  static std::vector<std::vector<Cell>> loadMaze(const std::string& filename);
  static void saveMaze(const Maze& maze, const std::string& filename);
};

}  // namespace s21

#endif  // __MAZE_SOURCE_MODEL_MAZE_MAZEFILEMANAGER_H__