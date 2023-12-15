#include <QApplication>

#include "mainwindow.h"
#include "mazecontroller.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  s21::MazeController controller;
  s21::MainWindow w(controller);

  w.show();
  return a.exec();
}
