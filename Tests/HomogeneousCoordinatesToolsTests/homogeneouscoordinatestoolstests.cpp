#include "homogeneouscoordinatestoolstests.h"
#include "HomogeneousCoordinatesTools/homogeneouscoordinatestools.h"

#include <QMatrix4x4>
#include <QVector4D>
#include <QtMath>

void HomogeneousCoordinatesToolsTests::lookAt_test01()
{
    // camera has only z coordinate
    QMatrix4x4 m = HomogeneousCoordinatesTools::lookAt({0, 0, 1}, {0, 0, 0}, {0, 1, 0});
    QVector4D p1 = {0, 0, 0, 1};
    QVector4D p2 = {1, 0, 0, 1};
    QVector4D p3 = {1, 1, 0, 1};
    QVector4D p4 = {1, 1, 1, 1};

    QVector4D actual1 = m * p1;
    QVector4D actual2 = m * p2;
    QVector4D actual3 = m * p3;
    QVector4D actual4 = m * p4;

    QVector4D expected1 = {0, 0, -1, 1};
    QVector4D expected2 = {1, 0, -1, 1};
    QVector4D expected3 = {1, 1, -1, 1};
    QVector4D expected4 = {1, 1, 0, 1};

    QCOMPARE(actual1, expected1);
    QCOMPARE(actual2, expected2);
    QCOMPARE(actual3, expected3);
    QCOMPARE(actual4, expected4);
}

void HomogeneousCoordinatesToolsTests::lookAt_test02()
{
    // camera has x and z coordinates
    QMatrix4x4 m = HomogeneousCoordinatesTools::lookAt({1, 0, 1}, {0, 0, 0}, {0, 1, 0});
    QVector4D p1 = {0, 0, 0, 1};
    QVector4D p2 = {1, 0, 0, 1};
    QVector4D p3 = {1, 1, 0, 1};
    QVector4D p4 = {1, 1, 1, 1};

    QVector4D actual1 = m * p1;
    QVector4D actual2 = m * p2;
    QVector4D actual3 = m * p3;
    QVector4D actual4 = m * p4;

    QVector4D expected1 = {0, 0, -(float)qSqrt(2), 1};
    QVector4D expected2 = {(float)qSqrt(2) / 2, 0, -(float)qSqrt(2) / 2, 1};
    QVector4D expected3 = {(float)qSqrt(2) / 2, 1, -(float)qSqrt(2) / 2, 1};
    QVector4D expected4 = {0, 1, 0, 1};

    QCOMPARE(actual1, expected1);
    QCOMPARE(actual2, expected2);
    QCOMPARE(actual3, expected3);
    QCOMPARE(actual4, expected4);
}

void HomogeneousCoordinatesToolsTests::lookAt_test03()
{
    // camera has x, y and z coordinates
    QMatrix4x4 m = HomogeneousCoordinatesTools::lookAt({1, 1, 1}, {0, 0, 0}, {0, 1, 0});
    QVector4D p1 = {0, 0, 0, 1};
    QVector4D p2 = {1, 0, 0, 1};
    QVector4D p3 = {1, 1, 0, 1};
    QVector4D p4 = {1, 1, 1, 1};

    QVector4D actual1 = m * p1;
    QVector4D actual2 = m * p2;
    QVector4D actual3 = m * p3;
    QVector4D actual4 = m * p4;

    QVector4D expected1 = {0, 0, -(float)qSqrt(3), 1};
    QVector4D expected2 = {(float)qSqrt(2) / 2, -(float)qSqrt(6) / 6, -2 * (float)qSqrt(3) / 3, 1};
    QVector4D expected3 = {(float)qSqrt(2) / 2, (float)qSqrt(6) / 6, -(float)qSqrt(3) / 3, 1};
    QVector4D expected4 = {0, 0, 0, 1};

    QCOMPARE(actual1, expected1);
    QCOMPARE(actual2, expected2);
    QCOMPARE(actual3, expected3);
    QCOMPARE(actual4, expected4);
}

