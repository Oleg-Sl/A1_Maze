#ifndef __MAZE_SOURCE_MODEL_CAVE_CAVEFILEMANAGER_H__
#define __MAZE_SOURCE_MODEL_CAVE_CAVEFILEMANAGER_H__


#include <iostream>
#include <vector>
#include <fstream>


namespace s21 {


class MatrixFileHandler {

public:
    static void save(const std::vector<std::vector<bool>> &grid, const std::string &filename);
    static std::vector<std::vector<bool>> load(const std::string &filename);

};


}  // namespace s21


#endif  // __MAZE_SOURCE_MODEL_CAVE_CAVEFILEMANAGER_H__
