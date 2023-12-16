#ifndef __MAZE_SOURCE_VIEW_MAINWINDOW_H__
#define __MAZE_SOURCE_VIEW_MAINWINDOW_H__

#include <QGraphicsScene>
#include <QMainWindow>
#include <vector>

#include "adapter.h"
#include "mazecell.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

namespace s21 {

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(Adapter adapter, QWidget *parent = nullptr);
  ~MainWindow();
  void drawMaze(QGraphicsScene &scene,
                const std::vector<std::vector<MazeCell>> &grid);
  void draw();

 private:
  s21::Adapter adapter_;
  Ui::MainWindow *ui_;
};

}  // namespace s21
#endif  // __MAZE_SOURCE_VIEW_MAINWINDOW_H__
