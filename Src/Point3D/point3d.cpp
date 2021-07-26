 #include "point3d.h"

Point3D::Point3D(int x, int y, int z) : m_x(x), m_y(y), m_z(z)
{

}

Point3D::Point3D(const QVector3D &vec) : m_x(vec.x()), m_y(vec.y()), m_z(vec.z())
{

}

Point3D Point3D::operator +(const Point3D &p)
{
    return Point3D(m_x + p.x(), m_y + p.y(), m_z + p.z());
}

Point3D Point3D::operator -(const Point3D &p)
{
    return Point3D(m_x - p.x(), m_y - p.y(), m_z - p.z());
}

Point3D Point3D::operator *(double m)
{
    return Point3D(m_x * m, m_y * m, m_z * m);
}

QVector3D Point3D::toVector3D()
{
    return QVector3D(m_x, m_y, m_z);
}

int Point3D::x() const
{
    return m_x;
}

void Point3D::setX(int x)
{
    m_x = x;
}

int Point3D::y() const
{
    return m_y;
}

void Point3D::setY(int y)
{
    m_y = y;
}

int Point3D::z() const
{
    return m_z;
}

void Point3D::setZ(int z)
{
    m_z = z;
}
