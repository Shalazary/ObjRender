#ifndef HOMOGENEOUS_COORDINATES_TOOLS_H
#define HOMOGENEOUS_COORDINATES_TOOLS_H

#include <QMatrix4x4>
#include <QVector2D>
#include <QVector3D>
#include <QPoint>
#include <QSize>

namespace HomogeneousCoordinatesTools {

QMatrix4x4 lookAt(const QVector3D &eye, const QVector3D &center, const QVector3D &up);
QMatrix4x4 frustum(float left, float right, float botttom, float top, float near, float far);
QMatrix4x4 perspective(float hFov, float aspectRatio, float near, float far);
QMatrix4x4 orthographic(float left, float right, float bottom, float top, float near, float far);
QMatrix4x4 viewport(int width, int height);

QVector2D projectToScreenPixelCoordinates(const QVector4D &NDCCoord, int width, int height);
QVector2D projectToScreenPixelCoordinates(const QVector4D &NDCCoord, const QSize &size);

QVector2D projectToTexturePixelCoordinates(const QVector2D &texCoord, int width, int height);
QVector2D projectToTexturePixelCoordinates(const QVector2D &texCoord, const QSize &size);

}

#endif
