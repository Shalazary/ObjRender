#ifndef DRAWINGTOOLS_H
#define DRAWINGTOOLS_H

#include <QPoint>
#include <QVector3D>
#include <QImage>
#include <QColor>

#include "Point3D/point3d.h"

namespace DrawingTools {
void drawLine(QImage &image, QPoint p1, QPoint p2, QColor color = QColor("white"));
void drawLine(QImage &image, int x1, int y1, int x2, int y2, QColor color = QColor("white"));

void drawLine(QImage &image, Point3D p1, Point3D p2, int **zbuffer, QColor color = QColor("white"));
void drawLine(QImage &image, int x1, int y1, int z1, int x2, int y2, int z2, int **zbuffer, QColor color = QColor("white"));

void drawTriangel(QImage &image, QPoint p1, QPoint p2, QPoint p3, QColor color = QColor("white"));
void drawTriangel(QImage &image, Point3D p1, Point3D p2, Point3D p3, int **zbuffer, QColor color = QColor("white"));
}

#endif // DRAWINGTOOLS_H
