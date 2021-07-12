#include "drawingtools.h"
#include "WorldCoordsTools/worldcoordstools.h"

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

void NDCDrawingTools::drawLine(QImage &image, QVector3D p1, QVector3D p2, int **zbuffer, QColor color, int zbufferDepth)
{
    p1 = WorldCoordsTools::worldNDCToScrean(p1, image.size(), zbufferDepth);
    p2 = WorldCoordsTools::worldNDCToScrean(p2, image.size(), zbufferDepth);

    int dx = p2.x() - p1.x();
    int dy = p2.y() - p1.y();

    float a = 0;
    if(std::abs(dx) > std::abs(dy)) {
        if (p1.x() > p2.x())
            std::swap(p1, p2);
        a = (float)dy / dx;
        float y = p1.y();
        for(int x = p1.x(); x <= p2.x(); ++x) {
            image.setPixelColor(x, y, color);
            y += a;
        }
    } else {
        if(p1.y() > p2.y())
            std::swap(p1, p2);
        a = (float)dx / dy;
        float x = p1.x();
        for(int y = p1.y(); y <= p2.y(); ++y) {
            image.setPixelColor(x, y, color);
            x += a;
        }
    }
}

void NDCDrawingTools::drawTriangel(QImage &image, QVector3D p1, QVector3D p2, QVector3D p3, int **zbuffer, QColor color, int zbufferDepth)
{
    p1 = WorldCoordsTools::worldNDCToScrean(p1, image.size(), zbufferDepth);
    p2 = WorldCoordsTools::worldNDCToScrean(p2, image.size(), zbufferDepth);
    p3 = WorldCoordsTools::worldNDCToScrean(p3, image.size(), zbufferDepth);

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
    if(a1 != 0)
        for(int y = p1.y(); y <= p2.y(); ++y) {
            int x1 = (float)(y - p1.y()) / a1 * b1 + p1.x();
            int z1 = (float)(y - p1.y()) / a1 * c1 + p1.z();
            int x2 = (float)(y - p1.y()) / a2 * b2 + p1.x();
            int z2 = (float)(y - p1.y()) / a2 * c2 + p1.z();

            float a = (float)(z2 - z1) / (x2 - x1);

            float z = z1;

            if(x1 > x2)
                std::swap(x1, x2);
            for(int x = x1; x <= x2; ++x) {
                if(z > zbuffer[x][y]) {
                    image.setPixelColor(x, y, color);
                    zbuffer[x][y] = z;
                }
                z += a;
            }
        }

    a1 = p3.y() - p2.y();
    b1 = p3.x() - p2.x();
    c1 = p3.z() - p2.z();
    if(a1 != 0)
        for(int y = p2.y(); y <= p3.y(); ++y) {
            int x1 = (float)(y - p2.y()) / a1 * b1 + p2.x();
            int z1 = (float)(y - p2.y()) / a1 * c1 + p2.z();
            int x2 = (float)(y - p1.y()) / a2 * b2 + p1.x();
            int z2 = (float)(y - p1.y()) / a2 * c2 + p1.z();

            float a = (float)(z2 - z1) / (x2 - x1);

            float z = z1;

            if(x1 > x2)
                std::swap(x1, x2);
            for(int x = x1; x <= x2; ++x) {
                if(z > zbuffer[x][y]) {
                    image.setPixelColor(x, y, color);
                    zbuffer[x][y] = z;
                }
                z += a;
            }
        }
}
