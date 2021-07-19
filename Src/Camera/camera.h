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
    Camera(float fov, float aspectRatio, float near, float far);

    QMatrix4x4 lookAt() const;
    QMatrix4x4 perspectiveProjection() const;
    QMatrix4x4 orthographicProjection() const;

    QVector3D pos() const;
    void setPos(const QVector3D &pos);

    QVector3D target() const;
    void setTarget(const QVector3D &target);

    QVector3D up() const;
    void setUp(const QVector3D &up);

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
    QVector3D m_pos = {0, 0, 1};
    QVector3D m_target = {0, 0, 0};
    QVector3D m_up = {0, 1, 0};

    float m_left = -1;
    float m_right = 1;
    float m_bottom = -1;
    float m_top = 1;
    float m_near = 0.1;
    float m_far = 100;

    float m_fov = M_PI_2;
    float m_aspectRatio = 16.0f / 9.0f;
};

#endif
