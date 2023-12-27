#ifndef __MAZE_SOURCE_VIEW_MAINWINDOW_H__
#define __MAZE_SOURCE_VIEW_MAINWINDOW_H__

#include <QGraphicsScene>
#include <QMainWindow>
#include <QTimer>
#include <vector>

#include "adapter/adapter.h"
#include "common/cell.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

namespace s21 {

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  const int kNumberPageMaze_ = 0;
  const int kNumberPageCave_ = 1;
  const int kCellBorderWidth = 2;
  const int kSolutionLineWidth = 2;
  const int kMaxMazeRows = 50;
  const int kMaxMazeCols = 50;
  const QColor kSolutionLineColor = Qt::red;

  const int kMaxCaveRows = 50;
  const int kMaxCaveCols = 50;
  const int kMinCaveBirthDeathLimit = 0;
  const int kMaxCaveBirthDeathLimit = 7;
  const int kMinTimeout = 10;

  explicit MainWindow(Adapter adapter, QWidget *parent = nullptr);
  ~MainWindow();

  void setConnections();
  void initializeSpins();
  void addMazeOnScene(QGraphicsScene &scene,
                      const std::vector<std::vector<Cell>> &maze);
  void clearSolution(QGraphicsScene &scene);
  std::vector<Point2D> generateSolutionForScene(
      const QGraphicsScene &scene, const std::vector<std::vector<Cell>> &maze,
      Point2D start, Point2D end);
  void addSolutionOnScene(QGraphicsScene &scene,
                          const std::vector<Point2D> &solution);

  void drawCave();
  bool makeStepCave();
  void stopTimerCave();

 public slots:
  void drawMaze();
  void drawSolution();
  void importMazeFile();
  void exportMazeFile();
  void generateMaze();

  void handleChangeTab(int page);
  void handleImportMatrixFile();
  void handleExportMatrixFile();
  void handleGenerateGridCave();
  void handleStepEvolutionCave();
  void handleAutoEvolutionCave();
  void handleTimerEvolutionCave();

 private:
  s21::Adapter adapter_;
  std::vector<std::vector<Cell>> maze_;
  QGraphicsScene scene_;
  QGraphicsScene cave_scene_;
  Ui::MainWindow *ui_;
  QTimer timer_;
};

}  // namespace s21

#endif  // __MAZE_SOURCE_VIEW_MAINWINDOW_H__