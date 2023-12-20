#include <iostream>
#include <vector>



namespace s21 {


class Cave {


public:
    Cave();
    Cave(size_t rows, size_t cols);
    Cave(const std::vector<std::vector<bool>> &grid);

    size_t getRows() const;
    size_t getCols() const;

    bool getCell(size_t row, size_t col) const;
    void setCell(size_t row, size_t col, bool value);

    void print() const;

private:
    size_t rows_{};
    size_t cols_{};
    std::vector<std::vector<bool>> grid_{};
};



}  // namespace s21


