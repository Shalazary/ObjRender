#include "coordtransformationtools.h"



QMatrix4x4 CoordTransformationTools::lookAt(const QVector3D &cameraPosition, const QVector3D &cameraTarget, const QVector3D &up)
{
    return QMatrix4x4::lookAt(cameraPosition, cameraTarget, up);
}

QMatrix4x4 CoordTransformationTools::perspectiveProjection(loat verticalAngle, float aspectRatio, float near, float far)
{
    return QMatrix4x4::perspective(verticalAngle, aspectRatio, near, far);
}

QMatrix4x4 CoordTransformationTools::orthographicProjection(float left, float right, float bottom, float top, float near, float far)
{
    return QMatrix4x4::ortho(left, right, bottom, top, near,far);
}
