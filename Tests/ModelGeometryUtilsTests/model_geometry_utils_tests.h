#ifndef MODEL_GEOMETRY_UTILS_TESTS_H
#define MODEL_GEOMETRY_UTILS_TESTS_H

#include <QtTest>

class ModelGeometryUtilsTests: public QObject
{
    Q_OBJECT
private slots:
    void triangulate_test01();
    void triangulate_test02();
    void triangulate_test03();

    void calculateNormal_test01();
    void calculateNormal_test02();
    void calculateNormal_test03();
};

#endif
