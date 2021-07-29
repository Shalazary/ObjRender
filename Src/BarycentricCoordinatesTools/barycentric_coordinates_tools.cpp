#include "barycentric_coordinates_tools.h"

QVector3D BarycentricCoordinatesTools::toBarycentric(const QVector2D &a, const QVector2D &b, const QVector2D &c, const QVector2D &p)
{
    QVector2D ab = b - a;
    QVector2D ac = c - a;
    QVector2D pa = a - p;

    QVector3D v1 = {ab.x(), ac.x(), pa.x()};
    QVector3D v2 = {ab.y(), ac.y(), pa.y()};
    QVector3D result = QVector3D::crossProduct(v1, v2);
    result /= result.z();
    result.setZ(1 - result.x() - result.y());

    return result;
}
