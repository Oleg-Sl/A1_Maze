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
  ui_->spin_start_x->setMaximum(kMaxMazeCols);
  ui_->spin_end_x->setMaximum(kMaxMazeCols);
  ui_->spin_start_y->setMaximum(kMaxMazeRows);
  ui_->spin_end_y->setMaximum(kMaxMazeRows);

  scene_.setSceneRect(ui_->view_screen->rect().adjusted(0, 0, -2, -2));
  ui_->view_screen->setScene(&scene_);

  connect(ui_->button_generate, &QPushButton::clicked, this,
          &MainWindow::generateMaze);
  connect(ui_->button_generate, &QPushButton::clicked, this,
          &MainWindow::drawMaze);
  connect(ui_->button_build_path, &QPushButton::clicked, this,
          &MainWindow::drawSolution);
  connect(ui_->button_import, &QPushButton::clicked, this,
          &MainWindow::importMazeFile);
  connect(ui_->button_import, &QPushButton::clicked, this,
          &MainWindow::drawMaze);
  connect(ui_->button_export, &QPushButton::clicked, this,
          &MainWindow::exportMazeFile);
}

void MainWindow::addMazeOnScene(QGraphicsScene &scene,
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

void MainWindow::clearSolution(QGraphicsScene &scene) {
  QList<QGraphicsItem *> items = scene.items();

  for (QGraphicsItem *item : items) {
    if (item->type() == QGraphicsLineItem::Type) {
      scene.removeItem(item);
    }
  }
}

std::vector<Point2D> MainWindow::generateSolutionForScene(
    const QGraphicsScene &scene, const std::vector<std::vector<Cell>> &maze,
    Point2D start, Point2D end) {
  std::vector<Point2D> path;

  if (maze.size() == 0 || maze[0].size() == 0) {
    return path;
  }

  path = adapter_.solutionMaze(maze, {start.x, start.y}, {end.x, end.y});

  qreal cell_height = scene.sceneRect().height() / maze.size();
  qreal cell_width = scene.sceneRect().width() / maze[0].size();

  for (Point2D &point : path) {
    point.x = point.x * cell_width + cell_width / 2;
    point.y = point.y * cell_height + cell_height / 2;
  }

  return path;
}

void MainWindow::addSolutionOnScene(QGraphicsScene &scene,
                                    const std::vector<Point2D> &solution) {
  if (solution.size() <= 1) {
    return;
  }

  for (size_t i = 0; i < solution.size() - 1; i++) {
    Point2D start = solution[i];
    Point2D end = solution[i + 1];

    QGraphicsLineItem *line =
        new QGraphicsLineItem(start.x, start.y, end.x, end.y);

    line->setPen(QPen(kSolutionLineColor, kSolutionLineWidth));

    scene.addItem(line);
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
}

void MainWindow::drawMaze() {
  scene_.clear();
  addMazeOnScene(scene_, maze_);
}

void MainWindow::drawSolution() {
  int x1 = ui_->spin_start_x->value() - 1;
  int x2 = ui_->spin_end_x->value() - 1;
  int y1 = ui_->spin_start_y->value() - 1;
  int y2 = ui_->spin_end_y->value() - 1;

  clearSolution(scene_);
  std::vector<Point2D> path =
      generateSolutionForScene(scene_, maze_, {x1, y1}, {x2, y2});
  addSolutionOnScene(scene_, path);
}

void MainWindow::importMazeFile() {
  std::string filename =
      QFileDialog::getOpenFileName(this, "Open File", "./", tr("*.txt"))
          .toStdString();

  maze_ = adapter_.loadMazeFromFile(filename);
}

void MainWindow::exportMazeFile() {
  std::string filename =
      QFileDialog::getSaveFileName(this, "Save maze", "./", tr("*.txt"))
          .toStdString();

  adapter_.saveMazeFile(maze_, filename);
}

MainWindow::~MainWindow() { delete ui_; }

}  // namespace s21
