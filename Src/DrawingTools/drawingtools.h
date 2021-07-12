#ifndef DRAWINGTOOLS_H
#define DRAWINGTOOLS_H

#include <QPoint>
#include <QVector3D>
#include <QImage>
#include <QColor>

namespace DrawingTools {
void drawLine(QImage &image, QPoint p1, QPoint p2, QColor color = QColor("white"));
void drawLine(QImage &image, int x1, int y1, int x2, int y2, QColor color = QColor("white"));
void drawTriangel(QImage &image, QPoint p1, QPoint p2, QPoint p3, QColor color = QColor("white"));
}
namespace NDCDrawingTools {
void drawLine(QImage &image, QVector3D p1, QVector3D p2, int **zbuffer, QColor color = QColor("white"), int zbufferDepth = 255);
void drawTriangel(QImage &image, QVector3D p1, QVector3D p2, QVector3D p3, int **zbuffer, QColor color = QColor("white"), int zbufferDepth = 255);
}

#endif // DRAWINGTOOLS_H
