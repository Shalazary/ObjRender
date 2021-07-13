#include "camera.h"

Camera::Camera(float left, float right, float bottom, float top, float far, float near) :
    m_left(left),
    m_right(right),
    m_bottom(bottom),
    m_top(top),
    m_far(far),
    m_near(near)
{

}

QMatrix4x4 Camera::modelView() const
{
    /*
    QVector3D direction = (m_pos - m_target).normalized();
    QVector3D right = QVector3D::crossProduct(direction, m_up).normalized();
    QVector3D up = QVector3D::crossProduct(right, direction);
    QMatrix4x4 m(
        right.x(), up.x(), direction.x(), -m_target.x(),
        right.y(), up.y(), direction.y(), -m_target.y(),
        right.z(), up.z(), direction.z(), -m_target.z(),
                0,      0,             0,             1);

    */
    QMatrix4x4 m;
    m.lookAt(m_pos, m_target, -m_up);
    return m;
}

QMatrix4x4 Camera::perspectiveProjection() const
{
    QMatrix4x4 m;
    m.frustum(m_left, m_right, m_bottom, m_top, m_near, m_far);

    /*
    QMatrix4x4 m(
        2 * m_near / (m_right - m_left),                                0,  (m_right + m_left) / (m_right - m_left),                                    0,
                                       0, 2 * m_near / (m_top - m_bottom),  (m_top + m_bottom) / (m_top - m_bottom),                                    0,
                                       0,                               0,     -(m_far + m_near) / (m_far - m_near),   - m_far * m_near / (m_far - m_near),
                                       0,                               0,                                       -1,                                    0);
                                       */
    return m;
}

QMatrix4x4 Camera::orthographicProjection() const
{

}

QVector3D Camera::pos() const
{
    return m_pos;
}

void Camera::setPos(const QVector3D &pos)
{
    m_pos = pos;
}

QVector3D Camera::target() const
{
    return m_target;
}

void Camera::setTarget(const QVector3D &target)
{
    m_target = target;
}

QVector3D Camera::up() const
{
    return m_up;
}

void Camera::setUp(const QVector3D &up)
{
    m_up = up;
}

float Camera::left() const
{
    return m_left;
}

void Camera::setLeft(float left)
{
    m_left = left;
}

float Camera::right() const
{
    return m_right;
}

void Camera::setRight(float right)
{
    m_right = right;
}

float Camera::bottom() const
{
    return m_bottom;
}

void Camera::setBottom(float bottom)
{
    m_bottom = bottom;
}

float Camera::top() const
{
    return m_top;
}

void Camera::setTop(float top)
{
    m_top = top;
}

float Camera::near() const
{
    return m_near;
}

void Camera::setNear(float near)
{
    m_near = near;
}

float Camera::far() const
{
    return m_far;
}

void Camera::setFar(float far)
{
    m_far = far;
}

