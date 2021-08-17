#ifndef DRAWABLE_OBJECT_H
#define DRAWABLE_OBJECT_H

#include <QMatrix4x4>
#include <QImage>

#include "Array2D/array2d.h"

class DrawableObject
{
public:
    virtual void draw(const QMatrix4x4 &modelViewMatrix, const QMatrix4x4 &projectionMatrix, QImage &image, Array2D::Array2D<float> &zbuffer) const = 0;
    virtual ~DrawableObject() = default;
};

#endif
