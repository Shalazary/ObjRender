#include "barycentric_coordinates_tools.h"

QVector3D BarycentricCoordinatesTools::toBarycentric(const QVector2D &a, const QVector2D &b, const QVector2D &c, const QVector2D &p)
{
    const QVector2D ab = b - a;
    const QVector2D ac = c - a;
    const QVector2D pa = a - p;

    const QVector3D v1 = {ab.x(), ac.x(), pa.x()};
    const QVector3D v2 = {ab.y(), ac.y(), pa.y()};

    //! REVIEW: check for Z == 0
    QVector3D result = QVector3D::crossProduct(v1, v2);
    result /= result.z();
    result.setZ(1 - result.x() - result.y());

    return result;
}
