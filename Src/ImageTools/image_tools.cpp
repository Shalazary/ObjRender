#include "image_tools.h"

#include <cmath>

QColor ImageTools::getPixelColor(const QImage &image, float x, float y, ImageTools::InterpolationType type)
{
    if(type == InterpolationType::Nearest)
        return getPixelColorNearest(image, x, y);

    if(type == InterpolationType::Bilinear)
        return getPixelColorBilinear(image, x, y);

    Q_ASSERT_X(false, "getPixelColor", "unknown interpolation type");
    return QColor();
}

QColor ImageTools::getPixelColor(const QImage &image, const QVector2D &p, ImageTools::InterpolationType type)
{
    return getPixelColor(image, p.x(), p.y(), type);
}

QColor ImageTools::getPixelColorNearest(const QImage &image, float x, float y)
{
    return image.pixelColor(std::round(x), std::round(y));
}

QColor ImageTools::getPixelColorNearest(const QImage &image, const QVector2D &p)
{
    return getPixelColorNearest(image, p.x(), p.y());
}

QColor ImageTools::getPixelColorBilinear(const QImage &image, float x, float y)
{
    if(image.height() < 2 || image.width() < 2)
        return image.pixelColor(0, 0);

    int x0 = std::floor(x);
    int x1 = std::floor(x + 1.0f);
    int y0 = std::floor(y);
    int y1 = std::floor(y + 1.0f);

    if(x1 == image.width()) {
        x1 = x0;
        --x0;
    }

    if(y1 == image.height()) {
        y1 = y0;
        --y0;
    }

    const QColor c4 = image.pixelColor(x0, y0);
    const QColor c3 = image.pixelColor(x1, y0);
    const QColor c2 = image.pixelColor(x0, y1);
    const QColor c1 = image.pixelColor(x1, y1);

    const float r1 = c1.red() * (x - x0) + c2.red() * (x1 - x);
    const float g1 = c1.green() * (x - x0) + c2.green() * (x1 - x);
    const float b1 = c1.blue() * (x - x0) + c2.blue() * (x1 - x);
    const float a1 = c1.alpha() * (x - x0) + c2.alpha() * (x1 - x);

    const float r2 = c3.red() * (x - x0) + c4.red() * (x1 - x);
    const float g2 = c3.green() * (x - x0) + c4.green() * (x1 - x);
    const float b2 = c3.blue() * (x - x0) + c4.blue() * (x1 - x);
    const float a2 = c3.alpha() * (x - x0) + c4.alpha() * (x1 - x);

    const float r = r1 * (y - y0) + r2 * (y1 - y);
    const float g = g1 * (y - y0) + g2 * (y1 - y);
    const float b = b1 * (y - y0) + b2 * (y1 - y);
    const float a = a1 * (y - y0) + a2 * (y1 - y);

    return QColor(r, g, b, a);
}

QColor ImageTools::getPixelColorBilinear(const QImage &image, const QVector2D &p)
{
    return getPixelColorBilinear(image, p.x(), p.y());
}
