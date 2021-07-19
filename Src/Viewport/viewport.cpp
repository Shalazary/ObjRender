#include "viewport.h"

Viewport::Viewport(Camera *camera) : m_camera(camera)
{

}

Viewport::Viewport(Camera *camera, const QVector<DrawableObject *> objects) : m_camera(camera), m_objects(objects)
{

}

void Viewport::addModel(DrawableObject *object)
{
    m_objects.append(object);
}

QImage Viewport::render() const
{
    QImage image(m_width, m_hight, QImage::Format_RGB32);
    image.fill(Qt::black);

    QMatrix4x4 MV = m_camera->lookAt();
    QMatrix4x4 P = m_camera->perspectiveProjection();

    int **zbuffer = new int *[m_hight];
    for (int i = 0; i < m_hight; ++i)
        zbuffer[i] = new int [m_width];
    for(int i = 0; i < m_hight; ++i)
        for(int j = 0; j < m_width; ++j)
            zbuffer[i][j] = INT_MIN;

    for(DrawableObject *object : m_objects)
        object->draw(MV, P, image, zbuffer);

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
