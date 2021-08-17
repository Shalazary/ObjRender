#ifndef DRAWABLE_MODEL_H
#define DRAWABLE_MODEL_H

#include <QImage>

#include "DrawableObject/drawableobject.h"
#include "ModelGeometry/ModelGeometry/modelgeometry.h"
#include "Array2D/array2d.h"

namespace DrawableModel {

class DrawableModel : public DrawableObject
{
public:
    DrawableModel() = default;

    ModelGeometry::ModelGeometry geometry() const;
    void setGeometry(const ModelGeometry::ModelGeometry &geometry);

    QImage texture() const;
    void setTexture(const QImage &texture);

    bool useLight = false;
    bool useTexture = false;

    QColor color() const;
    void setColor(const QColor &color);

    void draw(const QMatrix4x4 &modelViewMatrix, const QMatrix4x4 &projectionMatrix, QImage &image, Array2D::Array2D<float> &zbuffer) const override;
    ~DrawableModel() override = default;

private:
    ModelGeometry::ModelGeometry m_geometry;
    QImage m_texture;
    QColor m_color = Qt::white;
};

}

#endif
