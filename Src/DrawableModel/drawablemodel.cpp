#include "drawablemodel.h"

#include <QVector3D>
#include <QVector4D>

#include "ModelGeometry/Utils/utils.h"
#include "ShadePixelColorGetter/shade_pixel_color_getter.h"
#include "PlainPixelColorGetter/plain_pixel_color_getter.h"
#include "TexturePixelColorGetter/texture_pixel_color_getter.h"
#include "LightPixelColorTransformer/light_pixel_color_transformer.h"
#include "ShapeDrawingTools/shapedrawingtools.h"

void DrawableModel::DrawableModel::draw(const QMatrix4x4 &modelViewMatrix, const QMatrix4x4 &projectionMatrix, QImage &image, Array2D::Array2D<float> &zbuffer) const
{
    const QMatrix4x4 MVP = projectionMatrix * modelViewMatrix;
    const QVector3D lightDir = (MVP.inverted() * QVector3D(0, 0, 1)).normalized();

    DrawingTools::ShadePixelColorGetter colorGetter;
    DrawingTools::TexturePixelColorGetter textureColorGetter = DrawingTools::TexturePixelColorGetter::buildFromTexture(m_texture);
    DrawingTools::PlainPixelColorGetter plainColorGetter(m_color);
    DrawingTools::LightPixelColorTransformer lightColorTransformer = DrawingTools::LightPixelColorTransformer::buildFromLightDirection(lightDir);

    if(useTexture){
        colorGetter.setColorGetter(&textureColorGetter);
    } else {
        colorGetter.setColorGetter(&plainColorGetter);
    }

    if(useLight)
        colorGetter.setColorTransformer(&lightColorTransformer);

    for(int polygonNumber = 0; polygonNumber < m_geometry.nTriangles(); ++polygonNumber){
        int polygonStart = polygonNumber * 3;

        QVector4D v1 = MVP * QVector4D(m_geometry.vertices[m_geometry.triangulatedPolygonsVerticesIndices[polygonStart] - 1], 1);
        QVector4D v2 = MVP * QVector4D(m_geometry.vertices[m_geometry.triangulatedPolygonsVerticesIndices[polygonStart + 1] - 1], 1);
        QVector4D v3 = MVP * QVector4D(m_geometry.vertices[m_geometry.triangulatedPolygonsVerticesIndices[polygonStart + 2] - 1], 1);

        QVector2D vt1 = m_geometry.texCoords[m_geometry.triangulatedPolygonsTexCoordsIndices[polygonStart] - 1];
        QVector2D vt2 = m_geometry.texCoords[m_geometry.triangulatedPolygonsTexCoordsIndices[polygonStart + 1] - 1];
        QVector2D vt3 = m_geometry.texCoords[m_geometry.triangulatedPolygonsTexCoordsIndices[polygonStart + 2] - 1];

        QVector3D vn1 = m_geometry.recomputedNormals[m_geometry.triangulatedPolygonsVerticesIndices[polygonStart] - 1];
        QVector3D vn2 = m_geometry.recomputedNormals[m_geometry.triangulatedPolygonsVerticesIndices[polygonStart + 1] - 1];
        QVector3D vn3 = m_geometry.recomputedNormals[m_geometry.triangulatedPolygonsVerticesIndices[polygonStart + 2] - 1];

        textureColorGetter.setTriangleTexCoordinates(vt1, vt2, vt3);
        lightColorTransformer.setTriangleNormals(vn1, vn2, vn3);

        ShapeDrawingTools::drawTriangle(image, zbuffer, v1, v2, v3, &colorGetter);
    }
}

QColor DrawableModel::DrawableModel::color() const
{
    return m_color;
}

void DrawableModel::DrawableModel::setColor(const QColor &color)
{
    m_color = color;
}

ModelGeometry::ModelGeometry DrawableModel::DrawableModel::geometry() const
{
    return m_geometry;
}

void DrawableModel::DrawableModel::setGeometry(const ModelGeometry::ModelGeometry &geometry)
{
    m_geometry = geometry;
}

QImage DrawableModel::DrawableModel::texture() const
{
    return m_texture;
}

void DrawableModel::DrawableModel::setTexture(const QImage &texture)
{
    m_texture = texture;
}





