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

void MainWindow::draw() {
  QGraphicsScene *scene = new QGraphicsScene;
  scene->setSceneRect(0, 0, 500, 500);

  size_t rows = ui_->spin_rows->value();
  size_t cols = ui_->spin_cols->value();

  std::vector<std::vector<MazeCell>> maze = adapter_.generateMaze(rows, cols);

  drawMaze(*scene, maze);

  ui_->view_screen->setScene(scene);
}

MainWindow::~MainWindow() { delete ui_; }

}  // namespace s21
