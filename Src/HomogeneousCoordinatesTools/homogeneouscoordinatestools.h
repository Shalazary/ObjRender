#ifndef HOMOGENEOUS_COORDINATES_TOOLS_H
#define HOMOGENEOUS_COORDINATES_TOOLS_H

#include <QMatrix4x4>
#include <QVector3D>

namespace HomogeneousCoordinatesTools {
QMatrix4x4 lookAt(const QVector3D &eye, const QVector3D &center, const QVector3D &up);
QMatrix4x4 frustum(float left, float right, float botttom, float top, float near, float far);
QMatrix4x4 perspective(float hFov, float aspectRatio, float near, float far);
QMatrix4x4 orthographic(float left, float right, float bottom, float top, float near, float far);
QMatrix4x4 viewport(int width, int height, int depth);
}

#endif
