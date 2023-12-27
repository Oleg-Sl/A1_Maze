#ifndef __MAZE_SOURCE_MODEL_MAZE_MAZEGENERATOR_H__
#define __MAZE_SOURCE_MODEL_MAZE_MAZEGENERATOR_H__

#include "basemazegenerator.h"
#include "maze.h"

namespace s21 {

class MazeGenerator : BaseMazeGenerator {
 public:
  Maze generateMaze(size_t rows, size_t cols) override;

 private:
  void initializeFirstRow(const Maze& maze,
                          std::vector<std::vector<size_t>>& sets);
  void genRows(Maze& maze, std::vector<std::vector<size_t>>& sets);
  void genLastRow(Maze& maze, std::vector<std::vector<size_t>>& sets);
  void unionSets(std::vector<size_t>& sets, size_t set1, size_t set2);
  void buildWalls(Maze& maze, std::vector<std::vector<size_t>>& sets,
                  size_t row, size_t col);

  std::random_device rd_{};
  std::mt19937 gen_{rd_()};
  std::uniform_int_distribution<> dist_{0, 1};
};

}  // namespace s21

#endif  // __MAZE_SOURCE_MODEL_MAZE_MAZEGENERATOR_H__