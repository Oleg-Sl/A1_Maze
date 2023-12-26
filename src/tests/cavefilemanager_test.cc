#include <gtest/gtest.h>


#include "../source/model/cave/cavefilemanager.h"


namespace s21 {


TEST(CaveFileManager, EmptyFile) {
  std::vector<std::vector<bool>> grid = {};

  const std::string filename = "_test_cave_file.txt";
  
  MatrixFileHandler::save(grid, filename);

  std::vector<std::vector<bool>> grid_2 = MatrixFileHandler::load(filename);

  ASSERT_EQ(grid.size(), grid_2.size());
}


TEST(CaveFileManager, NotEmptyFile) {
  std::vector<std::vector<bool>> grid = {
      {true, false, false},
      {false, true, false},
      {false, true, true}
  };

  const std::string filename = "_test_cave_file.txt";
  
  MatrixFileHandler::save(grid, filename);

  std::vector<std::vector<bool>> grid_2 = MatrixFileHandler::load(filename);


  ASSERT_EQ(grid.size(), grid_2.size());

  for (size_t i = 0; i < grid.size(); ++i) {
    ASSERT_EQ(grid[i].size(), grid_2[i].size());
    
    for (size_t j = 0; j < grid[i].size(); ++j) {
      ASSERT_EQ(grid[i][j], grid_2[i][j]);
    }
  }
}

TEST(CaveFileManager, FileNotExist) {
  std::vector<std::vector<bool>> grid = {
      {true, false, false},
      {false, true, false},
      {false, true, true}
  };

  const std::string filename = "12134567890987654321.txt";

  ASSERT_THROW(MatrixFileHandler::load(filename), std::invalid_argument);
}


}  // namespace s21

