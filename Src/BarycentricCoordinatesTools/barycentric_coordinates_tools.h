#ifndef BARYCENTRIC_COORDINATES_TOOLS_H
#define BARYCENTRIC_COORDINATES_TOOLS_H

#include <QVector2D>
#include <QVector3D>

#include <optional>

namespace BarycentricCoordinatesTools {

std::optional<QVector3D> toBarycentric(
    const QVector2D &trianglePoint1,
    const QVector2D &trianglePoint2,
    const QVector2D &trianglePoint3,
    const QVector2D &conversionPoint);

template<typename T>
std::optional<T> mixByBarycentric(
    const QVector2D &trianglePoint1,
    const QVector2D &trianglePoint2,
    const QVector2D &trianglePoint3,
    const T &dataInPoint1,
    const T &dataInPoint2,
    const T &dataInPoint3,
    const QVector2D &conversionPoint)
{
    std::optional<QVector3D> dataBarycentricCoordinate = toBarycentric(trianglePoint1, trianglePoint2, trianglePoint3, conversionPoint);

    if(!dataBarycentricCoordinate.has_value())
        return std::nullopt;

    return dataInPoint1 * dataBarycentricCoordinate.value()[0] +
           dataInPoint2 * dataBarycentricCoordinate.value()[1] +
           dataInPoint3 * dataBarycentricCoordinate.value()[2];
}

template<typename T>
T mixByBarycentric(
    const T &dataInPoint1,
    const T &dataInPoint2,
    const T &dataInPoint3,
    const QVector3D &dataBarycentricCoordinate)
{
    return dataInPoint1 * dataBarycentricCoordinate[0] +
           dataInPoint2 * dataBarycentricCoordinate[1] +
           dataInPoint3 * dataBarycentricCoordinate[2];
}

bool isPointInsideTriangle(const QVector3D &pointBarycentricCoordinate, float eps = 1e-6);

}

#endif
