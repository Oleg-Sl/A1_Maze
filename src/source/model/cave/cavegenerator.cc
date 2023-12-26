#include "cavegenerator.h"

namespace s21 {

std::vector<std::vector<bool>> GridCaveGenerator::generateGrid(
    size_t rows, size_t cols, int probability_birth) {
  if (rows == 0 || cols == 0 || probability_birth == 0) {
    return std::vector<std::vector<bool>>{};
  }

  std::vector<std::vector<bool>> grid(rows, std::vector<bool>(cols, false));

  for (size_t row = 0; row < rows; row++) {
    for (size_t col = 0; col < cols; col++) {
      grid[row][col] = (dist_(gen_) > probability_birth);
    }
  }
  return grid;
}

}  // namespace s21
