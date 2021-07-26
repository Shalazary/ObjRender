#include "camera.h"
#include "HomogeneousCoordinatesTools/homogeneouscoordinatestools.h"



Camera::Camera(CameraMode mode) : m_mode(mode)
{

}

QMatrix4x4 Camera::projection() const
{
    if(m_mode == CameraMode::Orthographic)
        return HomogeneousCoordinatesTools::orthographic(m_left, m_right, m_bottom, m_top, m_near, m_far);
    else if(m_mode == CameraMode::Perspective)
        return HomogeneousCoordinatesTools::perspective(m_fov, m_aspectRatio, m_near, m_far);
    else if(m_mode == CameraMode::Frustum)
        return HomogeneousCoordinatesTools::frustum(m_left, m_right, m_bottom, m_top, m_near, m_far);
}

QMatrix4x4 Camera::view() const
{
    return HomogeneousCoordinatesTools::lookAt(m_pos, m_target, m_up);
}

QVector3D Camera::pos() const
{
    return m_pos;
}

void Camera::setPos(const QVector3D &pos)
{
    m_pos = pos;
}

void Camera::setPos(float x, float y, float z)
{
    m_pos = {x, y, z};
}

QVector3D Camera::target() const
{
    return m_target;
}

void Camera::setTarget(const QVector3D &target)
{
    m_target = target;
}

void Camera::setTarget(float x, float y, float z)
{
    m_target = {x, y, z};
}

QVector3D Camera::up() const
{
    return m_up;
}

void Camera::setUp(const QVector3D &up)
{
    m_up = up;
}

void Camera::setUp(float x, float y, float z)
{
    m_up = {x, y, z};
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

CameraMode Camera::mode() const
{
    return m_mode;
}

void Camera::setMode(const CameraMode &mode)
{
    m_mode = mode;
}

