#include <QDebug>
#include <QFileDialog>
#include <QGraphicsRectItem>
#include <QString>

#include "./ui_mainwindow.h"
#include "mainwindow.h"
#include "qgraphicscellitem.h"

namespace s21 {

MainWindow::MainWindow(Adapter adapter, QWidget *parent)
    : QMainWindow(parent), adapter_(adapter), ui_(new Ui::MainWindow) {
  ui_->setupUi(this);

  ui_->spin_cols->setMaximum(kMaxMazeCols);
  ui_->spin_rows->setMaximum(kMaxMazeRows);
  ui_->spin_end_x->setMaximum(kMaxMazeCols);
  ui_->spin_end_y->setMaximum(kMaxMazeCols);

  connect(ui_->button_generate, &QPushButton::clicked, this,
          &MainWindow::generateMaze);
  connect(ui_->button_build_path, &QPushButton::clicked, this,
          &MainWindow::drawSolution);
  connect(ui_->button_import, &QPushButton::clicked, this,
          &MainWindow::importMazeFile);
  connect(ui_->button_export, &QPushButton::clicked, this,
          &MainWindow::exportMazeFile);
}

void MainWindow::drawMaze(QGraphicsScene &scene,
                          const std::vector<std::vector<Cell>> &maze) {
  if (maze.size() == 0 || maze[0].size() == 0) {
    return;
  }
  
  QRectF scene_rect = scene.sceneRect();
  size_t rows = maze.size();
  size_t cols = maze[0].size();

  qreal cell_height = scene_rect.height() / rows;
  qreal cell_width = scene_rect.width() / cols;

  for (size_t row = 0; row < rows; row++) {
    for (size_t col = 0; col < cols; col++) {
      qreal x1 = col * cell_width;
      qreal y1 = row * cell_height;

      qreal x2 = (col + 1) * cell_width;
      qreal y2 = (row + 1) * cell_height;

      QGraphicsCellItem *cell = new QGraphicsCellItem(x1, y1, x2, y2);

      cell->setBorderDown(maze[row][col].down_wall);
      cell->setBorderLeft(maze[row][col].left_wall);
      cell->setBorderRight(maze[row][col].right_wall);
      cell->setBorderUp(maze[row][col].up_wall);

      cell->setBorderWidth(kCellBorderWidth);

      scene.addItem(cell);
    }
  }
}

void MainWindow::drawSolution() {
  QGraphicsScene *scene = ui_->view_screen->scene();

  int x1 = ui_->spin_start_x->value() - 1;
  int y1 = ui_->spin_start_y->value() - 1;
  int x2 = ui_->spin_end_x->value() - 1;
  int y2 = ui_->spin_end_y->value() - 1;

  std::vector<Point2D> path = adapter_.solutionMaze(maze_, {x1, y1}, {x2, y2});

  if (path.size() <= 1) {
    return;
  }

  QRectF scene_rect = scene->sceneRect();
  size_t M = maze_.size();
  size_t N = maze_[0].size();

  qreal cell_height = scene_rect.height() / M;
  qreal cell_width = scene_rect.width() / N;

  for (size_t i = 0; i < path.size() - 1; i++) {
    Point2D start = path[i];
    Point2D end = path[i + 1];

    int x = (start.x * cell_width) + cell_width / 2;
    int y = (start.y * cell_height) + cell_height / 2;

    int x2 = (end.x * cell_width) + cell_width / 2;
    int y2 = (end.y * cell_height) + cell_height / 2;

    QGraphicsLineItem *line = new QGraphicsLineItem(x, y, x2, y2);

    line->setPen(QPen(kSolutionLineColor, kSolutionLineWidth));

    scene->addItem(line);
  }
}

void MainWindow::generateMaze() {
  size_t rows = ui_->spin_rows->value();
  size_t cols = ui_->spin_cols->value();
  maze_ = adapter_.generateMaze(rows, cols);

  ui_->spin_end_x->setRange(1, cols);
  ui_->spin_end_y->setRange(1, rows);
  ui_->spin_end_x->setValue(cols);
  ui_->spin_end_y->setValue(rows);

  draw();
}

void MainWindow::draw() {
  QGraphicsScene *scene = new QGraphicsScene();
  scene->setSceneRect(ui_->view_screen->rect().adjusted(0, 0, -2, -2));

  drawMaze(*scene, maze_);

  ui_->view_screen->setScene(scene);
}

void MainWindow::importMazeFile() {
  std::string filename =
      QFileDialog::getOpenFileName(this, "Open File", "./", tr("*.txt"))
          .toStdString();

  maze_ = adapter_.loadMazeFromFile(filename);
  draw();
}

void MainWindow::exportMazeFile() {
  std::string filename =
      QFileDialog::getSaveFileName(this, "Save maze", "./", tr("*.txt"))
          .toStdString();

  adapter_.saveMazeFile(maze_, filename);
}

MainWindow::~MainWindow() { delete ui_; }

}  // namespace s21
