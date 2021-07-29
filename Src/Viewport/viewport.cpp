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

QImage Viewport::render() const
{
    QImage image(m_width, m_hight, QImage::Format_RGB32);
    image.fill(Qt::black);

    QMatrix4x4 view = m_camera->view();
    QMatrix4x4 projection = m_camera->projection();

    float **zbuffer = new float *[m_hight];
    for (int i = 0; i < m_hight; ++i)
        zbuffer[i] = new float [m_width];
    for(int i = 0; i < m_hight; ++i)
        for(int j = 0; j < m_width; ++j)
            zbuffer[i][j] = 2.0f;

    for(DrawableObject *object : m_objects)
        object->draw(view, projection, image, zbuffer);

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
