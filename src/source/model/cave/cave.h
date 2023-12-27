#ifndef __MAZE_SOURCE_MODEL_CAVE_CAVE_H__
#define __MAZE_SOURCE_MODEL_CAVE_CAVE_H__

#include <iostream>
#include <vector>

namespace s21 {

class Cave {
 public:
  using Grid = std::vector<std::vector<bool>>;

  Cave();
  Cave(size_t rows, size_t cols);
  explicit Cave(const Grid &matrix);

  size_t get_number_living_neighbors(size_t row, size_t col);
  size_t getRows() const;
  size_t getCols() const;
  const Grid &getGrid() const;
  bool isAlive(size_t row, size_t col) const;
  void print() const;
  void setGrid(Grid &grid);
  void setGrid(Grid &&grid);
  void setAlive(size_t row, size_t col, bool alive);

 private:
  size_t rows_{};
  size_t cols_{};
  Grid grid_{};
};

}  // namespace s21

#endif  // __MAZE_SOURCE_MODEL_CAVE_CAVE_H__