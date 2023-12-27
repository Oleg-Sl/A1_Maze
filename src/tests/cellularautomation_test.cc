#include <gtest/gtest.h>

#include "model/cave/cave.h"
#include "model/cave/cellularautomaton.h"

namespace s21 {

TEST(CellularAutomation, ConstructorEmptyCave) {
  Cave cave;
  CellularAutomaton cellular_automation(cave);
  ASSERT_EQ(cellular_automation.getCave().getRows(), 0);
  ASSERT_EQ(cellular_automation.getCave().getCols(), 0);
}

TEST(CellularAutomation, ConstructorNotEmptyCave) {
  Cave cave(5, 3);
  CellularAutomaton cellular_automation(cave);
  ASSERT_EQ(cellular_automation.getCave().getRows(), 5);
  ASSERT_EQ(cellular_automation.getCave().getCols(), 3);
}

TEST(CellularAutomation, EvolveBirthLowLevel) {
  const std::vector<std::vector<bool>> grid = {
      {false, true, false},
      {true, false, true},
      {false, false, false},
  };
  Cave cave(grid);
  CellularAutomaton cellular_automation(cave);

  bool is_change = cellular_automation.evolve(3, 5);
  ASSERT_TRUE(is_change);
  ASSERT_EQ(cellular_automation.getCave().isAlive(1, 1), false);
}

TEST(CellularAutomation, EvolveBirthHighLevel) {
  const std::vector<std::vector<bool>> grid = {
      {false, true, false},
      {true, false, true},
      {false, false, false},
  };
  Cave cave(grid);
  CellularAutomaton cellular_automation(cave);

  bool is_change = cellular_automation.evolve(2, 5);
  ASSERT_TRUE(is_change);
  ASSERT_EQ(cellular_automation.getCave().isAlive(1, 1), true);
}

TEST(CellularAutomation, EvolveDeadLowLevel) {
  const std::vector<std::vector<bool>> grid = {
      {false, true, false},
      {true, true, true},
      {false, false, false},
  };
  Cave cave(grid);
  CellularAutomaton cellular_automation(cave);

  bool is_change = cellular_automation.evolve(5, 3);
  ASSERT_TRUE(is_change);
  ASSERT_EQ(cellular_automation.getCave().isAlive(1, 1), true);
}

TEST(CellularAutomation, EvolveDeadHighLevel) {
  const std::vector<std::vector<bool>> grid = {
      {false, true, false},
      {true, true, true},
      {false, false, false},
  };
  Cave cave(grid);
  CellularAutomaton cellular_automation(cave);

  bool is_change = cellular_automation.evolve(5, 4);
  ASSERT_TRUE(is_change);
  ASSERT_EQ(cellular_automation.getCave().isAlive(1, 1), false);
}

}  // namespace s21
