#ifndef MODEL_GEOMETRY_H
#define MODEL_GEOMETRY_H

#include <QVector>
#include <QVector2D>
#include <QVector3D>

class ModelGeometry
{
public:
    QVector<QVector3D> polygonVertices(int polygonIndex) const;
    QVector<QVector2D> polygonTexCoords(int polygonIndex) const;
    QVector<QVector3D> polygonNormals(int polygonIndex) const;

    QVector<QVector3D> vertices;
    QVector<QVector2D> texCoords;
    QVector<QVector3D> normals;

    QVector<int> polygonsVerticesIndices;
    QVector<int> polygonsTexCoordsIndices;
    QVector<int> polygonsNormalsIndices;

    QVector<int> polygonsStarts;
};

bool operator ==(const ModelGeometry &m1, const ModelGeometry &m2);

#endif
