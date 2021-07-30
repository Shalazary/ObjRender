#include "drawingtools.h"
#include "WorldCoordsTools/worldcoordstools.h"
#include "HomogeneousCoordinatesTools/homogeneouscoordinatestools.h"
#include "BarycentricCoordinatesTools/barycentric_coordinates_tools.h"

int max(int a, int b, int c)
{
    int max = a;
    max = b > max ? b : max;
    max = c > max ? c : max;

    return max;
}

int min(int a, int b, int c)
{
    int min = a;
    min = b < min ? b : min;
    min = c < min ? c : min;

    return min;
}

void DrawingTools::drawLine(QImage &image, int x1, int y1, int z1, int x2, int y2, int z2, int **zbuffer, QColor color)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int dz = z2 - z1;

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

void DrawingTools::drawLine(QImage &image, int x1, int y1, int x2, int y2, QColor color)
{
    int dx = x2 - x1;
    int dy = y2 - y1;

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

void DrawingTools::drawLine(QImage &image, QPoint p1, QPoint p2, QColor color) {
    DrawingTools::drawLine(image, p1.x(), p1.y(), p2.x(), p2.y(), color);
}


void DrawingTools::drawLine(QImage &image, Point3D p1, Point3D p2, int **zbuffer, QColor color)
{
    drawLine(image, p1.x(), p1.y(), p1.z(), p2.x(), p2.y(), p2.z(), zbuffer, color);
}

void DrawingTools::drawTriangel(
    QImage &image,
    const QVector4D &v1, const QVector4D &v2, const QVector4D &v3,
    const QVector2D &vt1, const QVector2D &vt2, const QVector2D &vt3,
    const QVector3D &vn1, const QVector3D &vn2, const QVector3D &vn3,
    const QVector3D &lightDirection,
    const QImage &texture,
    float **zbuffer
)
{   
    const QVector3D p1 = v1.toVector3DAffine();
    const QVector3D p2 = v2.toVector3DAffine();
    const QVector3D p3 = v3.toVector3DAffine();

    const QMatrix4x4 viewport = HomogeneousCoordinatesTools::viewport(image.width(), image.height());
    QVector2D ps1 = QVector4D(viewport * p1).toVector2D();
    QVector2D ps2 = QVector4D(viewport * p2).toVector2D();
    QVector2D ps3 = QVector4D(viewport * p3).toVector2D();

    int maxX = max(ps1.x(), ps2.x(), ps3.x());
    int minX = min(ps1.x(), ps2.x(), ps3.x());
    int maxY = max(ps1.y(), ps2.y(), ps3.y());
    int minY = min(ps1.y(), ps2.y(), ps3.y());

    for(int y = minY; y <= maxY; ++y)
        for(int x = minX; x <= maxX; ++x) {
            QVector2D p = {(float)x, (float)y};
            QVector3D b = BarycentricCoordinatesTools::toBarycentric(ps1, ps2, ps3, p);

            float z = b[2] * p1.z() + b[0] * p2.z() + b[1] * p3.z();

            QVector2D t = b[2] * vt1 + b[0] * vt2 + b[1] * vt3;
            QVector2D ts = HomogeneousCoordinatesTools::mapTexture(t, texture.width(), texture.height());

            float intensity = 1;
            if(!lightDirection.isNull()) {
                QVector3D n = QVector3D(b[2] * vn1 + b[0] * vn2 + b[1] * vn3).normalized();
                intensity = QVector3D::dotProduct(n, lightDirection);
            }

            if((b[0] < 1.0f || qFuzzyCompare(b[0], 1.0f)) && (b[0] > 0.0f || qFuzzyIsNull(b[0])) &&
               (b[1] < 1.0f || qFuzzyCompare(b[1], 1.0f)) && (b[1] > 0.0f || qFuzzyIsNull(b[1])) &&
               (b[2] < 1.0f || qFuzzyCompare(b[2], 1.0f)) && (b[2] > 0.0f || qFuzzyIsNull(b[2])) &&
               z <= zbuffer[x][y] &&
               intensity > 0) {
                zbuffer[x][y] = z;
                QColor origColor = texture.pixelColor(ts.x(), ts.y());
                QColor mixedColor = QColor(origColor.red() * intensity, origColor.green() * intensity, origColor.blue() * intensity, origColor.alpha());
                image.setPixelColor(x, y, mixedColor);
            }
        }
}

void DrawingTools::drawTriangel(
    QImage &image,
    const QVector4D &v1, const QVector4D &v2, const QVector4D &v3,
    const QVector2D &vt1, const QVector2D &vt2, const QVector2D &vt3,
    const QImage &texture,
    float **zbuffer
)
{
    drawTriangel(image, v1, v2, v3, vt1, vt2, vt3, QVector3D(), QVector3D(), QVector3D(), QVector3D(0, 0, 0), texture, zbuffer);
}

void DrawingTools::drawTriangel(
    QImage &image,
    const QVector4D &v1, const QVector4D &v2, const QVector4D &v3,
    const QVector3D &vn1, const QVector3D &vn2, const QVector3D &vn3,
    const QVector3D &lightDirection,
    const QColor &color,
    float **zbuffer
)
{
    QImage colorImage = QImage(1, 1, QImage::Format_ARGB32);
    colorImage.fill(color);
    drawTriangel(image, v1, v2, v3, QVector2D(), QVector2D(), QVector2D(), vn1, vn2, vn3, lightDirection, colorImage, zbuffer);
}



void DrawingTools::drawTriangel(
    QImage &image,
    const QVector4D &v1, const QVector4D &v2, const QVector4D &v3,
    const QColor &color,
    float **zbuffer
)
{
    QImage colorImage = QImage(1, 1, QImage::Format_ARGB32);
    colorImage.fill(color);
    drawTriangel(image, v1, v2, v3, QVector2D(), QVector2D(), QVector2D(), QVector3D(), QVector3D(), QVector3D(), QVector3D(0, 0, 0), colorImage, zbuffer);
}