void HomogeneousCoordinatesToolsTests::frustum_test01()
{
    QMatrix4x4 f = HomogeneousCoordinatesTools::frustum(-1, 2, -3, 4, 5, 6);

    // points on edges of near plane
    QVector4D p1 = {-1, 0, -5, 1};
    QVector4D p2 = {2, 0, -5, 1};
    QVector4D p3 = {0, -3, -5, 1};
    QVector4D p4 = {0, 4, -5, 1};
    QVector4D p5 = {0, 0, -5, 1};

    float actual1 = QVector4D(f * p1).toVector3DAffine().x();
    float actual2 = QVector4D(f * p2).toVector3DAffine().x();
    float actual3 = QVector4D(f * p3).toVector3DAffine().y();
    float actual4 = QVector4D(f * p4).toVector3DAffine().y();
    float actual5 = QVector4D(f * p5).toVector3DAffine().z();

    float expected1 = -1;
    float expected2 = 1;
    float expected3 = -1;
    float expected4 = 1;
    float expected5 = -1;

    QCOMPARE(actual1, expected1);
    QCOMPARE(actual2, expected2);
    QCOMPARE(actual3, expected3);
    QCOMPARE(actual4, expected4);
    QCOMPARE(actual5, expected5);
}

void HomogeneousCoordinatesToolsTests::frustum_test02()
{
    QMatrix4x4 f = HomogeneousCoordinatesTools::frustum(-1, 2, -3, 4, 5, 6);

    // points on edges of far plane
    QVector4D p1 = {-1.2, 0, -6, 1};
    QVector4D p2 = {2.4, 0, -6, 1};
    QVector4D p3 = {0, -3.6, -6, 1};
    QVector4D p4 = {0, 4.8, -6, 1};
    QVector4D p5 = {0, 0, -6, 1};

    float actual1 = QVector4D(f * p1).toVector3DAffine().x();
    float actual2 = QVector4D(f * p2).toVector3DAffine().x();
    float actual3 = QVector4D(f * p3).toVector3DAffine().y();
    float actual4 = QVector4D(f * p4).toVector3DAffine().y();
    float actual5 = QVector4D(f * p5).toVector3DAffine().z();

    float expected1 = -1;
    float expected2 = 1;
    float expected3 = -1;
    float expected4 = 1;
    float expected5 = 1;

    QCOMPARE(actual1, expected1);
    QCOMPARE(actual2, expected2);
    QCOMPARE(actual3, expected3);
    QCOMPARE(actual4, expected4);
    QCOMPARE(actual5, expected5);
}

void HomogeneousCoordinatesToolsTests::frustum_test03()
{
    QMatrix4x4 f = HomogeneousCoordinatesTools::frustum(-1, 2, -3, 4, 5, 6);

    // points inside clip space
    QVector4D p1 = {-0.5, -2.5, -5.5, 1};
    QVector4D p2 = {1.5, 3.5, -5.5, 1};

    QVector3D actual1 = QVector4D(f * p1).toVector3DAffine();
    QVector3D actual2 = QVector4D(f * p2).toVector3DAffine();

    QVector3D expected1 = {-(float)21 / 33, -(float)61 / 77, (float)1 / 11};
    QVector3D expected2 = {(float)19 / 33, (float)59 / 77, (float)1 / 11};

    QCOMPARE(actual1, expected1);
    QCOMPARE(actual2, expected2);
}

void HomogeneousCoordinatesToolsTests::frustum_test04()
{
    QMatrix4x4 f = HomogeneousCoordinatesTools::frustum(-1, 2, -3, 4, 5, 6);

    // points outside clip space
    QVector4D p1 = {-2, -3, -5.5, 1};
    QVector4D p2 = {-1, -4, -5.5, 1};
    QVector4D p3 = {-1, -3, -4, 1};

    QVector3D actual1 = QVector4D(f * p1).toVector3DAffine();
    QVector3D actual2 = QVector4D(f * p2).toVector3DAffine();
    QVector3D actual3 = QVector4D(f * p3).toVector3DAffine();

    QVector3D expected1 = {-(float)51 / 33, -(float)71 / 77 , (float)1 / 11};
    QVector3D expected2 = {-(float)31 / 33, -(float)91 / 77, (float)1 / 11};
    QVector3D expected3 = {-(float)14 / 12, -(float)34 / 28, -4};

    QCOMPARE(actual1, expected1);
    QCOMPARE(actual2, expected2);
    QCOMPARE(actual3, expected3);
}

