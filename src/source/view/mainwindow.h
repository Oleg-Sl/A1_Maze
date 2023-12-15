#ifndef __MAZE_SOURCE_VIEW_MAINWINDOW_H__
#define __MAZE_SOURCE_VIEW_MAINWINDOW_H__

#include <QGraphicsScene>
#include <QMainWindow>

#include "maze.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

namespace s21 {

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  void drawMaze(QGraphicsScene &scene, const Maze &maze);
  void drawCell(QGraphicsScene &scene, const Cell &cell, qreal x, qreal y,
                qreal x1, qreal y1);
  void draw();

 private:
  Ui::MainWindow *ui;
};

}  // namespace s21
#endif  // __MAZE_SOURCE_VIEW_MAINWINDOW_H__
