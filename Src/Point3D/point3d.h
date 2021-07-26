#ifndef POINT3D_H
#define POINT3D_H

#include <QVector3D>

class Point3D
{
public:
    Point3D() = default;
    Point3D(int x, int y, int z);
    Point3D(const QVector3D &vec);

    Point3D operator +(const Point3D &p);
    Point3D operator -(const Point3D &p);
    Point3D operator *(double m);

    QVector3D toVector3D();

    int x() const;
    void setX(int x);

    int y() const;
    void setY(int y);

    int z() const;
    void setZ(int z);

private:
    int m_x = 0;
    int m_y = 0;
    int m_z = 0;
};

#endif
