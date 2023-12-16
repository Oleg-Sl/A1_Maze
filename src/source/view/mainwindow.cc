#include <QDebug>
#include <QGraphicsRectItem>

#include "./ui_mainwindow.h"
#include "mainwindow.h"
#include "qgraphicscellitem.h"

namespace s21 {

MainWindow::MainWindow(MazeController controller, QWidget *parent)
    : QMainWindow(parent), controller_(controller), ui_(new Ui::MainWindow) {
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
  size_t rows = ui_->spin_rows->value();
  size_t cols = ui_->spin_cols->value();
  Maze maze = controller_.generateMaze(rows, cols);

  QGraphicsScene *scene = new QGraphicsScene;
  scene->setSceneRect(0, 0, 500, 500);

  auto grid = maze.getGrid();
  std::vector<std::vector<MazeCell>> view_grid(
      maze.getM(), std::vector<MazeCell>(maze.getN(), {0, 0, 0, 0}));

  for (size_t i = 0; i < maze.getM(); i++) {
    for (size_t j = 0; j < maze.getN(); j++) {
      bool down = grid[i][j].down_wall;
      bool up = grid[i][j].up_wall;
      bool left = grid[i][j].left_wall;
      bool right = grid[i][j].right_wall;
      view_grid[i][j] = {up, down, right, left};
    }
  }

  drawMaze(*scene, view_grid);

  ui_->view_screen->setScene(scene);
}

MainWindow::~MainWindow() { delete ui_; }

}  // namespace s21
