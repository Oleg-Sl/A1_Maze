#ifndef __MAZE_SOURCE_MODEL_CAVE_CAVEGENERATOR_H__
#define __MAZE_SOURCE_MODEL_CAVE_CAVEGENERATOR_H__

#include <random>
#include <vector>

namespace s21 {

class GridCaveGenerator {
 public:
  std::vector<std::vector<bool>> generateGrid(size_t rows, size_t cols,
                                              int probability_birth);

 private:
  std::random_device rd_{};
  std::mt19937 gen_{rd_()};
  std::uniform_int_distribution<> dist_{0, 100};
};

}  // namespace s21

#endif  // __MAZE_SOURCE_MODEL_CAVE_CAVEGENERATOR_H__