#include "camera.h"

Camera::Camera::Camera(Mode mode) : m_mode(mode)
{

}

QMatrix4x4 Camera::Camera::projection() const
{
    QMatrix4x4 projectionMatrix;

    if(m_mode == Mode::Orthographic)
        projectionMatrix.ortho(m_left, m_right, m_bottom, m_top, m_near, m_far);
    else if(m_mode == Mode::Perspective)
        projectionMatrix.perspective(m_fov, m_aspectRatio, m_near, m_far);
    else if(m_mode == Mode::Frustum)
        projectionMatrix.frustum(m_left, m_right, m_bottom, m_top, m_near, m_far);
    else
        Q_ASSERT_X(false, "projection", "unknown camera mode");

    return projectionMatrix;
}

QMatrix4x4 Camera::Camera::view() const
{
    QMatrix4x4 transform;

    transform.translate(m_target);
    transform.rotate(m_rotation);
    transform.translate(m_origin);

    return transform.inverted();
}

QVector3D Camera::Camera::origin() const
{
    return m_origin;
}

void Camera::Camera::setOrigin(const QVector3D &origin)
{
    m_origin = origin;
}

void Camera::Camera::setOrigin(float x, float y, float z)
{
    m_origin = {x, y, z};
}

QQuaternion Camera::Camera::rotation() const
{
    return m_rotation;
}

void Camera::Camera::setRotation(const QQuaternion &rotation)
{
    m_rotation = rotation;
}

void Camera::Camera::setRotation(float scalar, const QVector3D &vector)
{
    m_rotation = QQuaternion(scalar, vector);
}

void Camera::Camera::setRotation(float scalar, float x, float y, float z)
{
    m_rotation = QQuaternion(scalar, x, y, z);
}

QVector3D Camera::Camera::target() const
{
    return m_target;
}

void Camera::Camera::setTarget(const QVector3D &target)
{
    m_target = target;
}

void Camera::Camera::setTarget(float x, float y, float z)
{
    m_target = {x, y, z};
}

float Camera::Camera::near() const
{
    return m_near;
}

void Camera::Camera::setNear(float near)
{
    m_near = near;
}

float Camera::Camera::far() const
{
    return m_far;
}

void Camera::Camera::setFar(float far)
{
    m_far = far;
}

float Camera::Camera::fov() const
{
    return m_fov;
}

void Camera::Camera::setFov(float fovAngle)
{
    m_fov = fovAngle;
}

float Camera::Camera::aspectRatio() const
{
    return m_aspectRatio;
}

void Camera::Camera::setAspectRatio(float aspectRatio)
{
    m_aspectRatio = aspectRatio;
}

Camera::Mode Camera::Camera::mode() const
{
    return m_mode;
}

void Camera::Camera::setMode(const Mode &mode)
{
    m_mode = mode;
}





