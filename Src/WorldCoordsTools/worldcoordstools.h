#ifndef WORLD_COORDS_TOOLS_H
#define WORLD_COORDS_TOOLS_H

#include <QVector3D>
#include <QSize>

namespace WorldCoordsTools {
int worldToScreanX(float x, float left, float right, int width);
int worldToScreanY(float y, float bottom, float top, int height);
int worldToScreanZ(float z, float near, float far, int depth);
QVector3D worldToScrean(QVector3D p, float left, float right, float bottom, float top, float near, float far, int width, int height, int depth);
QVector3D worldToScrean(QVector3D p, float left, float right, float bottom, float top, float near, float far, QSize windowSize, int depth);
QVector3D worldNDCToScrean(QVector3D p, int width, int hight, int depth);
QVector3D worldNDCToScrean(QVector3D p, QSize windowSize, int depth);
QPoint worldNDCToScrean(QVector3D p, QSize windowSize);
}

#endif
