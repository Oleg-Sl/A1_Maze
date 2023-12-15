#include "mazecontroller.h"

namespace s21 {

Maze MazeController::generateMaze(const int M, const int N) const {
  return MazeGenerator().generateMaze(M, N);
};

}  // namespace s21