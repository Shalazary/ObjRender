#include "drawablemodel.h"
#include "DrawingTools/drawingtools.h"

#include <QVector4D>

bool DrawableModel::save(const QString &filename, QString &errMsg) const
{

}

bool DrawableModel::save(QTextStream &stream, QString &errMsg) const
{

}

bool DrawableModel::read(const QString &filename, QString &errMsg)
{

}

bool DrawableModel::read(QTextStream &stream, QString &errMsg)
{

}

void DrawableModel::draw(const QMatrix4x4 &modelViewMatrix, const QMatrix4x4 &projectionMatrix, QImage &image, int **zbuffer)
{
    QMatrix4x4 MVP = modelViewMatrix * projectionMatrix;
    for(QVector<int> polygon : polygonsVerticesIndices) {
        QVector3D normal = QVector3D::normal(
            vertices[polygon[1] - 1] - vertices[polygon[0] - 1],
            vertices[polygon[2] - 1] - vertices[polygon[0] - 1]);
        float intensity = QVector3D::dotProduct(normal, QVector3D(0, 0, 1));
        if(intensity > 0)
            NDCDrawingTools::drawTriangel(
                image,
                vertices[polygon[0] - 1],
                vertices[polygon[1] - 1],
                vertices[polygon[2] - 1],
                zbuffer,
                QColor(255 * intensity, 255 * intensity, 255 * intensity));
    }
}





