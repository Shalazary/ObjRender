#include "drawablemodel.h"
#include "DrawingTools/drawingtools.h"

#include <QVector4D>
#include <Point3D/point3d.h>
#include <QtDebug>
#include <QRandomGenerator>

void DrawableModel::draw(const QMatrix4x4 &modelViewMatrix, const QMatrix4x4 &projectionMatrix, QImage &image, float **zbuffer) const
{
    QMatrix4x4 MVP = projectionMatrix * modelViewMatrix;
    QVector3D lightDir = QVector4D(MVP.inverted() * QVector4D(0, 0, -1, 1)).toVector3DAffine().normalized();

    for(int polygonInd = 0; polygonInd < m_geometry.m_polygonsVerticesIndices.size(); ++polygonInd) {
        QVector<int> polygonVertices = m_geometry.m_polygonsVerticesIndices[polygonInd];
        QVector<int> polygonNormals = m_geometry.m_polygonsNormalsIndices[polygonInd];
        QVector<int> polygonTex = m_geometry.m_polygonsTexCoordsIndices[polygonInd];

        QVector4D p1 = QVector4D(MVP * QVector4D(m_geometry.m_vertices[polygonVertices[0] - 1], 1));
        QVector4D p2 = QVector4D(MVP * QVector4D(m_geometry.m_vertices[polygonVertices[1] - 1], 1));
        QVector4D p3 = QVector4D(MVP * QVector4D(m_geometry.m_vertices[polygonVertices[2] - 1], 1));

        QVector2D vt1 = m_geometry.m_texCoords[polygonTex[0] - 1];
        QVector2D vt2 = m_geometry.m_texCoords[polygonTex[1] - 1];
        QVector2D vt3 = m_geometry.m_texCoords[polygonTex[2] - 1];

        QVector3D vn1 = m_geometry.m_normals[polygonNormals[0] - 1];
        QVector3D vn2 = m_geometry.m_normals[polygonNormals[1] - 1];
        QVector3D vn3 = m_geometry.m_normals[polygonNormals[2] - 1];

        DrawingTools::drawTriangel(image, p1, p2, p3, vt1, vt2, vt3, vn1, vn2, vn3, lightDir, m_texture, zbuffer);
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





