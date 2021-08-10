#ifndef VIEWPORT_H
#define VIEWPORT_H

#include <QString>
#include <QImage>
#include <QPoint>
#include <QVector>

#include "DrawableObject/drawableobject.h"
#include "Camera/camera.h"

//! REVIEW: namespace
class Viewport
{
public:
    Viewport() = default;
    Viewport(Camera *camera);
    //! REVIEW: const &
    Viewport(Camera *camera, const QVector<DrawableObject *> objects);

    void addObject(DrawableObject *object);
    void deleteObject(DrawableObject *object);

    QImage render() const;

    int width() const;
    void setWidth(int width);

    int hight() const;
    void setHight(int hight);

    QColor getBackgroundColor() const;
    void setBackgroundColor(const QColor &value);

private:
    QVector<DrawableObject *> m_objects;

    Camera *m_camera = new Camera(CameraMode::Perspective);

    int m_width = 1080;
    int m_hight = 1080;

    //! REVIEW: m_
    QColor backgroundColor = Qt::lightGray;
};

#endif // VIEWPORT_H
