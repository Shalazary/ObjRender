#include "homogeneouscoordinatestools.h"

#include <QtMath>

QMatrix4x4 HomogeneousCoordinatesTools::lookAt(const QVector3D &eye, const QVector3D &center, const QVector3D &up)
{
    QVector3D forward = (eye - center).normalized();
    QVector3D right = QVector3D::normal(up, forward);
    QVector3D realUp = QVector3D::normal(forward, right);

    QMatrix4x4 rotation(
          right.x(),   right.y(),   right.z(), 0.0f,
         realUp.x(),  realUp.y(),  realUp.z(), 0.0f,
        forward.x(), forward.y(), forward.z(), 0.0f,
               0.0f,        0.0f,        0.0f, 1.0f);

    QMatrix4x4 translation(
        1.0f, 0.0f, 0.0f, -eye.x(),
        0.0f, 1.0f, 0.0f, -eye.y(),
        0.0f, 0.0f, 1.0f, -eye.z(),
        0.0f, 0.0f, 0.0f,    1.0f);

    return rotation * translation;
}

QMatrix4x4 HomogeneousCoordinatesTools::frustum(float left, float right, float bottom, float top, float near, float far)
{
    return QMatrix4x4(
        2 * near  / (right - left),                      0.0f, (right + left) / (right - left),                            0.0f,
                              0.0f, 2 * near / (top - bottom), (top + bottom) / (top - bottom),                            0.0f,
                              0.0f,                      0.0f,    -(far + near) / (far - near), - 2 * far * near / (far - near),
                              0.0f,                      0.0f,                           -1.0f,                            0.0f);
}

QMatrix4x4 HomogeneousCoordinatesTools::perspective(float fov, float aspectRatio, float near, float far)
{
    double right = qTan(fov / 2) * near;
    double top = right / aspectRatio;

    return QMatrix4x4(
        near / right,       0.0f,                         0.0f,                            0.0f,
                0.0f, near / top,                         0.0f,                            0.0f,
                0.0f,       0.0f, -(far + near) / (far - near), - 2 * far * near / (far - near),
                0.0f,       0.0f,                        -1.0f,                            0.0f);
}

QMatrix4x4 HomogeneousCoordinatesTools::orthographic(float left, float right, float bottom, float top, float near, float far)
{
    return QMatrix4x4(
        2.0f / (right - left),                  0.0f,                 0.0f, -(right + left) / (right - left),
                         0.0f, 2.0f / (top - bottom),                 0.0f, -(top + bottom) / (top - bottom),
                         0.0f,                  0.0f, -2.0f / (far - near),    - (far + near) / (far - near),
                         0.0f,                  0.0f,                 0.0f,                             1.0f);
}

QMatrix4x4 HomogeneousCoordinatesTools::viewport(int width, int height)
{
    return QMatrix4x4(
        (width - 1) / 2.0f,                 0.0f, 0.0f,  (width - 1) / 2.0f,
                      0.0f, -(height - 1) / 2.0f, 0.0f, (height - 1) / 2.0f,
                      0.0f,                 0.0f, 1.0f,                0.0f,
                      0.0f,                 0.0f, 0.0f,                1.0f);
}

QPoint HomogeneousCoordinatesTools::mapTexture(QVector2D texCoord, int width, int height)
{
    return QPoint(texCoord.x() * (width - 1) + 0.5f, -texCoord.y() * (height - 1) + (height - 1) + 0.5f);
}
