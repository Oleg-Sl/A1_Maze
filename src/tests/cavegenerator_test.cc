#include "model/cave/cavegenerator.h"

#include <gtest/gtest.h>

namespace s21 {

TEST(CaveGenerator, EmptyGrid) {
  std::vector<std::vector<bool>> grid =
      GridCaveGenerator().generateGrid(0, 0, 50);
  ASSERT_EQ(grid.size(), 0);
}

TEST(CaveGenerator, NotEmptyGrid) {
  std::vector<std::vector<bool>> grid =
      GridCaveGenerator().generateGrid(5, 5, 50);
  ASSERT_EQ(grid.size(), 5);
  ASSERT_EQ(grid[0].size(), 5);
}

TEST(CaveGenerator, ProbabilityBirth10) {
  size_t rows = 40;
  size_t cols = 40;
  size_t probability_ref = 50;
  std::vector<std::vector<bool>> grid =
      GridCaveGenerator().generateGrid(rows, cols, probability_ref);

  size_t count_alive = 0;
  size_t count_dead = 0;

  for (auto& row : grid) {
    for (auto cell : row) {
      if (cell) {
        ++count_alive;
      } else {
        ++count_dead;
      }
    }
  }

  double probability =
      100 * static_cast<double>(count_alive) / (count_alive + count_dead);
  ASSERT_TRUE(std::abs(probability_ref - probability) < 15);
}

TEST(CaveGenerator, ProbabilityBirth80) {
  size_t rows = 500;
  size_t cols = 500;
  size_t probability_ref = 80;
  std::vector<std::vector<bool>> grid =
      GridCaveGenerator().generateGrid(rows, cols, probability_ref);

  size_t count_alive = 0;
  size_t count_dead = 0;

  for (auto& row : grid) {
    for (auto cell : row) {
      if (cell) {
        ++count_dead;
      } else {
        ++count_alive;
      }
    }
  }

  double probability =
      100 * static_cast<double>(count_alive) / (count_alive + count_dead);
  ASSERT_TRUE(std::abs(probability_ref - probability) < 15);
}

}  // namespace s21
