#include <QDebug>
#include <QGraphicsRectItem>

#include "./ui_mainwindow.h"
#include "mainwindow.h"
#include "mazegenerator.h"

namespace s21 {

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  connect(ui->button_generate, &QPushButton::clicked, this, &MainWindow::draw);
}

void MainWindow::drawCell(QGraphicsScene &scene, const Cell &cell, qreal x1,
                          qreal y1, qreal x2, qreal y2) {
  if (cell.isFilled()) {
    QGraphicsRectItem *rect = new QGraphicsRectItem(x1, y1, x2, y2);
    rect->setBrush(QBrush(Qt::black));
    scene.addItem(rect);
  } else {
    if (cell.up_wall) {
      QGraphicsLineItem *up_wall = new QGraphicsLineItem(x1, y1, x2, y1);
      scene.addItem(up_wall);
    }
    if (cell.down_wall) {
      QGraphicsLineItem *down_wall = new QGraphicsLineItem(x1, y2, x2, y2);
      scene.addItem(down_wall);
    }
    if (cell.left_wall) {
      QGraphicsLineItem *left_wall = new QGraphicsLineItem(x1, y1, x1, y2);
      scene.addItem(left_wall);
    }
    if (cell.right_wall) {
      QGraphicsLineItem *right_wall = new QGraphicsLineItem(x2, y1, x2, y2);
      scene.addItem(right_wall);
    }
  }
}

void MainWindow::drawMaze(QGraphicsScene &scene, const Maze &maze) {
  QRectF scene_rect = scene.sceneRect();
  size_t M = maze.getM();
  size_t N = maze.getN();

  std::vector<std::vector<Cell>> grid = maze.getGrid();

  int cell_height = scene_rect.height() / M;
  int cell_width = scene_rect.width() / N;

  int line_width = 1;

  for (size_t row = 0; row < M; row++) {
    for (size_t col = 0; col < N; col++) {
      qreal y1 = row * cell_height + line_width;
      qreal y2 = (row + 1) * cell_height + line_width;

      qreal x1 = col * cell_width + line_width;
      qreal x2 = (col + 1) * cell_width + line_width;

      qDebug() << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
      qDebug() << col << " " << row << " "
               << "\n";

      drawCell(scene, grid[row][col], x1, y1, x2, y2);
    }
  }
}

void MainWindow::draw() {
  MazeGenerator g;
  Maze test = g.generateMaze(30, 30);

  QGraphicsScene *scene = new QGraphicsScene;
  scene->setSceneRect(0, 0, 500, 500);

  drawMaze(*scene, test);

  ui->view_screen->setScene(scene);
}

MainWindow::~MainWindow() { delete ui; }

}  // namespace s21
