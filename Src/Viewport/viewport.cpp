#include "viewport.h"

Viewport::Viewport(Camera *camera) : m_camera(camera)
{

}

Viewport::Viewport(Camera *camera, const QVector<DrawableObject *> objects) : m_camera(camera), m_objects(objects)
{

}

void Viewport::addObject(DrawableObject *object)
{
    m_objects.append(object);
}

void Viewport::deleteObject(DrawableObject *object)
{
    int objectInd = m_objects.indexOf(object);
    if(objectInd != -1)
        m_objects.remove(objectInd);
}

QImage Viewport::render() const
{
    QImage image(m_width, m_hight, QImage::Format_RGB32);
    image.fill(backgroundColor);

    const QMatrix4x4 view = m_camera->view();
    const QMatrix4x4 projection = m_camera->projection();

    //! REVIEW: class for 2d arrays. Remember about rule of 5
    float **zbuffer = new float * [m_hight];
    zbuffer[0] = new float [m_hight * m_width];
    for(int i = 1; i < m_hight; ++i)
        zbuffer[i] = zbuffer[i - 1] + m_width;

    for(int i = 0; i < m_hight; ++i)
        for(int j = 0; j < m_width; ++j)
            zbuffer[i][j] = 2.0f;

    for(DrawableObject *object : m_objects)
        object->draw(view, projection, image, zbuffer);

    delete[] zbuffer[0];
    delete[] zbuffer;

    return image;
}

int Viewport::width() const
{
    return m_width;
}

void Viewport::setWidth(int width)
{
    m_width = width;
}

int Viewport::hight() const
{
    return m_hight;
}

void Viewport::setHight(int hight)
{
    m_hight = hight;
}

QColor Viewport::getBackgroundColor() const
{
    return backgroundColor;
}

void Viewport::setBackgroundColor(const QColor &value)
{
    backgroundColor = value;
}
