#ifndef DRAWABLE_OBJECT_H
#define DRAWABLE_OBJECT_H

#include <QMatrix4x4>
#include <QImage>

class DrawableObject
{
public:
    virtual void draw(const QMatrix4x4 &modelViewMatrix, const QMatrix4x4 &projectionMatrix, QImage &image, float **zbuffer) const = 0;
};

#endif
