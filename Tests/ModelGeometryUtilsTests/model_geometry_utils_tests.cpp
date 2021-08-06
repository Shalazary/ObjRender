#include "model_geometry_utils_tests.h"
#include "ModelGeometry/Utils/utils.h"

#include <QVector>

void ModelGeometryUtilsTests::triangulate_test01()
{
    QVector<int> polygon = {0, 1, 2};

    QVector<QVector<int>> actual = ModelGeometryUtils::triangulate(polygon);

    QVector<QVector<int>> expected = {{0, 1, 2}};

    QCOMPARE(actual, expected);
}

void ModelGeometryUtilsTests::triangulate_test02()
{
    QVector<int> polygon = {2, 3, 5, 8};

    QVector<QVector<int>> actual = ModelGeometryUtils::triangulate(polygon);

    QVector<QVector<int>> expected = {{0, 1, 2}, {0, 2, 3}};

    QCOMPARE(actual, expected);
}

void ModelGeometryUtilsTests::triangulate_test03()
{
    QVector<int> polygon = {2, 3, 5, 8, 0};

    QVector<QVector<int>> actual = ModelGeometryUtils::triangulate(polygon);

    QVector<QVector<int>> expected = {{0, 1, 2}, {0, 2, 3}, {0, 3, 4}};

    QCOMPARE(actual, expected);
}

void ModelGeometryUtilsTests::calculateNormal_test01()
{
    QVector<QVector3D> vertices = {
        {-1, 1, 0},
        {0, 0, 0},
        {1, 1, 0},
        {1, -1, 0},
        {-1, -1, 0}
    };

    QVector<QVector<int>> polygons = {
        {2, 4, 3},
        {5, 2, 1}
    };

    QVector3D actual = ModelGeometryUtils::calculateNormal(2, vertices, polygons);

    QVector3D expected = {0, 0, 1};

    QCOMPARE(actual, expected);
}

void ModelGeometryUtilsTests::calculateNormal_test02()
{
    QVector<QVector3D> vertices = {
        {-1, 1, -1},
        {0, 0, 0},
        {1, 1, -1},
        {1, -1, -1},
        {-1, -1, -1}
    };

    QVector<QVector<int>> polygons = {
        {2, 4, 3},
        {5, 2, 1}
    };

    QVector3D actual = ModelGeometryUtils::calculateNormal(2, vertices, polygons);

    QVector3D expected = {0, 0, 1};

    QCOMPARE(actual, expected);
}

void ModelGeometryUtilsTests::calculateNormal_test03()
{
    QVector<QVector3D> vertices = {
        {0, 2, -1},
        {1, 1, 0},
        {2, 2, -1},
        {2, 0, -1},
        {0, 0, -1}
    };

    QVector<QVector<int>> polygons = {
        {2, 4, 3},
        {5, 2, 1}
    };

    QVector3D actual = ModelGeometryUtils::calculateNormal(2, vertices, polygons);

    QVector3D expected = {0, 0, 1};

    QCOMPARE(actual, expected);
}
