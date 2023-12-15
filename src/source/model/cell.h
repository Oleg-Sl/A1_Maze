#ifndef __MAZE_SOURCE_INCLUDE_CELL_H__
#define __MAZE_SOURCE_INCLUDE_CELL_H__

namespace s21 {

struct Cell {
  bool right_wall = 0;
  bool left_wall = 0;
  bool up_wall = 0;
  bool down_wall = 0;

  int set_id = 0;

  bool operator==(const Cell &other) const {
    return right_wall == other.right_wall && down_wall == other.down_wall &&
           set_id == other.set_id && up_wall == other.up_wall &&
           left_wall == other.left_wall;
  }

  void fill() {
    right_wall = 1;
    left_wall = 1;
    up_wall = 1;
    down_wall = 1;
  }

  bool isFilled() const { return right_wall && left_wall && up_wall && down_wall; }
};

}  // namespace s21

#endif  // __MAZE_SOURCE_INCLUDE_CELL_H__