#include "viewport.h"

#include "Array2D/array2d.h"

Viewport::Viewport::Viewport(Camera::Camera *camera) : m_camera(camera)
{

}

Viewport::Viewport::Viewport(Camera::Camera *camera, const QVector<DrawableObject *> &objects) : m_camera(camera), m_objects(objects)
{

}

void Viewport::Viewport::addObject(DrawableObject *object)
{
    m_objects.append(object);
}

void Viewport::Viewport::deleteObject(DrawableObject *object)
{
    int objectInd = m_objects.indexOf(object);
    if(objectInd != -1)
        m_objects.remove(objectInd);
}

QImage Viewport::Viewport::render() const
{
    QImage image(m_width, m_height, QImage::Format_RGB32);
    image.fill(m_backgroundColor);

    const QMatrix4x4 view = m_camera->view();
    const QMatrix4x4 projection = m_camera->projection();

    Array2D::Array2D<float> zbuffer(m_height, m_width, 2.0f);

    for(DrawableObject *object : m_objects)
        object->draw(view, projection, image, zbuffer);

    return image;
}

int Viewport::Viewport::width() const
{
    return m_width;
}

void Viewport::Viewport::setWidth(int width)
{
    m_width = width;
}

int Viewport::Viewport::hight() const
{
    return m_height;
}

void Viewport::Viewport::setHight(int hight)
{
    m_height = hight;
}

QColor Viewport::Viewport::getBackgroundColor() const
{
    return m_backgroundColor;
}

void Viewport::Viewport::setBackgroundColor(const QColor &value)
{
    m_backgroundColor = value;
}
