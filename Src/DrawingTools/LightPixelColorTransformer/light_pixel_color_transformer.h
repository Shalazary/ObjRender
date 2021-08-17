#ifndef DRAWING_TOOLS_LIGHT_PIXEL_COLOR_TRANSFORMER_H
#define DRAWING_TOOLS_LIGHT_PIXEL_COLOR_TRANSFORMER_H

#include "AbstractPixelColorTransformer/abstract_pixel_color_transformer.h"

#include <QVector3D>
#include <QVector>

namespace DrawingTools {

class LightPixelColorTransformer : public AbstractPixelColorTransformer
{
public:
    QColor transformPixelColor(const QColor &color, const QVector3D &barycentricCoordinates) const override;
    ~LightPixelColorTransformer() override = default;

    LightPixelColorTransformer(
        const QVector3D &lightDirection,
        const QVector3D &normal1,
        const QVector3D &normal2,
        const QVector3D &normal3);

    static LightPixelColorTransformer buildFromLightDirection(const QVector3D &lightDir);

    QVector3D lightDirection() const;
    void setLightDirection(const QVector3D &lightDirection);

    QVector<QVector3D> triangleNormals() const;
    void setTriangleNormals(
        const QVector3D &normal1,
        const QVector3D &normal2,
        const QVector3D &normal3);

private:
    QVector3D m_lightDirection = QVector3D(0.0f, 0.0f, -1.0f);
    QVector3D m_normal1;
    QVector3D m_normal2;
    QVector3D m_normal3;

};

}

#endif
