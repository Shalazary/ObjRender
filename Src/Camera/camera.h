#ifndef CAMERA_H
#define CAMERA_H

#include <QVector3D>
#include <QtMath>
#include <QMatrix4x4>

class Camera
{
public:
    Camera() = default;
    Camera(float left, float right, float bottom, float top, float far, float near);

    QMatrix4x4 modelView() const;
    QMatrix4x4 perspectiveProjection() const;
    QMatrix4x4 orthographicProjection() const;
private:
    QVector3D m_pos = {0, 0, -1};
    QVector3D m_target = {0, 0, 0};
    QVector3D m_up = {0, 1, 0};

    float m_left = -1;
    float m_right = 1;
    float m_bottom = -1;
    float m_top = 1;
    float m_near = -1;
    float m_far = 1;
};

#endif
