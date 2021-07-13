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
    for(QVector<int> polygon : m_polygonsVerticesIndices) {
        QVector3D normal = QVector3D::normal(
            m_vertices[polygon[1] - 1] - m_vertices[polygon[0] - 1],
            m_vertices[polygon[2] - 1] - m_vertices[polygon[0] - 1]);
        float intensity = QVector3D::dotProduct(normal, QVector3D(0, 0, 1));
        QMatrix4x4 MVP = projectionMatrix * modelViewMatrix;
        QVector3D p1 = QVector4D(MVP * QVector4D(m_vertices[polygon[0] - 1], 1)).toVector3DAffine();
        QVector3D p2 = QVector4D(MVP * QVector4D(m_vertices[polygon[1] - 1], 1)).toVector3DAffine();
        QVector3D p3 = QVector4D(MVP * QVector4D(m_vertices[polygon[2] - 1], 1)).toVector3DAffine();
        if(intensity > 0)
            NDCDrawingTools::drawTriangel(image, p1, p2, p3, zbuffer, QColor(255 * intensity, 255 * intensity, 255 * intensity));
    }
}





