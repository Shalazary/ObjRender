#include "utils.h"

#include <algorithm>
#include <QVector3D>


QVector<QVector<int> > ModelGeometryUtils::triangulate(const QVector<int> &polygonIndices)
{
    QVector<QVector<int> > triangles;

    for(int i = 0; i < polygonIndices.size() - 2; ++i)
        triangles.push_back({0, i + 1, i + 2});

    return triangles;
}

QVector3D ModelGeometryUtils::calculateNormal(int vertexIndex, const QVector<QVector3D> &vertices, const QVector<QVector<int> > &polygonsVerticesIndices)
{
   QVector3D resultingNormal(0, 0, 0);

   for(const QVector<int> &polygon : polygonsVerticesIndices)
       if(polygon.contains(vertexIndex))
           resultingNormal += QVector3D::normal(vertices[polygon[1] - 1] - vertices[polygon[0] - 1], vertices[polygon[2] - 1] - vertices[polygon[1] - 1]);

    return resultingNormal.normalized();
}
