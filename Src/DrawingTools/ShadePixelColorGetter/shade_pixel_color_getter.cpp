 #include "shade_pixel_color_getter.h"

QColor DrawingTools::ShadePixelColorGetter::getPixelColor(const QVector3D &barycentricCoordinates) const
{
    QColor color = Qt::black;

    if(m_colorGetter != nullptr)
        color = m_colorGetter->getPixelColor(barycentricCoordinates);

    if(m_colorTransformer != nullptr)
        color = m_colorTransformer->transformPixelColor(color, barycentricCoordinates);

    return color;
}

DrawingTools::ShadePixelColorGetter::ShadePixelColorGetter(
    DrawingTools::AbstractPixelColorGetter *colorGetter,
    DrawingTools::AbstractPixelColorTransformer *colorTransformer)
    : m_colorGetter(colorGetter),
      m_colorTransformer(colorTransformer)
{

}

DrawingTools::AbstractPixelColorTransformer *DrawingTools::ShadePixelColorGetter::colorTransformer() const
{
    return m_colorTransformer;
}

void DrawingTools::ShadePixelColorGetter::setColorTransformer(DrawingTools::AbstractPixelColorTransformer *colorTransformer)
{
    m_colorTransformer = colorTransformer;
}

DrawingTools::AbstractPixelColorGetter *DrawingTools::ShadePixelColorGetter::colorGetter() const
{
    return m_colorGetter;
}

void DrawingTools::ShadePixelColorGetter::setColorGetter(DrawingTools::AbstractPixelColorGetter *colorGetter)
{
    m_colorGetter = colorGetter;
}




