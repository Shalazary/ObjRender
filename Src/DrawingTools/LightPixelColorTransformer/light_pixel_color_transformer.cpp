#include "light_pixel_color_transformer.h"

#include "BarycentricCoordinatesTools/barycentric_coordinates_tools.h"


QColor DrawingTools::LightPixelColorTransformer::transformPixelColor(const QColor &color, const QVector3D &barycentricCoordinates) const
{
    const QVector3D pointNormal = BarycentricCoordinatesTools::mixByBarycentric<QVector3D>(m_normal1, m_normal2, m_normal3, barycentricCoordinates);
    const float intensity = QVector3D::dotProduct(-m_lightDirection.normalized(), pointNormal.normalized());
    if(intensity > 0)
        return QColor(color.red() * intensity, color.green() * intensity, color.blue() * intensity, color.alpha());
    else
        return Qt::transparent;
}

DrawingTools::LightPixelColorTransformer::LightPixelColorTransformer(
    const QVector3D &lightDirection,
    const QVector3D &normal1,
    const QVector3D &normal2,
    const QVector3D &normal3)
    : m_lightDirection(lightDirection),
      m_normal1(normal1),
      m_normal2(normal2),
      m_normal3(normal3)
{

}

DrawingTools::LightPixelColorTransformer DrawingTools::LightPixelColorTransformer::buildFromLightDirection(const QVector3D &lightDir)
{
    return LightPixelColorTransformer(lightDir, QVector3D(), QVector3D(), QVector3D());
}

QVector3D DrawingTools::LightPixelColorTransformer::lightDirection() const
{
    return m_lightDirection;
}

void DrawingTools::LightPixelColorTransformer::setLightDirection(const QVector3D &lightDirection)
{
    m_lightDirection = lightDirection;
}

QVector<QVector3D> DrawingTools::LightPixelColorTransformer::triangleNormals() const
{
    return {m_normal1, m_normal2, m_normal3};
}

void DrawingTools::LightPixelColorTransformer::setTriangleNormals(const QVector3D &normal1, const QVector3D &normal2, const QVector3D &normal3)
{
    m_normal1 = normal1;
    m_normal2 = normal2;
    m_normal3 = normal3;
}


