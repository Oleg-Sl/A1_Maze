#include "model/cave/cave.h"

#include <gtest/gtest.h>

namespace s21 {

TEST(CaveConstructor, DefaultConstructor) {
  Cave cave;
  ASSERT_EQ(cave.getRows(), 0);
  ASSERT_EQ(cave.getCols(), 0);
}

TEST(CaveConstructor, SizeConstructor) {
  {
    Cave cave(0, 0);
    ASSERT_EQ(cave.getRows(), 0);
    ASSERT_EQ(cave.getCols(), 0);
  }

  {
    Cave cave(4, 7);
    ASSERT_EQ(cave.getRows(), 4);
    ASSERT_EQ(cave.getCols(), 7);
  }

  {
    Cave cave(10, 10);
    ASSERT_EQ(cave.getRows(), 10);
    ASSERT_EQ(cave.getCols(), 10);
  }
}

TEST(CaveConstructor, MatrixConstructor) {
  {
    std::vector<std::vector<bool>> grid;
    Cave cave(grid);
    ASSERT_EQ(cave.getRows(), 0);
    ASSERT_EQ(cave.getCols(), 0);
  }

  {
    std::vector<std::vector<bool>> grid = {{true, false, false},
                                           {false, true, false},
                                           {true, false, true},
                                           {false, false, true},
                                           {false, false, true}};
    Cave cave(grid);
    ASSERT_EQ(cave.getRows(), 5);
    ASSERT_EQ(cave.getCols(), 3);
  }

  {
    std::vector<std::vector<bool>> grid = {
        {true, false, false}, {false, true, false}, {true, false, true}};
    Cave cave(grid);
    ASSERT_EQ(cave.getRows(), 3);
    ASSERT_EQ(cave.getCols(), 3);
  }
}

TEST(CaveGetterSetter, GetRowsAndCols) {
  {
    Cave cave(0, 0);
    ASSERT_EQ(cave.getRows(), 0);
    ASSERT_EQ(cave.getCols(), 0);
  }

  {
    Cave cave(4, 7);
    ASSERT_EQ(cave.getRows(), 4);
    ASSERT_EQ(cave.getCols(), 7);
  }

  {
    Cave cave(11, 11);
    ASSERT_EQ(cave.getRows(), 11);
    ASSERT_EQ(cave.getCols(), 11);
  }
}

TEST(CaveGetterSetter, GetAndSetAlive) {
  {
    Cave cave(4, 7);
    ASSERT_EQ(cave.isAlive(0, 0), false);
    ASSERT_EQ(cave.isAlive(3, 6), false);
  }

  {
    Cave cave(11, 11);

    ASSERT_EQ(cave.isAlive(0, 0), false);
    cave.setAlive(0, 0, true);
    ASSERT_EQ(cave.isAlive(0, 0), true);

    ASSERT_EQ(cave.isAlive(5, 4), false);
    cave.setAlive(5, 4, true);
    ASSERT_EQ(cave.isAlive(5, 4), true);

    ASSERT_EQ(cave.isAlive(10, 10), false);
    cave.setAlive(10, 10, true);
    ASSERT_EQ(cave.isAlive(10, 10), true);
  }
}

TEST(CaveGetterSetter, ThrowGetAndSetAlive) {
  {
    Cave cave(0, 0);
    ASSERT_THROW(cave.isAlive(0, 0), std::out_of_range);
  }

  {
    Cave cave(4, 7);
    ASSERT_EQ(cave.isAlive(0, 0), false);
    ASSERT_EQ(cave.isAlive(3, 6), false);
    ASSERT_THROW(cave.isAlive(4, 6), std::out_of_range);
    ASSERT_THROW(cave.isAlive(3, 7), std::out_of_range);
  }
}

TEST(CaveGetterSetter, GetGrid) {
  {
    std::vector<std::vector<bool>> grid;
    Cave cave(grid);
    std::vector<std::vector<bool>> cave_grid = cave.getGrid();
    ASSERT_EQ(cave_grid.size(), grid.size());
  }

  {
    std::vector<std::vector<bool>> grid = {{true, false, false},
                                           {false, true, false},
                                           {true, false, true},
                                           {false, false, true},
                                           {false, false, true}};
    Cave cave(grid);
    std::vector<std::vector<bool>> cave_grid = cave.getGrid();
    ASSERT_EQ(cave_grid.size(), grid.size());
    ASSERT_EQ(cave_grid[0].size(), grid[0].size());
  }

  {
    std::vector<std::vector<bool>> grid = {
        {true, false, false}, {false, true, false}, {true, false, true}};
    Cave cave(grid);
    std::vector<std::vector<bool>> cave_grid = cave.getGrid();
    ASSERT_EQ(cave_grid.size(), grid.size());
    ASSERT_EQ(cave_grid[0].size(), grid[0].size());
  }
}

TEST(CaveGetterSetter, SetGrid) {
  {
    std::vector<std::vector<bool>> grid;
    Cave cave(grid);

    std::vector<std::vector<bool>> grid_new = {{true, false, false},
                                               {false, true, false},
                                               {true, false, true},
                                               {false, false, true},
                                               {false, false, true}};
    cave.setGrid(grid_new);

    ASSERT_EQ(cave.getRows(), 5);
    ASSERT_EQ(cave.getCols(), 3);
  }

  {
    std::vector<std::vector<bool>> grid = {{true, false, false},
                                           {false, true, false},
                                           {true, false, true},
                                           {false, false, true},
                                           {false, false, true}};
    Cave cave(grid);

    std::vector<std::vector<bool>> grid_new;
    cave.setGrid(grid_new);

    ASSERT_EQ(cave.getRows(), 0);
    ASSERT_EQ(cave.getCols(), 0);
  }
}

TEST(CaveFunction, GetNumberLivingNeighbors) {
  {
    Cave cave(11, 11);
    ASSERT_EQ(cave.get_number_living_neighbors(0, 0), 5);
    ASSERT_EQ(cave.get_number_living_neighbors(5, 5), 0);
    ASSERT_EQ(cave.get_number_living_neighbors(10, 10), 5);
    ASSERT_EQ(cave.get_number_living_neighbors(10, 5), 3);
    ASSERT_EQ(cave.get_number_living_neighbors(5, 10), 3);
  }

  {
    std::vector<std::vector<bool>> grid = {{true, true, false},
                                           {true, true, false},
                                           {true, false, true},
                                           {false, false, false},
                                           {true, false, true}};
    Cave cave(grid);
    ASSERT_EQ(cave.get_number_living_neighbors(0, 0), 8);
    ASSERT_EQ(cave.get_number_living_neighbors(0, 2), 7);
    ASSERT_EQ(cave.get_number_living_neighbors(3, 1), 4);
    ASSERT_EQ(cave.get_number_living_neighbors(4, 1), 5);
    ASSERT_EQ(cave.get_number_living_neighbors(4, 2), 5);
  }
}

TEST(CaveFunction, ThrowGetNumberLivingNeighbors) {
  {
    Cave cave;
    ASSERT_THROW(cave.get_number_living_neighbors(0, 0), std::out_of_range);
  }

  {
    Cave cave(11, 11);
    ASSERT_THROW(cave.get_number_living_neighbors(11, 11), std::out_of_range);
  }

  {
    std::vector<std::vector<bool>> grid = {{true, true, false},
                                           {true, true, false},
                                           {true, false, true},
                                           {false, false, false},
                                           {true, false, true}};
    Cave cave(grid);
    ASSERT_THROW(cave.get_number_living_neighbors(5, 3), std::out_of_range);
  }
}

}  // namespace s21
