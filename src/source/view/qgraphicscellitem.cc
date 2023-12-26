#include "qgraphicscellitem.h"

#include <QBrush>

namespace s21 {

QGraphicsCellItem::QGraphicsCellItem(QGraphicsItem* parent)
    : QGraphicsItem(parent) {}
QGraphicsCellItem::QGraphicsCellItem(qreal x1, qreal y1, qreal x2, qreal y2,
                                     QGraphicsItem* parent)
    : QGraphicsItem(parent), x1_(x1), y1_(y1), x2_(x2), y2_(y2) {}

QRectF QGraphicsCellItem::boundingRect() const {
  return QRectF(x1_, y1_, x2_, y2_);
}

void QGraphicsCellItem::paint(QPainter* painter,
                              const QStyleOptionGraphicsItem* option,
                              QWidget* widget) {
  Q_UNUSED(option);
  Q_UNUSED(widget);

  painter->setPen(QPen(color_, border_width_));

  if (filled_) {
    painter->fillRect(x1_, y1_, x2_, y2_, color_);
  } else {
    if (up_border_) {
      painter->drawLine(x1_, y1_, x2_, y1_);
    }
    if (down_border_) {
      painter->drawLine(x1_, y2_, x2_, y2_);
    }
    if (left_border_) {
      painter->drawLine(x1_, y1_, x1_, y2_);
    }
    if (right_border_) {
      painter->drawLine(x2_, y1_, x2_, y2_);
    }
  }
}

void QGraphicsCellItem::setBorderUp(bool show) { up_border_ = show; }
void QGraphicsCellItem::setBorderDown(bool show) { down_border_ = show; }
void QGraphicsCellItem::setBorderLeft(bool show) { left_border_ = show; }
void QGraphicsCellItem::setBorderRight(bool show) { right_border_ = show; }

void QGraphicsCellItem::setFilled(bool filled) { filled_ = filled; }
void QGraphicsCellItem::setBorderWidth(int width) { border_width_ = width; }
void QGraphicsCellItem::setColor(QColor color) { color_ = color; }

}  // namespace s21
