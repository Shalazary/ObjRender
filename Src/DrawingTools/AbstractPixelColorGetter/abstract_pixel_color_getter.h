#ifndef DRAWING_TOOLS_ABSTRACT_PIXEL_COLOR_GETTER_H
#define DRAWING_TOOLS_ABSTRACT_PIXEL_COLOR_GETTER_H

#include <QColor>
#include <QVector3D>

namespace DrawingTools {

class AbstractPixelColorGetter
{
public:
    virtual QColor getPixelColor(const QVector3D &barycentricCoordinates) const = 0;
    virtual ~AbstractPixelColorGetter() = default;
};

}

#endif
