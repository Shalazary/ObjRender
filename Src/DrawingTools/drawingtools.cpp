#include "drawingtools.h"
#include "WorldCoordsTools/worldcoordstools.h"

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

void DrawingTools::drawTriangel(QImage &image, QPoint p1, QPoint p2, QPoint p3, QColor color)
{
    if(p1.y() > p2.y())
        std::swap(p1, p2);
    if(p2.y() > p3.y())
        std::swap(p2, p3);
    if(p1.y() > p2.y())
        std::swap(p1, p2);

    int a1 = 0;
    int b1 = 0;
    int a2 = 0;
    int b2 = 0;

    a1 = p2.y() - p1.y();
    b1 = p2.x() - p1.x();
    a2 = p3.y() - p1.y();
    b2 = p3.x() - p1.x();
    if(a1 != 0)
        for(int y = p1.y(); y <= p2.y(); ++y) {
            int x1 = (float)(y - p1.y()) / a1 * b1 + p1.x();
            int x2 = (float)(y - p1.y()) / a2 * b2 + p1.x();
            if(x1 > x2)
                std::swap(x1, x2);
            for(int x = x1; x <= x2; ++x)
                image.setPixelColor(x, y, color);
        }

    a1 = p3.y() - p2.y();
    b1 = p3.x() - p2.x();
    if(a1 != 0)
        for(int y = p2.y(); y <= p3.y(); ++y) {
            int x1 = (float)(y - p2.y()) / a1 * b1 + p2.x();
            int x2 = (float)(y - p1.y()) / a2 * b2 + p1.x();
            if(x1 > x2)
                std::swap(x1, x2);
            for(int x = x1; x <= x2; ++x)
                image.setPixelColor(x, y, color);
        }
}

void DrawingTools::drawTriangel(QImage &image, Point3D p1, Point3D p2, Point3D p3, int **zbuffer, QColor color)
{
    if(p1.y() > p2.y())
        std::swap(p1, p2);
    if(p2.y() > p3.y())
        std::swap(p2, p3);
    if(p1.y() > p2.y())
        std::swap(p1, p2);

    int a1 = 0;
    int b1 = 0;
    int c1 = 0;
    int a2 = 0;
    int b2 = 0;
    int c2 = 0;

    a1 = p2.y() - p1.y();
    b1 = p2.x() - p1.x();
    c1 = p2.z() - p1.z();
    a2 = p3.y() - p1.y();
    b2 = p3.x() - p1.x();
    c2 = p3.z() - p1.z();

    if(a1 != 0 && a2 != 0)
        for(int y = p1.y(); y <= p2.y(); ++y) {
            int x1 = (y - p1.y()) * b1 / a1  + p1.x();
            int x2 = (y - p1.y()) * b2 / a2  + p1.x();
            if(x1 > x2)
                std::swap(x1, x2);
            int z1 = p1.z();
            int z2 = p1.z();
            if(a1 != 0)
                z1 = (y - p1.y()) * c1 / a1 + p1.z();
            if(a2 != 0)
                z2 = (y - p1.y()) * c2 / a2 + p1.z();
            for(int x = x1; x <= x2; ++x) {
                int z = z1;
                if(x1 != x2)
                    z = (x - x1) * (z2 - z1) / (x2 - x1) + z1;
                if(z <= zbuffer[x][y]){
                    zbuffer[x][y] = z;
                    image.setPixelColor(x, y, color);
                }
            }
        }

    a1 = p3.y() - p2.y();
    b1 = p3.x() - p2.x();
    c1 = p3.z() - p2.z();
    if(a1 != 0 && a2 != 0)
        for(int y = p2.y(); y <= p3.y(); ++y) {
            int x1 = (y - p2.y()) * b1 / a1 + p2.x();
            int x2 = (y - p1.y()) * b2 / a2 + p1.x();
            if(x1 > x2)
                std::swap(x1, x2);
            int z1 = p3.z();
            int z2 = p3.z();
            if(b1 != 0)
                z1 = (y - p2.x()) * c1 / b1 + p2.z();
            if(b2 != 0)
                z2 = (y - p1.x()) * c2 / b2 + p1.z();
            for(int x = x1; x <= x2; ++x) {
                int z = z1;
                if(x1 != x2)
                    z = (x - x1) * (z2 - z1) / (x2 - x1) + z1;
                if(z <= zbuffer[x][y]){
                    zbuffer[x][y] = z;
                    image.setPixelColor(x, y, color);
                }
            }
        }
}
