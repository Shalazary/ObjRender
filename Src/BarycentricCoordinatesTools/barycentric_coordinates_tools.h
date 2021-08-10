#ifndef BARYCENTRIC_COORDINATES_TOOLS_H
#define BARYCENTRIC_COORDINATES_TOOLS_H

#include <QVector2D>
#include <QVector3D>

namespace BarycentricCoordinatesTools {

    QVector3D toBarycentric(const QVector2D &a, const QVector2D &b, const QVector2D &c, const QVector2D &p);

}

#endif
