#ifndef __MAZE_SOURCE_MODEL_CAVE_CAVEGENERATOR_H__
#define __MAZE_SOURCE_MODEL_CAVE_CAVEGENERATOR_H__

namespace s21 {

//#include <random>
//#include <cmath>
//#include <algorithm>
//#include <iostream>
//#include <numeric>
#include <vector>
//#include <iostream>


class GridCaveGenerator {
public:
    std::vector<std::vector<bool>> generateGrid(size_t rows, size_t cols, int probability_birth) {
        if (rows == 0 || cols == 0 || probability_birth == 0) {
            return std::vector<std::vector<bool>>{};
        }

        std::vector<std::vector<bool>> grid(rows, std::vector<bool>(cols, false));

        for (size_t row = 0; row < rows; row++) {
            for (size_t col = 0; col < cols; col++) {
                grid[row][col]  = true;
////                grid[row][col] = (dist_(gen_) > probability_birth);
            }
        }
        return grid;
    }

 private:
//     std::random_device rd_{};
//    // std::mt19937 gen_{rd_()};
//    // std::uniform_int_distribution<> dist_{0, 100};
};

}  // namespace s21


#endif  // __MAZE_SOURCE_MODEL_CAVE_CAVEGENERATOR_H__
