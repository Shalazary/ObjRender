#ifndef CAMERA_H
#define CAMERA_H

#include <QVector3D>
#include <QtMath>
#include <QMatrix4x4>

enum class CameraMode
{
    Orthographic,
    Perspective,
    Frustum
};

class Camera
{
public:
    Camera() = default;
    Camera(CameraMode mode);

    QMatrix4x4 view() const;
    QMatrix4x4 projection() const;

    CameraMode mode() const;
    void setMode(const CameraMode &mode);

    QVector3D pos() const;
    void setPos(const QVector3D &pos);
    void setPos(float x, float y, float z);

    QVector3D target() const;
    void setTarget(const QVector3D &target);
    void setTarget(float x, float y, float z);

    QVector3D up() const;
    void setUp(const QVector3D &up);
    void setUp(float x, float y, float z);

    float left() const;
    void setLeft(float left);

    float right() const;
    void setRight(float right);

    float bottom() const;
    void setBottom(float bottom);

    float top() const;
    void setTop(float top);

    float near() const;
    void setNear(float near);

    float far() const;
    void setFar(float far);

    float fov() const;
    void setFov(float fov);

    float aspectRatio() const;
    void setAspectRatio(float aspectRatio);

private:
    CameraMode m_mode = CameraMode::Perspective;

    QVector3D m_pos = {0, 0, 20};
    QVector3D m_target = {0, 0, 0};
    QVector3D m_up = {0, 1, 0};

    float m_left = -1;
    float m_right = 1;
    float m_bottom = -1;
    float m_top = 1;
    float m_near = 0.01;
    float m_far = 1000;

    float m_fov = M_PI / 6.0f;
    float m_aspectRatio = 16.0f / 9.0f;
};

#endif