void HomogeneousCoordinatesToolsTests::perspective_test01()
{
    QMatrix4x4 p = HomogeneousCoordinatesTools::perspective(M_PI_2, (float)1 / 2, 1, 2);

    // points on edges of near plane
    QVector4D p1 = {-1, 0, -1, 1};
    QVector4D p2 = {1, 0, -1, 1};
    QVector4D p3 = {0, -2, -1, 1};
    QVector4D p4 = {0, 2, -1, 1};
    QVector4D p5 = {0, 0, -1, 1};

    float actual1 = QVector4D(p * p1).toVector3DAffine().x();
    float actual2 = QVector4D(p * p2).toVector3DAffine().x();
    float actual3 = QVector4D(p * p3).toVector3DAffine().y();
    float actual4 = QVector4D(p * p4).toVector3DAffine().y();
    float actual5 = QVector4D(p * p5).toVector3DAffine().z();

    float expected1 = -1;
    float expected2 = 1;
    float expected3 = -1;
    float expected4 = 1;
    float expected5 = -1;

    QCOMPARE(actual1, expected1);
    QCOMPARE(actual2, expected2);
    QCOMPARE(actual3, expected3);
    QCOMPARE(actual4, expected4);
    QCOMPARE(actual5, expected5);
}

void HomogeneousCoordinatesToolsTests::perspective_test02()
{
    QMatrix4x4 p = HomogeneousCoordinatesTools::perspective(M_PI_2, (float)1 / 2, 1, 2);

    // points on edges of far plane
    QVector4D p1 = {-2, 0, -2, 1};
    QVector4D p2 = {2, 0, -2, 1};
    QVector4D p3 = {0, -4, -2, 1};
    QVector4D p4 = {0, 4, -2, 1};
    QVector4D p5 = {0, 0, -2, 1};

    float actual1 = QVector4D(p * p1).toVector3DAffine().x();
    float actual2 = QVector4D(p * p2).toVector3DAffine().x();
    float actual3 = QVector4D(p * p3).toVector3DAffine().y();
    float actual4 = QVector4D(p * p4).toVector3DAffine().y();
    float actual5 = QVector4D(p * p5).toVector3DAffine().z();

    float expected1 = -1;
    float expected2 = 1;
    float expected3 = -1;
    float expected4 = 1;
    float expected5 = 1;

    QCOMPARE(actual1, expected1);
    QCOMPARE(actual2, expected2);
    QCOMPARE(actual3, expected3);
    QCOMPARE(actual4, expected4);
    QCOMPARE(actual5, expected5);
}

void HomogeneousCoordinatesToolsTests::perspective_test03()
{
    QMatrix4x4 p = HomogeneousCoordinatesTools::perspective(M_PI_2, (float)1 / 2, 1, 2);

    // points inside clip space
    QVector4D p1 = {0.5, 0.5, -1.5, 1};
    QVector4D p2 = {-0.5, -1.5, -1.5, 1};

    QVector3D actual1 = QVector4D(p * p1).toVector3DAffine();
    QVector3D actual2 = QVector4D(p * p2).toVector3DAffine();

    QVector3D expected1 = {(float)1 / 3, (float)1 / 6, (float)1 / 3};
    QVector3D expected2 = {-(float)1 / 3, -(float)1 / 2, (float)1 / 3};

    QCOMPARE(actual1, expected1);
    QCOMPARE(actual2, expected2);
}

void HomogeneousCoordinatesToolsTests::perspective_test04()
{
    QMatrix4x4 p = HomogeneousCoordinatesTools::perspective(M_PI_2, (float)1 / 2, 1, 2);

    // points outside clip space
    QVector4D p1 = {2.5, 2.5, -1.5, 1};
    QVector4D p2 = {-0.5, -1.5, -2.5, 1};

    QVector3D actual1 = QVector4D(p * p1).toVector3DAffine();
    QVector3D actual2 = QVector4D(p * p2).toVector3DAffine();

    QVector3D expected1 = {(float)5 / 3, (float)5 / 6, (float)1 / 3};
    QVector3D expected2 = {-(float)1 / 5, -(float)3 / 10, (float)7 / 5};

    QCOMPARE(actual1, expected1);
    QCOMPARE(actual2, expected2);
}

