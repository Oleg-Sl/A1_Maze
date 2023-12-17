#ifndef __MAZE_SOURCE_COMMON_CELL_H__
#define __MAZE_SOURCE_COMMON_CELL_H__

namespace s21 {

struct Cell {
  bool right_wall = 0;
  bool left_wall = 0;
  bool up_wall = 0;
  bool down_wall = 0;

  bool operator==(const Cell &other) const {
    return right_wall == other.right_wall && down_wall == other.down_wall &&
           up_wall == other.up_wall && left_wall == other.left_wall;
  }
};

}  // namespace s21

#endif  // __MAZE_SOURCE_COMMON_CELL_H__