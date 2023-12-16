#ifndef __MAZE_VIEW_MAZECELL_H__
#define __MAZE_VIEW_MAZECELL_H__

namespace s21 {

struct MazeCell {
  bool up_wall;
  bool down_wall;
  bool right_wall;
  bool left_wall;
};

}  // namespace s21

#endif  // __MAZE_VIEW_MAZECELL_H__