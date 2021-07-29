#ifndef VIEWPORT_H
#define VIEWPORT_H

#include <QString>
#include <QImage>
#include <QPoint>
#include <QVector>

#include "DrawableObject/drawableobject.h"
#include "Camera/camera.h"

class Viewport
{
public:
    Viewport() = default;
    Viewport(Camera *camera);
    Viewport(Camera *camera, const QVector<DrawableObject *> objects);

    void addObject(DrawableObject *object);

    QImage render() const;

    int width() const;
    void setWidth(int width);

    int hight() const;
    void setHight(int hight);

private:
    QVector<DrawableObject *> m_objects;

    Camera *m_camera = new Camera(CameraMode::Perspective);

    int m_width = 1080;
    int m_hight = 1080;
};

#endif // VIEWPORT_H
