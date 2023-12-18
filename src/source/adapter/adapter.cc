#include <stdexcept>

#include "adapter.h"
#include "filereader.h"
#include "filesaver.h"
#include "mazegenerator.h"
#include "mazesolver.h"

namespace s21 {

std::vector<std::vector<Cell>> Adapter::generateMaze(const int M,
                                                     const int N) const {
  return MazeGenerator().generateMaze(M, N).getGrid();
}

std::vector<Point2D> Adapter::solutionMaze(std::vector<std::vector<Cell>> maze,
                                           Point2D start, Point2D end) const {
  return MazeSolver().findPath(maze, start, end);
}

std::vector<std::vector<Cell>> Adapter::loadMazeFromFile(
    std::string filename) const {
  std::vector<std::vector<Cell>> maze;

  try {
    maze = FileReader().loadMaze(filename);
  } catch (std::invalid_argument& e) {
    maze.clear();
  }
  return maze;
}

void Adapter::saveMazeFile(const std::vector<std::vector<Cell>>& maze,
                           const std::string& filename) const {
  FileSaver().saveMaze(maze, filename);
}

}  // namespace s21