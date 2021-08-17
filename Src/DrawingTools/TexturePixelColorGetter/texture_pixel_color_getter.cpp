#include "texture_pixel_color_getter.h"

#include "BarycentricCoordinatesTools/barycentric_coordinates_tools.h"
#include "HomogeneousCoordinatesTools/homogeneouscoordinatestools.h"
#include "ImageTools/image_tools.h"

#include <optional>



QColor DrawingTools::TexturePixelColorGetter::getPixelColor(const QVector3D &barycentricCoordinates) const
{
    QVector2D coordsOntexture = BarycentricCoordinatesTools::mixByBarycentric<QVector2D>(m_texCoord1, m_texCoord2, m_texCoord3, barycentricCoordinates);
    QVector2D pixelOnTexture = HomogeneousCoordinatesTools::projectToTexturePixelCoordinates(coordsOntexture, m_texture.size());
    return ImageTools::getPixelColorBilinear(m_texture, pixelOnTexture);
}

DrawingTools::TexturePixelColorGetter::TexturePixelColorGetter(const QImage &texture, const QVector3D &vt1, const QVector3D &vt2, const QVector3D &vt3)
    : m_texture(texture),
      m_texCoord1(vt1),
      m_texCoord2(vt2),
      m_texCoord3(vt3)
{

}

DrawingTools::TexturePixelColorGetter DrawingTools::TexturePixelColorGetter::buildFromTexture(const QImage &texture)
{
    return TexturePixelColorGetter(texture, QVector2D(), QVector2D(), QVector2D());
}

QVector<QVector2D> DrawingTools::TexturePixelColorGetter::triangleTexCoordinates() const
{
    return QVector<QVector2D>({m_texCoord1, m_texCoord2, m_texCoord3});
}

void DrawingTools::TexturePixelColorGetter::setTriangleTexCoordinates(const QVector2D &vt1, const QVector2D &vt2, const QVector2D &vt3)
{
    m_texCoord1 = vt1;
    m_texCoord2 = vt2;
    m_texCoord3 = vt3;
}


