#include "utils.h"

QVector<QVector<int> > ModelGeometryUtils::triangulate(const QVector<int> &polygonIndices)
{
    QVector<QVector<int> > triangles;

    for(int i = 0; i < polygonIndices.size() - 2; ++i)
        triangles.push_back({0, i + 1, i + 2});

    return triangles;
}

QVector3D ModelGeometryUtils::calculateNormal(
    int vertexIndex,
    const QVector<QVector3D> &vertices,
    const QVector<int> &polygonsVerticesIndices,
    const QVector<int> &polygonsStarts)
{
   QVector3D resultingNormal(0, 0, 0);

   for(int polygonNumber = 0; polygonNumber < polygonsStarts.size() - 1; ++polygonNumber) {
       const int polygonStart = polygonsStarts[polygonNumber];
       const int polygonSize = polygonsStarts[polygonNumber + 1] - polygonsStarts[polygonNumber];
       if(polygonsVerticesIndices.mid(polygonStart, polygonSize).contains(vertexIndex)) {
           QVector3D v1 = vertices[polygonsVerticesIndices[polygonStart + 1] - 1] - vertices[polygonsVerticesIndices[polygonStart] - 1];
           QVector3D v2 = vertices[polygonsVerticesIndices[polygonStart + 2] - 1] - vertices[polygonsVerticesIndices[polygonStart] - 1];
           resultingNormal += QVector3D::normal(v1, v2);
       }
   }

    return resultingNormal.normalized();
}
