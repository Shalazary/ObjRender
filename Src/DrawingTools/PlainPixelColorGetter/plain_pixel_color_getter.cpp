#include "plain_pixel_color_getter.h"



QColor DrawingTools::PlainPixelColorGetter::getPixelColor(const QVector3D &barycentricCoordinates) const
{
    return m_color;
}

DrawingTools::PlainPixelColorGetter::PlainPixelColorGetter(const QColor &color)
    : m_color(color)
{

}
