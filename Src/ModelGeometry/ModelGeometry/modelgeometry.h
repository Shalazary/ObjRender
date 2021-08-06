#ifndef MODEL_GEOMETRY_H
#define MODEL_GEOMETRY_H

#include <QVector>
#include <QVector2D>
#include <QVector3D>

class ModelGeometry
{
public:
    QVector<QVector3D> m_vertices;
    QVector<QVector2D> m_texCoords;
    QVector<QVector3D> m_normals;

    QVector<QVector<int>> m_polygonsVerticesIndices;
    QVector<QVector<int>> m_polygonsTexCoordsIndices;
    QVector<QVector<int>> m_polygonsNormalsIndices;
};

bool operator ==(const ModelGeometry &m1, const ModelGeometry &m2);

#endif
