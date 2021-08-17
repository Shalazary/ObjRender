#ifndef CAMERA_H
#define CAMERA_H

#include <QVector3D>
#include <QtMath>
#include <QMatrix4x4>

namespace Camera {

enum class Mode
{
    Orthographic,
    Perspective,
    Frustum
};

class Camera
{
public:
    Camera() = default;
    Camera(Mode mode);

    QMatrix4x4 view() const;
    QMatrix4x4 projection() const;

    Mode mode() const;
    void setMode(const Mode &mode);

    QVector3D origin() const;
    void setOrigin(const QVector3D &origin);
    void setOrigin(float x, float y, float z);


    QVector3D target() const;
    void setTarget(const QVector3D &target);
    void setTarget(float x, float y, float z);

    float near() const;
    void setNear(float near);

    float far() const;
    void setFar(float far);

    float fov() const;
    void setFov(float fov);

    float aspectRatio() const;
    void setAspectRatio(float aspectRatio);

    QQuaternion rotation() const;
    void setRotation(const QQuaternion &rotation);
    void setRotation(float scalar, const QVector3D &vector);
    void setRotation(float scalar, float x, float y, float z);

private:
    Mode m_mode = Mode::Perspective;

    QVector3D m_origin = {0, 0, 20};
    QQuaternion m_rotation = {0, 0, 0, 0};
    QVector3D m_target = {0, 0, 0};

    float m_left = -1;
    float m_right = 1;
    float m_bottom = -1;
    float m_top = 1;
    float m_near = 0.01;
    float m_far = 1000;

    float m_fov = M_PI / 6.0f;
    float m_aspectRatio = 16.0f / 9.0f;
};

}

#endif
