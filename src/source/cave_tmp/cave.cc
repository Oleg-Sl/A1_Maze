#include "cave.h"
#include <cmath>
#include <iostream>

namespace s21 {


Cave::Cave() {
}


Cave::Cave(size_t rows, size_t cols) {
    grid_.resize(rows, std::vector<bool>(cols, false));
    rows_ = rows;
    cols_ = cols;
    grid_[1][1] = true;
}


Cave::Cave(const std::vector<std::vector<bool>> &grid) : rows_(grid.size()), cols_(grid.size() == 0 ? 0 : grid[0].size()), grid_(grid) {
}


size_t Cave::getRows() const {
    return rows_;
}


size_t Cave::getCols() const {
    return cols_;
}


bool Cave::getCell(size_t row, size_t col) const {
    if (row >= rows_ || col >= cols_) {
        throw std::out_of_range("Index out of range");
    }
    return grid_[row][col];
}


void  Cave::setCell(size_t row, size_t col, bool value) {
    if (row >= rows_ || col >= cols_) {
        throw std::out_of_range("Index out of range");
    }
    grid_[row][col] = value;
}

// bool Cave::operator()(size_t row, size_t col) const {
//     return grid_[row][col];
// }


// bool &Cave::operator()(size_t row, size_t col) {
//     return grid_[row][col];
// }


void Cave::print() const {
    for (size_t i = 0; i < rows_; i++) {
        for (size_t j = 0; j < cols_; j++) {
            if (grid_[i][j]) {
                std::cout << (char)(178)<< static_cast<char>(219);
            } else {
                std::cout << "  ";
            }
        }
        std::cout << std::endl;
    }
}


}  // namespace s21


int main(int argc, char const *argv[]) {
    size_t rows = 5;
    size_t cols = 5;
    // std::cout << rows << " " << cols << std::endl;
    s21::Cave cave(rows, cols);
    std::cout << "rows = " << rows << ", cols = " << cols << std::endl;
    std::cout << "***************************************" << std::endl;
    cave.print();
    std::cout << "***************************************" << std::endl;

    return 0;
}