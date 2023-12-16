#include <QApplication>

#include "adapter.h"
#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  s21::Adapter adapter;
  s21::MainWindow w(adapter);

  w.show();
  return a.exec();
}
