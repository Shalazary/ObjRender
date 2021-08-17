#ifndef SHAPE_DRAWING_TOOLS_H
#define SHAPE_DRAWING_TOOLS_H

#include <QPoint>
#include <QVector3D>
#include <QVector4D>
#include <QImage>
#include <QColor>

#include "AbstractPixelColorGetter/abstract_pixel_color_getter.h"
#include "Array2D/array2d.h"

namespace ShapeDrawingTools {

void drawLine(QImage &image, const QPoint &p1, const QPoint &p2, const QColor &color = QColor("white"));
void drawLine(QImage &image, int x1, int y1, int x2, int y2, const QColor &color = QColor("white"));
void drawLine(QImage &image, int x1, int y1, int z1, int x2, int y2, int z2, int **zbuffer, const QColor &color = QColor("white"));

void drawTriangle(
    QImage &image,
    Array2D::Array2D<float> &zbuffer,
    const QVector4D &v1,
    const QVector4D &v2,
    const QVector4D &v3,
    DrawingTools::AbstractPixelColorGetter *colorGetter);

}

#endif
