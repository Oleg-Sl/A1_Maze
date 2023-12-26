#include "cavefilemanager.h"

namespace s21 {

void MatrixFileHandler::save(const std::vector<std::vector<bool>> &matrix,
                             const std::string &filename) {
  std::ofstream fileoutstream(filename);
  if (!fileoutstream) {
    throw std::invalid_argument("File opening error");
  }
  fileoutstream << matrix.size() << " "
                << ((matrix.size() != 0) ? matrix[0].size() : 0) << std::endl;
  for (auto &row : matrix) {
    for (auto cell : row) {
      fileoutstream << (cell ? 1 : 0) << " ";
    }
    fileoutstream << std::endl;
  }
}

std::vector<std::vector<bool>> MatrixFileHandler::load(
    const std::string &filename) {
  size_t rows = 0;
  size_t cols = 0;
  std::ifstream fileinstream(filename);

  if (!fileinstream.is_open()) {
    throw std::invalid_argument("File opening error");
  }

  fileinstream >> rows >> cols;
  std::vector<std::vector<bool>> matrix(rows, std::vector<bool>(cols, false));
  int tmp = 0;
  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j) {
      fileinstream >> tmp;
      matrix[i][j] = (tmp == 0) ? false : true;
    }
  }

  return matrix;
}

}  // namespace s21
