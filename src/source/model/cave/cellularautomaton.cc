#include "cellularautomaton.h"

namespace s21 {

CellularAutomaton::CellularAutomaton(Cave& cave) : cave_(cave) {}

Cave& CellularAutomaton::getCave() const { return cave_; }

bool CellularAutomaton::evolve(size_t birth_limit, size_t death_limit) {
  bool is_change = false;
  Cave current_cave(cave_);
  for (size_t row = 0; row < cave_.getRows(); ++row) {
    for (size_t col = 0; col < cave_.getCols(); ++col) {
      size_t number_alive = current_cave.get_number_living_neighbors(row, col);
      bool isAlive = current_cave.isAlive(row, col);

      if (isAlive && number_alive < death_limit) {
        is_change = true;
        cave_.setAlive(row, col, false);
      } else if (!isAlive && number_alive > birth_limit) {
        is_change = true;
        cave_.setAlive(row, col, true);
      }
    }
  }

  return is_change;
}

}  // namespace s21
