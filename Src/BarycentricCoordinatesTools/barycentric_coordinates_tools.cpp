#include "barycentric_coordinates_tools.h"

std::optional<QVector3D> BarycentricCoordinatesTools::toBarycentric(
    const QVector2D &trianglePoint1,
    const QVector2D &trianglePoint2,
    const QVector2D &trianglePoint3,
    const QVector2D &conversionPoint)
{
    // A is point1
    // B is point2
    // C is point3
    // P is conversion point
    const QVector2D ab = trianglePoint2 - trianglePoint1;
    const QVector2D ac = trianglePoint3 - trianglePoint1;
    const QVector2D pa = trianglePoint1 - conversionPoint;

    const QVector3D v1 = {ab.x(), ac.x(), pa.x()};
    const QVector3D v2 = {ab.y(), ac.y(), pa.y()};

    QVector3D result = QVector3D::crossProduct(v1, v2);

    if(qFuzzyIsNull(result.z()))
        return std::nullopt;

    result /= result.z();
    result.setZ(1 - result.x() - result.y());

    return QVector3D(result.z(), result.x(), result.y());
}

bool BarycentricCoordinatesTools::isPointInsideTriangle(const QVector3D &pointBarycentricCoordinate, float eps)
{
    return (pointBarycentricCoordinate[0] >= 0.0f - eps) && (pointBarycentricCoordinate[0] <= 1.0f + eps) &&
           (pointBarycentricCoordinate[1] >= 0.0f - eps) && (pointBarycentricCoordinate[1] <= 1.0f + eps) &&
           (pointBarycentricCoordinate[2] >= 0.0f - eps) && (pointBarycentricCoordinate[2] <= 1.0f + eps);
}
