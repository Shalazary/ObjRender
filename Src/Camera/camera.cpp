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
    QMatrix4x4 m;
    m.lookAt(m_pos, m_target, m_up);
    return m;
}

QMatrix4x4 Camera::perspectiveProjection() const
{
    QMatrix4x4 m;
    m.frustum(m_left, m_right, m_bottom, m_top, m_near, m_far);
    return m;
}

QMatrix4x4 Camera::orthographicProjection() const
{

}

