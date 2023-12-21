#include <iostream>
#include <vector>


// #include "cave_file_manager.h"


namespace s21 {


class Cave {
public:
    using Grid = std::vector<std::vector<bool>>;
    Cave();
    Cave(size_t rows, size_t cols);
    Cave(const Grid &matrix);
    Cave(const Cave &other);

    size_t getRows() const;
    size_t getCols() const;
    const Grid &getGrid() const;

    bool isAlive(size_t row, size_t col) const;
    void setAlive(size_t row, size_t col, bool alive);

    size_t get_number_living_neighbors(size_t row, size_t col);
    void print() const;

private:
    size_t rows_{};
    size_t cols_{};
    Grid grid_{};
};


}  // namespace s21
