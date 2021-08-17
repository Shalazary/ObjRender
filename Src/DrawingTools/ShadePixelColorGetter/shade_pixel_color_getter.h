#ifndef DRAWING_TOOLS_SHADE_PIXEL_COLOR_GETTER_H
#define DRAWING_TOOLS_SHADE_PIXEL_COLOR_GETTER_H

#include "AbstractPixelColorGetter/abstract_pixel_color_getter.h"
#include "AbstractPixelColorTransformer/abstract_pixel_color_transformer.h"

namespace DrawingTools {

class ShadePixelColorGetter : public AbstractPixelColorGetter
{
public:
    QColor getPixelColor(const QVector3D &barycentricCoordinates) const override;
    ~ShadePixelColorGetter() override  = default;

    ShadePixelColorGetter() = default;
    ShadePixelColorGetter(AbstractPixelColorGetter *colorGetter, AbstractPixelColorTransformer *colorTransformer);

    AbstractPixelColorGetter *colorGetter() const;
    void setColorGetter(AbstractPixelColorGetter *colorGetter);

    AbstractPixelColorTransformer *colorTransformer() const;
    void setColorTransformer(AbstractPixelColorTransformer *colorTransformer);

private:
    AbstractPixelColorGetter *m_colorGetter = nullptr;
    AbstractPixelColorTransformer *m_colorTransformer = nullptr;
};

}

#endif
