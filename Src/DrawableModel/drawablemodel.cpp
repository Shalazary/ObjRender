#include "drawablemodel.h"
#include "DrawingTools/drawingtools.h"
#include "HomogeneousCoordinatesTools/homogeneouscoordinatestools.h"

#include <QVector4D>
#include <cmath>

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
    QMatrix4x4 MVP =  projectionMatrix * modelViewMatrix;
    for(QVector<int> polygon : m_polygonsVerticesIndices) {
        int polygonSize = polygon.size();
        for(int i = 0; i < polygonSize  - 1; ++i){
            QVector3D p1 = QVector4D(MVP * QVector4D(m_vertices[polygon[i] - 1], 1)).toVector3DAffine();
            QVector3D p2 = QVector4D(MVP * QVector4D(m_vertices[polygon[i + 1] - 1], 1)).toVector3DAffine();
            NDCDrawingTools::drawLine(image, p1, p2, zbuffer);
        }
        QVector3D p1 = QVector4D(MVP * QVector4D(m_vertices[polygon[0] - 1], 1)).toVector3DAffine();
        QVector3D p2 = QVector4D(MVP * QVector4D(m_vertices[polygon[polygonSize - 1] - 1], 1)).toVector3DAffine();
        NDCDrawingTools::drawLine(image, p1, p2, zbuffer);
    }
}