void HomogeneousCoordinatesToolsTests::orthographic_test01()
{
    QMatrix4x4 o = HomogeneousCoordinatesTools::orthographic(-1, 2, -3, 4, 5, 6);

    // points on edges of near plane
    QVector4D p1 = {-1, 0, -5, 1};
    QVector4D p2 = {2, 0, -5, 1};
    QVector4D p3 = {0, -3, -5, 1};
    QVector4D p4 = {0, 4, -5, 1};
    QVector4D p5 = {0, 0, -5, 1};

    float actual1 = QVector4D(o * p1).toVector3DAffine().x();
    float actual2 = QVector4D(o * p2).toVector3DAffine().x();
    float actual3 = QVector4D(o * p3).toVector3DAffine().y();
    float actual4 = QVector4D(o * p4).toVector3DAffine().y();
    float actual5 = QVector4D(o * p5).toVector3DAffine().z();

    float expected1 = -1;
    float expected2 = 1;
    float expected3 = -1;
    float expected4 = 1;
    float expected5 = -1;

    QCOMPARE(actual1, expected1);
    QCOMPARE(actual2, expected2);
    QCOMPARE(actual3, expected3);
    QCOMPARE(actual4, expected4);
    QCOMPARE(actual5, expected5);
}

void HomogeneousCoordinatesToolsTests::orthographic_test02()
{
    QMatrix4x4 o = HomogeneousCoordinatesTools::orthographic(-1, 2, -3, 4, 5, 6);

    // points on edges of far plane
    QVector4D p1 = {-1, 0, -6, 1};
    QVector4D p2 = {2, 0, -6, 1};
    QVector4D p3 = {0, -3, -6, 1};
    QVector4D p4 = {0, 4, -6, 1};
    QVector4D p5 = {0, 0, -6, 1};

    float actual1 = QVector4D(o * p1).toVector3DAffine().x();
    float actual2 = QVector4D(o * p2).toVector3DAffine().x();
    float actual3 = QVector4D(o * p3).toVector3DAffine().y();
    float actual4 = QVector4D(o * p4).toVector3DAffine().y();
    float actual5 = QVector4D(o * p5).toVector3DAffine().z();

    float expected1 = -1;
    float expected2 = 1;
    float expected3 = -1;
    float expected4 = 1;
    float expected5 = 1;

    QCOMPARE(actual1, expected1);
    QCOMPARE(actual2, expected2);
    QCOMPARE(actual3, expected3);
    QCOMPARE(actual4, expected4);
    QCOMPARE(actual5, expected5);
}

void HomogeneousCoordinatesToolsTests::orthographic_test03()
{
    QMatrix4x4 o = HomogeneousCoordinatesTools::orthographic(-1, 2, -3, 4, 5, 6);

    // points inside clip space
    QVector4D p1 = {0.5, -2.5, -5.5, 1};
    QVector4D p2 = {-0.5, 3.5, -5.5, 1};

    QVector3D actual1 = QVector4D(o * p1).toVector3DAffine();
    QVector3D actual2 = QVector4D(o * p2).toVector3DAffine();

    QVector3D expected1 = {0, -(float)6 / 7, 0};
    QVector3D expected2 = {-(float)2 / 3, (float)6 / 7, 0};

    QCOMPARE(actual1, expected1);
    QCOMPARE(actual2, expected2);
}

void HomogeneousCoordinatesToolsTests::orthographic_test04()
{
    QMatrix4x4 o = HomogeneousCoordinatesTools::orthographic(-1, 2, -3, 4, 5, 6);

    // points outside clip space
    QVector4D p1 = {-1.5, -3.5, -4, 1};
    QVector4D p2 = {2.5, 4.5, -7, 1};

    QVector3D actual1 = QVector4D(o * p1).toVector3DAffine();
    QVector3D actual2 = QVector4D(o * p2).toVector3DAffine();

    QVector3D expected1 = {-(float)4 / 3, -(float)8 / 7, -3};
    QVector3D expected2 = {(float)4 / 3, (float)8 / 7, 3};

    QCOMPARE(actual1, expected1);
    QCOMPARE(actual2, expected2);
}

