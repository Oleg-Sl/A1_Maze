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

void Cave::print() const {
    for (size_t i = 0; i < rows_ + 2; i++) {
        if (i == 0) {
            std::cout << "+-";
        } else if (i == rows_ + 1) {
            std::cout << "-+";
        } else {
            std::cout << "---";
        }
    }
    std::cout << std::endl;
    for (size_t i = 0; i < rows_; i++) {
        std::cout << "| ";
        for (size_t j = 0; j < cols_; j++) {
            if (grid_[i][j]) {
                std::cout << " " << static_cast<char>(219) << " ";
            } else {
                std::cout << " . ";
            }
        }
        std::cout << " |" << std::endl;
    }
    for (size_t i = 0; i < rows_ + 2; i++) {
        if (i == 0) {
            std::cout << "+-";
        } else if (i == rows_ + 1) {
            std::cout << "-+";
        } else {
            std::cout << "---";
        }
    }
    std::cout << std::endl;
}


}  // namespace s21


int main(int argc, char const *argv[]) {
    size_t rows = 25;
    size_t cols = 25;
    // std::cout << rows << " " << cols << std::endl;
    s21::Cave cave(rows, cols);
    std::cout << "rows = " << rows << ", cols = " << cols << std::endl;
    cave.print();

    return 0;
}