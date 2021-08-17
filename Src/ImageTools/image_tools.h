#ifndef IMAGE_TOOLS_H
#define IMAGE_TOOLS_H

#include <QColor>
#include <QImage>
#include <QVector2D>

namespace ImageTools {

enum class InterpolationType {
    Nearest,
    Bilinear
};

QColor getPixelColor(const QImage &image, float x, float y, InterpolationType type = InterpolationType::Nearest);
QColor getPixelColor(const QImage &image, const QVector2D &p, InterpolationType type = InterpolationType::Nearest);

QColor getPixelColorNearest(const QImage &image, float x, float y);
QColor getPixelColorNearest(const QImage &image, const QVector2D &p);

QColor getPixelColorBilinear(const QImage &image, float x, float y);
QColor getPixelColorBilinear(const QImage &image, const QVector2D &p);

}

#endif