void HomogeneousCoordinatesToolsTests::viewport_test01()
{
    QMatrix4x4 v = HomogeneousCoordinatesTools::viewport(1080, 1080, 256);

    // 1 point for each corner of ndc cube
    QVector4D p1 = {1, 1, 1, 1};
    QVector4D p2 = {1, 1, -1, 1};
    QVector4D p3 = {1, -1, 1, 1};
    QVector4D p4 = {-1, 1, 1, 1};
    QVector4D p5 = {1, -1, -1, 1};
    QVector4D p6 = {-1, -1, 1, 1};
    QVector4D p7 = {-1, 1, -1, 1};
    QVector4D p8 = {-1, -1, -1, 1};

    QVector3D actual1 = QVector4D(v * p1).toVector3DAffine();
    QVector3D actual2 = QVector4D(v * p2).toVector3DAffine();
    QVector3D actual3 = QVector4D(v * p3).toVector3DAffine();
    QVector3D actual4 = QVector4D(v * p4).toVector3DAffine();
    QVector3D actual5 = QVector4D(v * p5).toVector3DAffine();
    QVector3D actual6 = QVector4D(v * p6).toVector3DAffine();
    QVector3D actual7 = QVector4D(v * p7).toVector3DAffine();
    QVector3D actual8 = QVector4D(v * p8).toVector3DAffine();

    QVector3D expected1 = {1079, 0, 255};
    QVector3D expected2 = {1079, 0, 0};
    QVector3D expected3 = {1079, 1079, 255};
    QVector3D expected4 = {0, 0, 255};
    QVector3D expected5 = {1079, 1079, 0};
    QVector3D expected6 = {0, 1079, 255};
    QVector3D expected7 = {0, 0, 0};
    QVector3D expected8 = {0, 1079, 0};

    QCOMPARE(actual1, expected1);
    QCOMPARE(actual2, expected2);
    QCOMPARE(actual3, expected3);
    QCOMPARE(actual4, expected4);
    QCOMPARE(actual5, expected5);
    QCOMPARE(actual6, expected6);
    QCOMPARE(actual7, expected7);
    QCOMPARE(actual8, expected8);
}

void HomogeneousCoordinatesToolsTests::viewport_test02()
{
    QMatrix4x4 v = HomogeneousCoordinatesTools::viewport(1080, 1080, 256);

    // points inside ndc cube
    QVector4D p1 = {0, 0, 0, 1};
    QVector4D p2 = {0.1, 0.2, 0.3, 1};
    QVector4D p3 = {-0.4, -0.5, -0.6, 1};

    QVector3D actual1 = QVector4D(v * p1).toVector3DAffine();
    QVector3D actual2 = QVector4D(v * p2).toVector3DAffine();
    QVector3D actual3 = QVector4D(v * p3).toVector3DAffine();

    // maybe it should convert to int for each coordinate
    QVector3D expected1 = {539.5f, 539.5f, 127.5f};
    QVector3D expected2 = {593.45f, 431.6f, 165.75f};
    QVector3D expected3 = {323.7f, 809.25f, 51.0f};

    QCOMPARE(actual1, expected1);
    QCOMPARE(actual2, expected2);
    QCOMPARE(actual3, expected3);
}

void HomogeneousCoordinatesToolsTests::viewport_test03()
{
    QMatrix4x4 v = HomogeneousCoordinatesTools::viewport(1080, 1080, 256);

    // points outside ndc cube
    QVector4D p1 = {1.1, 1.2, 1.3, 1};
    QVector4D p2 = {-1.4, -1.5, -1.6, 1};

    QVector3D actual1 = QVector4D(v * p1).toVector3DAffine();
    QVector3D actual2 = QVector4D(v * p2).toVector3DAffine();

    // maybe it should convert to int for each coordinate
    QVector3D expected1 = {1132.95f, -107.9f, 293.25f};
    QVector3D expected2 = {-215.8f, 1348.75f, -76.5f};

    QCOMPARE(actual1, expected1);
    QCOMPARE(actual2, expected2);
}