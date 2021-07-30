#ifndef DRAWINGTOOLS_H
#define DRAWINGTOOLS_H

#include <QPoint>
#include <QVector3D>
#include <QVector4D>
#include <QImage>
#include <QColor>

#include "Point3D/point3d.h"

namespace DrawingTools {
void drawLine(QImage &image, QPoint p1, QPoint p2, QColor color = QColor("white"));
void drawLine(QImage &image, int x1, int y1, int x2, int y2, QColor color = QColor("white"));

void drawLine(QImage &image, Point3D p1, Point3D p2, int **zbuffer, QColor color = QColor("white"));
void drawLine(QImage &image, int x1, int y1, int z1, int x2, int y2, int z2, int **zbuffer, QColor color = QColor("white"));

void drawTriangel(
    QImage &image,
    const QVector4D &v1, const QVector4D &v2, const QVector4D &v3,
    const QVector2D &vt1, const QVector2D &vt2, const QVector2D &vt3,
    const QVector3D &vn1, const QVector3D &vn2, const QVector3D &vn3,
    const QVector3D &lightDirection,
    const QImage &texture,
    float **zbuffer
);
void drawTriangel(
    QImage &image,
    const QVector4D &v1, const QVector4D &v2, const QVector4D &v3,
    const QVector2D &vt1, const QVector2D &vt2, const QVector2D &vt3,
    const QImage &texture,
    float **zbuffer
);
void drawTriangel(
    QImage &image,
    const QVector4D &v1, const QVector4D &v2, const QVector4D &v3,
    const QVector3D &vn1, const QVector3D &vn2, const QVector3D &vn3,
    const QVector3D &lightDirection,
    const QColor &color,
    float **zbuffer
);
void drawTriangel(
    QImage &image,
    const QVector4D &v1, const QVector4D &v2, const QVector4D &v3,
    const QColor &color,
    float **zbuffer
);
}

#endif // DRAWINGTOOLS_H
