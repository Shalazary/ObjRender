#ifndef DRAWING_TOOLS_TEXTURE_PIXEL_COLOR_GETTER_H
#define DRAWING_TOOLS_TEXTURE_PIXEL_COLOR_GETTER_H

#include "AbstractPixelColorGetter/abstract_pixel_color_getter.h"

#include <QColor>
#include <QImage>
#include <QVector>
#include <QVector2D>

namespace DrawingTools {

class TexturePixelColorGetter : public AbstractPixelColorGetter
{
public:
    QColor getPixelColor(const QVector3D &barycentricCoordinates) const override;
    ~TexturePixelColorGetter() override  = default;

    TexturePixelColorGetter() = default;
    TexturePixelColorGetter(
        const QImage &texture,
        const QVector3D &vt1,
        const QVector3D &vt2,
        const QVector3D &vt3);

    static TexturePixelColorGetter buildFromTexture(const QImage &texture);

    QVector<QVector2D> triangleTexCoordinates() const;
    void setTriangleTexCoordinates(
        const QVector2D &vt1,
        const QVector2D &vt2,
        const QVector2D &vt3);

private:
    QImage m_texture;

    QVector2D m_texCoord1;
    QVector2D m_texCoord2;
    QVector2D m_texCoord3;   

};

}

#endif

