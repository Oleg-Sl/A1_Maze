#ifndef __MAZE_SOURCE_COMMON_POINT2D_H__
#define __MAZE_SOURCE_COMMON_POINT2D_H__
namespace s21 {

struct Point2D {
  int x;
  int y;

  bool operator==(const Point2D &other) const {
    return x == other.x && y == other.y;
  }
};

}  // namespace s21

#endif  // __MAZE_SOURCE_COMMON_POINT2D_H__