#include <QDebug>
#include <QGraphicsRectItem>

#include "./ui_mainwindow.h"
#include "mainwindow.h"
#include "qgraphicscellitem.h"

namespace s21 {

MainWindow::MainWindow(Adapter adapter, QWidget *parent)
    : QMainWindow(parent), adapter_(adapter), ui_(new Ui::MainWindow) {
  ui_->setupUi(this);

  connect(ui_->button_generate, &QPushButton::clicked, this, &MainWindow::draw);
  connect(ui_->button_build_path, &QPushButton::clicked, this,
          &MainWindow::drawSolution);
}

void MainWindow::drawMaze(QGraphicsScene &scene,
                          const std::vector<std::vector<MazeCell>> &grid) {
  QRectF scene_rect = scene.sceneRect();
  size_t M = grid.size();
  size_t N = M == 0 ? 0 : grid[0].size();

  qreal cell_height = scene_rect.height() / M;
  qreal cell_width = scene_rect.width() / N;

  int line_width = 0;

  for (size_t row = 0; row < M; row++) {
    for (size_t col = 0; col < N; col++) {
      qreal y1 = row * cell_height + line_width;
      qreal y2 = (row + 1) * cell_height + line_width;

      qreal x1 = col * cell_width + line_width;
      qreal x2 = (col + 1) * cell_width + line_width;

      QGraphicsCellItem *cell = new QGraphicsCellItem(x1, y1, x2, y2);
      cell->setBorderDown(grid[row][col].down_wall);
      cell->setBorderLeft(grid[row][col].left_wall);
      cell->setBorderRight(grid[row][col].right_wall);
      cell->setBorderUp(grid[row][col].up_wall);

      scene.addItem(cell);
    }
  }
}

void MainWindow::drawSolution() {
  QGraphicsScene *scene = ui_->view_screen->scene();

  int x1, x2, y1, y2;

  x1 = ui_->spin_start_x->value();
  y1 = ui_->spin_start_y->value();
  x2 = ui_->spin_end_x->value();
  y2 = ui_->spin_end_y->value();

  std::vector<std::pair<int, int>> path =
      adapter_.solutionMaze(maze_, x1, y1, x2, y2);

  QRectF scene_rect = scene->sceneRect();
  size_t M = maze_.size();
  size_t N = maze_[0].size();

  qreal cell_height = scene_rect.height() / M;
  qreal cell_width = scene_rect.width() / N;

  for (size_t i = 0; i < path.size() - 1; i++) {
    std::pair<int, int> point_start = path[i];
    std::pair<int, int> point_end = path[i + 1];

    int y = (point_start.first * cell_height) + cell_height / 2;
    int x = (point_start.second * cell_width) + cell_width / 2;

    int y2 = (point_end.first * cell_height) + cell_height / 2;
    int x2 = (point_end.second * cell_width) + cell_width / 2;

    QGraphicsLineItem *line = new QGraphicsLineItem(x, y, x2, y2);
    QPen newPen(Qt::green);

    line->setPen(newPen);

    scene->addItem(line);
  }
}

void MainWindow::draw() {
  QGraphicsScene *scene = new QGraphicsScene;
  scene->setSceneRect(0, 0, 500, 500);

  size_t rows = ui_->spin_rows->value();
  size_t cols = ui_->spin_cols->value();

  maze_ = adapter_.generateMaze(rows, cols);

  drawMaze(*scene, maze_);

  ui_->view_screen->setScene(scene);
}

MainWindow::~MainWindow() { delete ui_; }

}  // namespace s21
