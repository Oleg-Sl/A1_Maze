#ifndef __MAZE_SOURCE_MODEL_CAVE_CELLULARAUTOMATON_H__
#define __MAZE_SOURCE_MODEL_CAVE_CELLULARAUTOMATON_H__

#include "cave.h"

namespace s21 {

class CellularAutomaton {
 public:
  explicit CellularAutomaton(Cave &cave);

  bool evolve(size_t birth_limit = 3, size_t death_limit = 4);
  Cave &getCave() const;

 private:
  Cave &cave_;
};

}  // namespace s21

#endif  // __MAZE_SOURCE_MODEL_CAVE_CELLULARAUTOMATON_H__