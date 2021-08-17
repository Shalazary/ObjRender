#ifndef DRAWING_TOOLS_ABSTRACT_PIXEL_COLOR_TRANSFORMER_H
#define DRAWING_TOOLS_ABSTRACT_PIXEL_COLOR_TRANSFORMER_H

#include <QColor>
#include <QVector3D>

namespace DrawingTools {

class AbstractPixelColorTransformer
{
public:
    virtual QColor transformPixelColor(const QColor &color, const QVector3D &barycentricCoordinates) const = 0;
    virtual ~AbstractPixelColorTransformer() = default;
};

}

#endif
