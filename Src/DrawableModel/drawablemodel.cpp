#include "drawablemodel.h"
#include "DrawingTools/drawingtools.h"
#include "HomogeneousCoordinatesTools/homogeneouscoordinatestools.h"

#include <QVector4D>
#include <Point3D/point3d.h>
#include <QtDebug>

void DrawableModel::draw(const QMatrix4x4 &modelViewMatrix, const QMatrix4x4 &projectionMatrix, QImage &image, int **zbuffer)
{
    QMatrix4x4 MVP =  HomogeneousCoordinatesTools::viewport(image.height(), image.width(), 256) * projectionMatrix * modelViewMatrix;
    for(QVector<int> polygon : m_geometry.m_polygonsVerticesIndices) {
        Point3D p1 = QVector4D(MVP * QVector4D(m_geometry.m_vertices[polygon[0] - 1], 1)).toVector3DAffine();
        Point3D p2 = QVector4D(MVP * QVector4D(m_geometry.m_vertices[polygon[1] - 1], 1)).toVector3DAffine();
        Point3D p3 = QVector4D(MVP * QVector4D(m_geometry.m_vertices[polygon[2] - 1], 1)).toVector3DAffine();
        DrawingTools::drawTriangel(image, p1, p2, p3, zbuffer, QColor(qrand() % 256, qrand() % 256, qrand() % 256));
//        DrawingTools::drawLine(image, p1, p2, zbuffer, Qt::gray);
//        DrawingTools::drawLine(image, p2, p3, zbuffer, Qt::gray);
//        DrawingTools::drawLine(image, p1, p3, zbuffer, Qt::gray);
    }
}

ModelGeometry DrawableModel::geometry() const
{
    return m_geometry;
}

void DrawableModel::setGeometry(const ModelGeometry &geometry)
{
    m_geometry = geometry;
}

QImage DrawableModel::texture() const
{
    return m_texture;
}

void DrawableModel::setTexture(const QImage &texture)
{
    m_texture = texture;
}





