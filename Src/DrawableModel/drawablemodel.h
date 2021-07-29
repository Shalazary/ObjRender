#ifndef DRAWABLE_MODEL_H
#define DRAWABLE_MODEL_H

#include <QImage>

#include "DrawableObject/drawableobject.h"
#include "ModelGeometry/ModelGeometry/modelgeometry.h"

class DrawableModel : public DrawableObject
{
public:
    DrawableModel() = default;

    ModelGeometry geometry() const;
    void setGeometry(const ModelGeometry &geometry);

    QImage texture() const;
    void setTexture(const QImage &texture);

    void draw(const QMatrix4x4 &modelViewMatrix, const QMatrix4x4 &projectionMatrix, QImage &image, float **zbuffer) const override;

private:
    ModelGeometry m_geometry;
    QImage m_texture = QImage(1, 1, QImage::Format_ARGB32);
};

#endif
