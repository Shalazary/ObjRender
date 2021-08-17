#ifndef MODEL_GEOMETRY_H
#define MODEL_GEOMETRY_H

#include <QVector>
#include <QVector2D>
#include <QVector3D>

namespace ModelGeometry {

class ModelGeometry
{
public:
    QVector<QVector3D> vertices;
    QVector<QVector2D> texCoords;
    QVector<QVector3D> normals;
    QVector<QVector3D> recomputedNormals;

    QVector<int> polygonsVerticesIndices;
    QVector<int> polygonsTexCoordsIndices;
    QVector<int> polygonsNormalsIndices;

    QVector<int> polygonsStarts;

    QVector<int> triangulatedPolygonsVerticesIndices;
    QVector<int> triangulatedPolygonsTexCoordsIndices;
    QVector<int> triangulatedPolygonsNormalsIndices;

    int nPolygons() const;
    int nTriangles() const;

    bool isTriangulated() const;
    bool isNormalsRecomputed() const;

    void clear();

    void triangulate();

    void recomputeNormals();

private:
    int m_nTrianles = 0;
};

bool operator ==(const ModelGeometry &m1, const ModelGeometry &m2);

}

#endif
