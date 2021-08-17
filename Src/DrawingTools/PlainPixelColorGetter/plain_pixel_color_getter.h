#ifndef DRAWING_TOOLS_PLAIN_PIXEL_COLOR_GETTER_H
#define DRAWING_TOOLS_PLAIN_PIXEL_COLOR_GETTER_H

#include <QColor>

#include "AbstractPixelColorGetter/abstract_pixel_color_getter.h"

namespace DrawingTools {

class PlainPixelColorGetter : public AbstractPixelColorGetter
{
public:
    QColor getPixelColor(const QVector3D &barycentricCoordinates) const override;
    ~PlainPixelColorGetter() override = default;

    PlainPixelColorGetter() = default;
    PlainPixelColorGetter(const QColor &color);

private:
    QColor m_color;
};

}

#endif
