#ifndef MODEL_GEOMETRY_UTILS_H
#define MODEL_GEOMETRY_UTILS_H

#include <QVector3D>
#include <QVector>

namespace ModelGeometryUtils {

QVector<QVector<int>> triangulate(const QVector<int> &polygonIndices);
QVector3D calculateNormal(int vertexIndex, const QVector<QVector3D> &vertices, const QVector<QVector<int>> &polygonsVerticesIndices);
}

#endif
