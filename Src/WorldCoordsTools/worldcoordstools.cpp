#include "worldcoordstools.h"

int WorldCoordsTools::worldToScreanX(float x, float left, float right, int width)
{
    if (x <= left || width <= 0)
        return 0;

    if(x >= right)
        return width - 1;

    return (x - left) / (right - left) * width;
}

int WorldCoordsTools::worldToScreanY(float y, float bottom, float top, int height)
{
    if(y >= top || height <= 0)
        return 0;

    if(y <= bottom)
        return height - 1;

    return (top - y) / (top - bottom) * height;
}

int WorldCoordsTools::worldToScreanZ(float z, float near, float far, int depth)
{
    if(z <= near || depth <= 0)
        return 0 ;

    if(z >= far)
        return depth - 1;

    return (z - near) / (far - near) * depth;
}

QVector3D WorldCoordsTools::worldToScrean(
        QVector3D p,
        float left,
        float right,
        float bottom,
        float top,
        float near,
        float far,
        int width,
        int hight,
        int depth)
{
    int x = worldToScreanX(p.x(), left, right, width);
    int y = worldToScreanY(p.y(), bottom, top, hight);
    int z = worldToScreanZ(p.z(), near, far, depth);

    return QVector3D(x, y, z);
}

QVector3D WorldCoordsTools::worldNDCToScrean(QVector3D p, int width, int height, int depth)
{
    return worldToScrean(p, -1, 1, -1, 1, -1, 1, width, height, depth);
}

QVector3D WorldCoordsTools::worldToScrean(QVector3D p, float left, float right, float bottom, float top, float near, float far, QSize windowSize, int depth)
{
    return worldToScrean(p, left, right, bottom, top, near, far, windowSize.width(), windowSize.height(), depth);
}

QVector3D WorldCoordsTools::worldNDCToScrean(QVector3D p, QSize windowSize, int depth)
{
    return worldToScrean(p, -1, 1, -1, 1, -1, 1, windowSize.width(), windowSize.height(), depth);
}

QPoint WorldCoordsTools::worldNDCToScrean(QVector3D p, QSize windowSize)
{
    return worldToScrean(p, -1, 1, -1, 1, -1, 1, windowSize.width(), windowSize.height(), 256).toPoint();
}
