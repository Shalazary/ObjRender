#include "shapedrawingtools.h"

#include <optional>
#include <algorithm>

#include "HomogeneousCoordinatesTools/homogeneouscoordinatestools.h"
#include "BarycentricCoordinatesTools/barycentric_coordinates_tools.h"
#include "ImageTools/image_tools.h"

void ShapeDrawingTools::drawLine(QImage &image, int x1, int y1, int z1, int x2, int y2, int z2, int **zbuffer, const QColor &color)
{
    const int dx = x2 - x1;
    const int dy = y2 - y1;
    const int dz = z2 - z1;

    float a = 0;
    float b = 0;
    if(std::abs(dx) > std::abs(dy)) {
        if (x1 > x2) {
            std::swap(x1, x2);
            std::swap(y1, y2);
            std::swap(z1, z2);
        }
        a = (float)dy / dx;
        b = (float)dz / dx;
        float y = y1;
        float z = z1;
        for(int x = x1; x <= x2; ++x) {
            if(z <= zbuffer[x][(int)y]){
                zbuffer[x][(int)y] = z;
                image.setPixelColor(x, y, color);
            }
            y += a;
            z += b;
        }
    } else {
        if(y1 > y2) {
            std::swap(x1, x2);
            std::swap(y1, y2);
            std::swap(z1, z2);
        }
        a = (float)dx / dy;
        b = (float)dz / dy;
        float x = x1;
        float z = z1;
        for(int y = y1; y <= y2; ++y) {
            if(z <= zbuffer[(int)x][y]) {
                zbuffer[(int)x][y] = z;
                image.setPixelColor(x, y, color);
            }
            x += a;
            z += b;
        }
    }
}

void ShapeDrawingTools::drawLine(QImage &image, int x1, int y1, int x2, int y2, const QColor &color)
{
    const int dx = x2 - x1;
    const int dy = y2 - y1;

    float a = 0;
    if(std::abs(dx) > std::abs(dy)) {
        if (x1 > x2) {
            std::swap(x1, x2);
            std::swap(y1, y2);
        }
        a = (float)dy / dx;
        float y = y1;
        for(int x = x1; x <= x2; ++x) {
            image.setPixelColor(x, y, color);
            y += a;
        }
    } else {
        if(y1 > y2) {
            std::swap(x1, x2);
            std::swap(y1, y2);
        }
        a = (float)dx / dy;
        float x = x1;
        for(int y = y1; y <= y2; ++y) {
            image.setPixelColor(x, y, color);
            x += a;
        }
    }
}

void ShapeDrawingTools::drawLine(QImage &image, const QPoint &p1, const QPoint &p2, const QColor &color) {
    ShapeDrawingTools::drawLine(image, p1.x(), p1.y(), p2.x(), p2.y(), color);
}

void ShapeDrawingTools::drawTriangle(
    QImage &image,
    Array2D::Array2D<float> &zbuffer,
    const QVector4D &v1,
    const QVector4D &v2,
    const QVector4D &v3,
    DrawingTools::AbstractPixelColorGetter *colorGetter)
{
    const QVector3D projectedPoint1 = v1.toVector3DAffine();
    const QVector3D projectedPoint2 = v2.toVector3DAffine();
    const QVector3D projectedPoint3 = v3.toVector3DAffine();

    const QVector2D pixelPoint1 = HomogeneousCoordinatesTools::projectToScreenPixelCoordinates(projectedPoint1, image.size());
    const QVector2D pixelPoint2 = HomogeneousCoordinatesTools::projectToScreenPixelCoordinates(projectedPoint2, image.size());
    const QVector2D pixelPoint3 = HomogeneousCoordinatesTools::projectToScreenPixelCoordinates(projectedPoint3, image.size());

    const int maxX = std::max({pixelPoint1.x(), pixelPoint2.x(), pixelPoint3.x()});
    const int minX = std::min({pixelPoint1.x(), pixelPoint2.x(), pixelPoint3.x()});
    const int maxY = std::max({pixelPoint1.y(), pixelPoint2.y(), pixelPoint3.y()});
    const int minY = std::min({pixelPoint1.y(), pixelPoint2.y(), pixelPoint3.y()});

    for(int y = minY; y <= maxY; ++y)
        for(int x = minX; x <= maxX; ++x) {
            const QVector2D pixelPoint(x, y);

            const std::optional<QVector3D> optPointBarycentricCoord =  BarycentricCoordinatesTools::toBarycentric(pixelPoint1, pixelPoint2, pixelPoint3, pixelPoint);

            if(!optPointBarycentricCoord.has_value())
                return;

            const QVector3D pointBarycentricCoord = optPointBarycentricCoord.value();

            if(!BarycentricCoordinatesTools::isPointInsideTriangle(pointBarycentricCoord))
                continue;

            const float pointDepth = BarycentricCoordinatesTools::mixByBarycentric<float>(
                projectedPoint1.z(),
                projectedPoint2.z(),
                projectedPoint3.z(),
                pointBarycentricCoord);

            const bool isPointVisibleByDepth = (pointDepth <= zbuffer(x, y));
            if(!isPointVisibleByDepth)
                continue;

            zbuffer(x, y) = pointDepth;

            image.setPixelColor(x, y, colorGetter->getPixelColor(pointBarycentricCoord));
        }
}
