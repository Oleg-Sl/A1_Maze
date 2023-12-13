#include <vector>

#include "maze.h"
#include "filereader.h"

int main() {
  using namespace s21;
  // const int M = 4;
  // const int N = 4;

  // std::vector<std::vector<int>> right_walls;
  // for (size_t i = 0; i < M; i++) {
  //   right_walls.push_back(std::vector<int>{});
  //   for (size_t j = 0; j < N; j++) {
  //     right_walls[i].push_back(1);
  //   }
  // }

  // std::vector<std::vector<int>> down_walls;
  // for (size_t i = 0; i < M; i++) {
  //   down_walls.push_back(std::vector<int>{});
  //   for (size_t j = 0; j < N; j++) {
  //     down_walls[i].push_back(1);
  //   }
  // }

  // Maze maze = Maze(right_walls, down_walls);
  // auto matrix = maze.getGrid();

  // for (size_t i = 0; i < maze.getM(); i++) {
  //   for (size_t j = 0; j < maze.getN(); j++) {
  //     std::cout << matrix[i][j].down_wall << " " << matrix[i][j].right_wall << std::endl;
  //   }
  // }

  FileReader reader;

  Maze maze = reader.loadMaze("test.txt");
  maze.Print();

  return 0;
}