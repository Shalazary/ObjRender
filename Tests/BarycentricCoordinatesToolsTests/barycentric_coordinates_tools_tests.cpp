#include "barycentric_coordinates_tools_tests.h"

#include <QVector3D>

#include "BarycentricCoordinatesTools/barycentric_coordinates_tools.h"

void BarycentricCoordinatesToolsTests::toBaricentric_test01()
{
    // points in vertices
    const QVector2D a = {0, 0};
    const QVector2D b = {1, 0};
    const QVector2D c = {1, 1};
    const QVector2D p1 = {0, 0};
    const QVector2D p2 = {1, 0};
    const QVector2D p3 = {1, 1};

    const QVector3D actual1 = BarycentricCoordinatesTools::toBarycentric(a, b, c, p1);
    const QVector3D actual2 = BarycentricCoordinatesTools::toBarycentric(a, b, c, p2);
    const QVector3D actual3 = BarycentricCoordinatesTools::toBarycentric(a, b, c, p3);

    const QVector3D expected1 = {0, 0, 1};
    const QVector3D expected2 = {1, 0, 0};
    const QVector3D expected3 = {0, 1, 0};

    QVERIFY(qFuzzyCompare(actual1, expected1));
    QVERIFY(qFuzzyCompare(actual2, expected2));
    QVERIFY(qFuzzyCompare(actual3, expected3));
}

void BarycentricCoordinatesToolsTests::toBaricentric_test02()
{
    // points on edges
    const QVector2D a = {0, 0};
    const QVector2D b = {1, 0};
    const QVector2D c = {1, 1};
    const QVector2D p1 = {1.0f, 0.5f};
    const QVector2D p2 = {0.5f, 0};
    const QVector2D p3 = {0.5f, 0.5f};

    const QVector3D actual1 = BarycentricCoordinatesTools::toBarycentric(a, b, c, p1);
    const QVector3D actual2 = BarycentricCoordinatesTools::toBarycentric(a, b, c, p2);
    const QVector3D actual3 = BarycentricCoordinatesTools::toBarycentric(a, b, c, p3);

    const QVector3D expected1 = {0.5f, 0.5f, 0.0f};
    const QVector3D expected2 = {0.5f, 0.0f, 0.5f};
    const QVector3D expected3 = {0.0f, 0.5f, 0.5f};

    QVERIFY(qFuzzyCompare(actual1, expected1));
    QVERIFY(qFuzzyCompare(actual2, expected2));
    QVERIFY(qFuzzyCompare(actual3, expected3));
}

void BarycentricCoordinatesToolsTests::toBaricentric_test03()
{
    // point inside triangel
    const QVector2D a = {0, 0};
    const QVector2D b = {1, 0};
    const QVector2D c = {1, 1};
    const QVector2D p = {0.5f, 0.25f};

    const QVector3D actual = BarycentricCoordinatesTools::toBarycentric(a, b, c, p);

    const QVector3D expected = {0.25f, 0.25f, 0.5f};

    QVERIFY(qFuzzyCompare(actual, expected));
}

void BarycentricCoordinatesToolsTests::toBaricentric_test04()
{
    // point outside triangel
    const QVector2D a = {0, 0};
    const QVector2D b = {1, 0};
    const QVector2D c = {0.5, 1};
    const QVector2D p = {0.25f, 0.75f};

    const QVector3D actual = BarycentricCoordinatesTools::toBarycentric(a, b, c, p);

    QVERIFY(qFuzzyCompare(p, actual[2] * a + actual[0] * b + actual[1] * c));
}

void BarycentricCoordinatesToolsTests::toBaricentric_test05()
{
    const QVector2D a = {0, 0};
    const QVector2D b = {1, 0};
    const QVector2D c = {0.5, 0};
    const QVector2D p = {0.25f, 0.75f};

    const QVector3D actual = BarycentricCoordinatesTools::toBarycentric(a, b, c, p);

    QVERIFY(qFuzzyCompare(p, actual[2] * a + actual[0] * b + actual[1] * c));
}
