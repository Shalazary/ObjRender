#include "drawablemodel.h"
#include "DrawingTools/drawingtools.h"
#include "ModelGeometry/Utils/utils.h"

#include <QVector4D>

void DrawableModel::draw(const QMatrix4x4 &modelViewMatrix, const QMatrix4x4 &projectionMatrix, QImage &image, float **zbuffer) const
{
    QMatrix4x4 MVP = projectionMatrix * modelViewMatrix;
    QVector3D lightDir = QVector4D(MVP.inverted() * QVector4D(0, 0, -1, 1)).toVector3DAffine().normalized();

    for(int polygonInd = 0; polygonInd < m_geometry.m_polygonsVerticesIndices.size(); ++polygonInd) {
        QVector<QVector<int>> triangles = ModelGeometryUtils::triangulate(m_geometry.m_polygonsVerticesIndices[polygonInd]);
        for(const QVector<int> &triangel : triangles){
            QVector<int> polygonVertices = m_geometry.m_polygonsVerticesIndices[polygonInd];
            QVector<int> polygonTex = m_geometry.m_polygonsTexCoordsIndices[polygonInd];

            QVector4D p1 = QVector4D(MVP * QVector4D(m_geometry.m_vertices[polygonVertices[triangel[0]] - 1], 1));
            QVector4D p2 = QVector4D(MVP * QVector4D(m_geometry.m_vertices[polygonVertices[triangel[1]] - 1], 1));
            QVector4D p3 = QVector4D(MVP * QVector4D(m_geometry.m_vertices[polygonVertices[triangel[2]] - 1], 1));

            QVector2D vt1;
            QVector2D vt2;
            QVector2D vt3;

            if(useTexture) {
                vt1 = m_geometry.m_texCoords[polygonTex[triangel[0]] - 1];
                vt2 = m_geometry.m_texCoords[polygonTex[triangel[1]] - 1];
                vt3 = m_geometry.m_texCoords[polygonTex[triangel[2]] - 1];
            }

            QVector3D vn1;
            QVector3D vn2;
            QVector3D vn3;

            if(useLight) {
                vn1 = ModelGeometryUtils::calculateNormal(polygonVertices[triangel[0]], m_geometry.m_vertices, m_geometry.m_polygonsVerticesIndices);
                vn2 = ModelGeometryUtils::calculateNormal(polygonVertices[triangel[1]], m_geometry.m_vertices, m_geometry.m_polygonsVerticesIndices);
                vn3 = ModelGeometryUtils::calculateNormal(polygonVertices[triangel[2]], m_geometry.m_vertices, m_geometry.m_polygonsVerticesIndices);
            }

            if(!useTexture && !useLight)
                DrawingTools::drawTriangel(image, p1, p2, p3, m_color, zbuffer);
            else if(!useTexture && useLight)
                DrawingTools::drawTriangel(image, p1, p2, p3, vn1, vn2, vn3, lightDir, m_color, zbuffer);
            else if(useTexture && !useLight)
                DrawingTools::drawTriangel(image, p1, p2, p3, vt1, vt2, vt3, m_texture, zbuffer);
            else if(useTexture && useLight)
                DrawingTools::drawTriangel(image, p1, p2, p3, vt1, vt2, vt3, vn1, vn2, vn3, lightDir, m_texture, zbuffer);
        }
    }
}

QColor DrawableModel::color() const
{
    return m_color;
}

void DrawableModel::setColor(const QColor &color)
{
    m_color = color;
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





