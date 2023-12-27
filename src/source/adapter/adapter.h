#ifndef __MAZE_SOURCE_ADAPTER_ADAPTER_H__
#define __MAZE_SOURCE_ADAPTER_ADAPTER_H__

#include <string>
#include <vector>

#include "common/cell.h"
#include "common/point2d.h"
#include "model/cave/cavefilemanager.h"
#include "model/cave/cavegenerator.h"
#include "model/cave/cellularautomaton.h"

namespace s21 {

class Adapter {
 public:
  explicit Adapter(CellularAutomaton& cellular_automaton);

  std::vector<std::vector<Cell>> generateMaze(const int M, const int N) const;
  std::vector<Point2D> solutionMaze(std::vector<std::vector<Cell>> maze,
                                    Point2D start, Point2D end) const;
  std::vector<std::vector<Cell>> loadMazeFromFile(std::string filename) const;
  void saveMazeFile(const std::vector<std::vector<Cell>>& maze,
                    const std::string& filename) const;

  const std::vector<std::vector<bool>>& getCaveGrid() const;
  bool loadCaveFromFile(const std::string& filename) const;
  void saveCaveToFile(const std::string& filename) const;
  bool evolveCave(size_t birth_limit, size_t death_limit);
  void generateCave(size_t rows, size_t cols, int probability_birth);

 private:
  CellularAutomaton& cellular_automaton_;
};

}  // namespace s21

#endif  // __MAZE_SOURCE_ADAPTER_ADAPTER_H__