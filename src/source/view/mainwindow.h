#ifndef __MAZE_SOURCE_VIEW_MAINWINDOW_H__
#define __MAZE_SOURCE_VIEW_MAINWINDOW_H__

#include <QGraphicsScene>
#include <QMainWindow>
#include <vector>

#include "mazecontroller.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

namespace s21 {

struct MazeCell {
  bool up_wall;
  bool down_wall;
  bool right_wall;
  bool left_wall;
};

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(MazeController controller, QWidget *parent = nullptr);
  ~MainWindow();
  void drawMaze(QGraphicsScene &scene,
                const std::vector<std::vector<MazeCell>> &grid);
  void draw();

 private:
  s21::MazeController controller_;
  Ui::MainWindow *ui_;
};

}  // namespace s21
#endif  // __MAZE_SOURCE_VIEW_MAINWINDOW_H__
