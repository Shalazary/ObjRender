#include "camera.h"
#include "HomogeneousCoordinatesTools/homogeneouscoordinatestools.h"

Camera::Camera(float left, float right, float bottom, float top, float far, float near) :
    m_left(left),
    m_right(right),
    m_bottom(bottom),
    m_top(top),
    m_far(far),
    m_near(near)
{

}

Camera::Camera(float fov, float aspectRatio, float near, float far) :
    m_fov(fov),
    m_aspectRatio(aspectRatio),
    m_near(near),
    m_far(far)
{

}

QMatrix4x4 Camera::lookAt() const
{
    return HomogeneousCoordinatesTools::lookAt(m_pos, m_target, m_up);
}

QMatrix4x4 Camera::perspectiveProjection() const
{
    return HomogeneousCoordinatesTools::perspective(m_fov, m_aspectRatio, m_near, m_far);
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

float Camera::fov() const
{
    return m_fov;
}

void Camera::setFov(float fov)
{
    m_fov = fov;
}

float Camera::aspectRatio() const
{
    return m_aspectRatio;
}

void Camera::setAspectRatio(float aspectRatio)
{
    m_aspectRatio = aspectRatio;
}

