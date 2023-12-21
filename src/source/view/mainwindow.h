#ifndef __MAZE_SOURCE_VIEW_MAINWINDOW_H__
#define __MAZE_SOURCE_VIEW_MAINWINDOW_H__

#include <QGraphicsScene>
#include <QMainWindow>
#include <vector>

#include "adapter.h"
#include "cell.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

namespace s21 {

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  const int kCellBorderWidth = 2;
  const int kSolutionLineWidth = 2;
  const int kMaxMazeRows = 50;
  const int kMaxMazeCols = 50;
  const int kMaxCaveRows = 50;
  const int kMaxCaveCols = 50;
  const int kMinCaveBirthDeathLimit = 0;
  const int kMaxCaveBirthDeathLimit = 7;

  MainWindow(Adapter adapter, QWidget *parent = nullptr);
  ~MainWindow();
  void drawMaze(QGraphicsScene &scene, const std::vector<std::vector<Cell>> &grid);
  void draw();
  void drawSolution();
  void importMazeFile();
  void exportMazeFile();
  void generateMaze();

  void drawCave();
  void importCaveFile();
  void exportCaveFile();
  void generateCave();
  void makeStepCave();
  void autoEvolveCave();

 private:
  s21::Adapter adapter_;
  std::vector<std::vector<Cell>> maze_;
  std::vector<std::vector<bool>> cave_;
  Ui::MainWindow *ui_;
};

}  // namespace s21
#endif  // __MAZE_SOURCE_VIEW_MAINWINDOW_H__
