#include "drawablemodel.h"

#include <QVector3D>
#include <QVector4D>

#include "DrawingTools/drawingtools.h"
#include "ModelGeometry/Utils/utils.h"
#include "RenderTools/render_tools.h"

void DrawableModel::draw(const QMatrix4x4 &modelViewMatrix, const QMatrix4x4 &projectionMatrix, QImage &image, float **zbuffer) const
{
    const QMatrix4x4 MVP = projectionMatrix * modelViewMatrix;
    const QVector3D lightDir = (MVP.inverted() * QVector3D(0, 0, 1)).normalized();

    RenderTools::render(
        &image,
        zbuffer,
        m_geometry.vertices,
        m_geometry.polygonsVerticesIndices,
        m_geometry.texCoords,
        m_geometry.polygonsTexCoordsIndices,
        m_geometry.polygonsStarts,
        useTexture ? m_texture : QImage(),
        useLight ? lightDir : QVector3D(0, 0, 0),
        MVP,
        m_color);
}

QColor DrawableModel::color() const
{
    return m_color;
}

void DrawableModel::setColor(const QColor &color)
{
    m_color = color;
}

ModelGeometry DrawableModel::geometry() const
{
    return m_geometry;
}

void DrawableModel::setGeometry(const ModelGeometry &geometry)
{
    m_geometry = geometry;
}

QImage DrawableModel::texture() const
{
    return m_texture;
}

void DrawableModel::setTexture(const QImage &texture)
{
    m_texture = texture;
}





