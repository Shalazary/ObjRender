#include "camera.h"

#include "HomogeneousCoordinatesTools/homogeneouscoordinatestools.h"

Camera::Camera(CameraMode mode) : m_mode(mode)
{

}

QMatrix4x4 Camera::projection() const
{
    QMatrix4x4 projectionMatrix;

    if(m_mode == CameraMode::Orthographic)
        projectionMatrix.ortho(m_left, m_right, m_bottom, m_top, m_near, m_far);
    else if(m_mode == CameraMode::Perspective)
        projectionMatrix.perspective(m_fov, m_aspectRatio, m_near, m_far);
    else if(m_mode == CameraMode::Frustum)
        projectionMatrix.frustum(m_left, m_right, m_bottom, m_top, m_near, m_far);

    return projectionMatrix;
}

QMatrix4x4 Camera::view() const
{
    QMatrix4x4 transform;

    transform.translate(m_target);
    transform.rotate(m_rotation);
    transform.translate(m_origin);

    return transform.inverted();
}

QVector3D Camera::origin() const
{
    return m_origin;
}

void Camera::setOrigin(const QVector3D &origin)
{
    m_origin = origin;
}

void Camera::setOrigin(float x, float y, float z)
{
    m_origin = {x, y, z};
}

QQuaternion Camera::rotation() const
{
    return m_rotation;
}

void Camera::setRotation(const QQuaternion &rotation)
{
    m_rotation = rotation;
}

void Camera::setRotation(float scalar, const QVector3D &vector)
{
    m_rotation = QQuaternion(scalar, vector);
}

void Camera::setRotation(float scalar, float x, float y, float z)
{
    m_rotation = QQuaternion(scalar, x, y, z);
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

void Camera::setFov(float fovAngle)
{
    m_fov = fovAngle;
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





