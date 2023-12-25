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


const std::vector<std::vector<bool>>& Adapter::getCaveGrid() const {
  return cellular_automaton_.getCave().getGrid();
}
    
bool Adapter::loadCaveFromFile(const std::string& filename) const {
  try {
    cellular_automaton_.getCave().setGrid(MatrixFileHandler::load(filename));
  } catch (const std::invalid_argument& e) {
    std::cout << e.what();
    return false;
  }

  return true;
}

void Adapter::saveCaveToFile(const std::string& filename) const {
  MatrixFileHandler::save(getCaveGrid(), filename);
}

bool Adapter::evolveCave(size_t birth_limit, size_t death_limit) {
  return cellular_automaton_.evolve(birth_limit, death_limit);
}

void Adapter::generateCave(size_t rows, size_t cols, int probability_birth) {
  cellular_automaton_.getCave().setGrid(GridCaveGenerator().generateGrid(rows, cols, probability_birth));
}



}  // namespace s21
