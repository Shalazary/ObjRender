#ifndef COORD_TRANSFORMATION_TOOLS_H
#define COORD_TRANSFORMATION_TOOLS_H

#include <QMatrix4x4>

namespace CoordTransformationTools {
QMatrix4x4 lookAt(const QVector3D &cameraPosition, const QVector3D &cameraTarget, const QVector3D &up);
QMatrix4x4 perspectiveProjection(float left, float right, float bottom, float top, float near, float far);
QMatrix4x4 orthographicProjection(float left, float right, float bottom, float top, float near, float far);
}

#endif
