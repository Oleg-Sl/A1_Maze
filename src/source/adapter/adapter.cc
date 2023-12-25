#include <stdexcept>

#include "adapter.h"
#include "filereader.h"
#include "filesaver.h"
#include "mazegenerator.h"
#include "mazesolver.h"
//#include "cave_file_manager.h"
// #include "cave_tmp/cavefilemanager.h"


namespace s21 {


Adapter::Adapter(CellularAutomaton& cellular_automaton) : cellular_automaton_(cellular_automaton) {
}

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


// std::vector<std::vector<bool>> Adapter::loadCaveFromFile(const std::string& filename) const {
//   try {
//     return MatrixFileHandler::load(filename);
//   } catch (const std::invalid_argument& e) {
//     std::cout << e.what();
//   }
//   return std::vector<std::vector<bool>>{};
// }


}  // namespace s21
