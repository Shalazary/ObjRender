#include "homogeneouscoordinatestoolstests.h"

#include <QMatrix4x4>
#include <QVector4D>
#include <QtMath>

#include "HomogeneousCoordinatesTools/homogeneouscoordinatestools.h"

void HomogeneousCoordinatesToolsTests::lookAt_test01()
{
    // camera has only z coordinate
    const QMatrix4x4 m = HomogeneousCoordinatesTools::lookAt({0, 0, 1}, {0, 0, 0}, {0, 1, 0});
    const QVector4D p1 = {0, 0, 0, 1};
    const QVector4D p2 = {1, 0, 0, 1};
    const QVector4D p3 = {1, 1, 0, 1};
    const QVector4D p4 = {1, 1, 1, 1};

    const QVector4D actual1 = m * p1;
    const QVector4D actual2 = m * p2;
    const QVector4D actual3 = m * p3;
    const QVector4D actual4 = m * p4;

    const QVector4D expected1 = {0, 0, -1, 1};
    const QVector4D expected2 = {1, 0, -1, 1};
    const QVector4D expected3 = {1, 1, -1, 1};
    const QVector4D expected4 = {1, 1, 0, 1};

    QVERIFY(qFuzzyCompare(actual1, expected1));
    QVERIFY(qFuzzyCompare(actual2, expected2));
    QVERIFY(qFuzzyCompare(actual3, expected3));
    QVERIFY(qFuzzyCompare(actual4, expected4));
}

void HomogeneousCoordinatesToolsTests::lookAt_test02()
{
    // camera has x and z coordinates
    const QMatrix4x4 m = HomogeneousCoordinatesTools::lookAt({1, 0, 1}, {0, 0, 0}, {0, 1, 0});
    const QVector4D p1 = {0, 0, 0, 1};
    const QVector4D p2 = {1, 0, 0, 1};
    const QVector4D p3 = {1, 1, 0, 1};
    const QVector4D p4 = {1, 1, 1, 1};

    const QVector4D actual1 = m * p1;
    const QVector4D actual2 = m * p2;
    const QVector4D actual3 = m * p3;
    const QVector4D actual4 = m * p4;

    const QVector4D expected1 = {0, 0, -(float)qSqrt(2), 1};
    const QVector4D expected2 = {(float)qSqrt(2) / 2, 0, -(float)qSqrt(2) / 2, 1};
    const QVector4D expected3 = {(float)qSqrt(2) / 2, 1, -(float)qSqrt(2) / 2, 1};
    const QVector4D expected4 = {0, 1, 0, 1};

    QVERIFY(qFuzzyCompare(actual1, expected1));
    QVERIFY(qFuzzyCompare(actual2, expected2));
    QVERIFY(qFuzzyCompare(actual3, expected3));
    QVERIFY(qFuzzyCompare(actual4, expected4));
}

void HomogeneousCoordinatesToolsTests::lookAt_test03()
{
    // camera has x, y and z coordinates
    const QMatrix4x4 m = HomogeneousCoordinatesTools::lookAt({1, 1, 1}, {0, 0, 0}, {0, 1, 0});
    const QVector4D p1 = {0, 0, 0, 1};
    const QVector4D p2 = {1, 0, 0, 1};
    const QVector4D p3 = {1, 1, 0, 1};
    const QVector4D p4 = {1, 1, 1, 1};

    const QVector4D actual1 = m * p1;
    const QVector4D actual2 = m * p2;
    const QVector4D actual3 = m * p3;
    const QVector4D actual4 = m * p4;

    const QVector4D expected1 = {0, 0, -(float)qSqrt(3), 1};
    const QVector4D expected2 = {(float)qSqrt(2) / 2, -(float)qSqrt(6) / 6, -2 * (float)qSqrt(3) / 3, 1};
    const QVector4D expected3 = {(float)qSqrt(2) / 2, (float)qSqrt(6) / 6, -(float)qSqrt(3) / 3, 1};
    const QVector4D expected4 = {0, 0, 0, 1};

    QVERIFY(qFuzzyCompare(actual1, expected1));
    QVERIFY(qFuzzyCompare(actual2, expected2));
    QVERIFY(qFuzzyCompare(actual3, expected3));
    QVERIFY(qFuzzyCompare(actual4, expected4));
}

void HomogeneousCoordinatesToolsTests::frustum_test01()
{
    const QMatrix4x4 f = HomogeneousCoordinatesTools::frustum(-1, 2, -3, 4, 5, 6);

    // points on edges of near plane
    const QVector4D p1 = {-1, 0, -5, 1};
    const QVector4D p2 = {2, 0, -5, 1};
    const QVector4D p3 = {0, -3, -5, 1};
    const QVector4D p4 = {0, 4, -5, 1};
    const QVector4D p5 = {0, 0, -5, 1};

    const float actual1 = QVector4D(f * p1).toVector3DAffine().x();
    const float actual2 = QVector4D(f * p2).toVector3DAffine().x();
    const float actual3 = QVector4D(f * p3).toVector3DAffine().y();
    const float actual4 = QVector4D(f * p4).toVector3DAffine().y();
    const float actual5 = QVector4D(f * p5).toVector3DAffine().z();

    const float expected1 = -1;
    const float expected2 = 1;
    const float expected3 = -1;
    const float expected4 = 1;
    const float expected5 = -1;

    QCOMPARE(actual1, expected1);
    QCOMPARE(actual2, expected2);
    QCOMPARE(actual3, expected3);
    QCOMPARE(actual4, expected4);
    QCOMPARE(actual5, expected5);
}

void HomogeneousCoordinatesToolsTests::frustum_test02()
{
    const QMatrix4x4 f = HomogeneousCoordinatesTools::frustum(-1, 2, -3, 4, 5, 6);

    // points on edges of far plane
    const QVector4D p1 = {-1.2, 0, -6, 1};
    const QVector4D p2 = {2.4, 0, -6, 1};
    const QVector4D p3 = {0, -3.6, -6, 1};
    const QVector4D p4 = {0, 4.8, -6, 1};
    const QVector4D p5 = {0, 0, -6, 1};

    const float actual1 = QVector4D(f * p1).toVector3DAffine().x();
    const float actual2 = QVector4D(f * p2).toVector3DAffine().x();
    const float actual3 = QVector4D(f * p3).toVector3DAffine().y();
    const float actual4 = QVector4D(f * p4).toVector3DAffine().y();
    const float actual5 = QVector4D(f * p5).toVector3DAffine().z();

    const float expected1 = -1;
    const float expected2 = 1;
    const float expected3 = -1;
    const float expected4 = 1;
    const float expected5 = 1;

    QCOMPARE(actual1, expected1);
    QCOMPARE(actual2, expected2);
    QCOMPARE(actual3, expected3);
    QCOMPARE(actual4, expected4);
    QCOMPARE(actual5, expected5);
}

void HomogeneousCoordinatesToolsTests::frustum_test03()
{
    const QMatrix4x4 f = HomogeneousCoordinatesTools::frustum(-1, 2, -3, 4, 5, 6);

    // points inside clip space
    const QVector4D p1 = {-0.5, -2.5, -5.5, 1};
    const QVector4D p2 = {1.5, 3.5, -5.5, 1};

    const QVector3D actual1 = QVector4D(f * p1).toVector3DAffine();
    const QVector3D actual2 = QVector4D(f * p2).toVector3DAffine();

    const QVector3D expected1 = {-(float)21 / 33, -(float)61 / 77, (float)1 / 11};
    const QVector3D expected2 = {(float)19 / 33, (float)59 / 77, (float)1 / 11};

    QVERIFY(qFuzzyCompare(actual1, expected1));
    QVERIFY(qFuzzyCompare(actual2, expected2));
}

void HomogeneousCoordinatesToolsTests::frustum_test04()
{
    const QMatrix4x4 f = HomogeneousCoordinatesTools::frustum(-1, 2, -3, 4, 5, 6);

    // points outside clip space
    const QVector4D p1 = {-2, -3, -5.5, 1};
    const QVector4D p2 = {-1, -4, -5.5, 1};
    const QVector4D p3 = {-1, -3, -4, 1};

    const QVector3D actual1 = QVector4D(f * p1).toVector3DAffine();
    const QVector3D actual2 = QVector4D(f * p2).toVector3DAffine();
    const QVector3D actual3 = QVector4D(f * p3).toVector3DAffine();

    const QVector3D expected1 = {-(float)51 / 33, -(float)71 / 77 , (float)1 / 11};
    const QVector3D expected2 = {-(float)31 / 33, -(float)91 / 77, (float)1 / 11};
    const QVector3D expected3 = {-(float)14 / 12, -(float)34 / 28, -4};

    QVERIFY(qFuzzyCompare(actual1, expected1));
    QVERIFY(qFuzzyCompare(actual2, expected2));
    QVERIFY(qFuzzyCompare(actual3, expected3));
}

void HomogeneousCoordinatesToolsTests::perspective_test01()
{
    const QMatrix4x4 p = HomogeneousCoordinatesTools::perspective(M_PI_2, (float)1 / 2, 1, 2);

    // points on edges of near plane
    const QVector4D p1 = {-1, 0, -1, 1};
    const QVector4D p2 = {1, 0, -1, 1};
    const QVector4D p3 = {0, -2, -1, 1};
    const QVector4D p4 = {0, 2, -1, 1};
    const QVector4D p5 = {0, 0, -1, 1};

    const float actual1 = QVector4D(p * p1).toVector3DAffine().x();
    const float actual2 = QVector4D(p * p2).toVector3DAffine().x();
    const float actual3 = QVector4D(p * p3).toVector3DAffine().y();
    const float actual4 = QVector4D(p * p4).toVector3DAffine().y();
    const float actual5 = QVector4D(p * p5).toVector3DAffine().z();

    const float expected1 = -1;
    const float expected2 = 1;
    const float expected3 = -1;
    const float expected4 = 1;
    const float expected5 = -1;

    QCOMPARE(actual1, expected1);
    QCOMPARE(actual2, expected2);
    QCOMPARE(actual3, expected3);
    QCOMPARE(actual4, expected4);
    QCOMPARE(actual5, expected5);
}

void HomogeneousCoordinatesToolsTests::perspective_test02()
{
    const QMatrix4x4 p = HomogeneousCoordinatesTools::perspective(M_PI_2, (float)1 / 2, 1, 2);

    // points on edges of far plane
    const QVector4D p1 = {-2, 0, -2, 1};
    const QVector4D p2 = {2, 0, -2, 1};
    const QVector4D p3 = {0, -4, -2, 1};
    const QVector4D p4 = {0, 4, -2, 1};
    const QVector4D p5 = {0, 0, -2, 1};

    const float actual1 = QVector4D(p * p1).toVector3DAffine().x();
    const float actual2 = QVector4D(p * p2).toVector3DAffine().x();
    const float actual3 = QVector4D(p * p3).toVector3DAffine().y();
    const float actual4 = QVector4D(p * p4).toVector3DAffine().y();
    const float actual5 = QVector4D(p * p5).toVector3DAffine().z();

    const float expected1 = -1;
    const float expected2 = 1;
    const float expected3 = -1;
    const float expected4 = 1;
    const float expected5 = 1;

    QCOMPARE(actual1, expected1);
    QCOMPARE(actual2, expected2);
    QCOMPARE(actual3, expected3);
    QCOMPARE(actual4, expected4);
    QCOMPARE(actual5, expected5);
}

void HomogeneousCoordinatesToolsTests::perspective_test03()
{
    const QMatrix4x4 p = HomogeneousCoordinatesTools::perspective(M_PI_2, (float)1 / 2, 1, 2);

    // points inside clip space
    const QVector4D p1 = {0.5, 0.5, -1.5, 1};
    const QVector4D p2 = {-0.5, -1.5, -1.5, 1};

    const QVector3D actual1 = QVector4D(p * p1).toVector3DAffine();
    const QVector3D actual2 = QVector4D(p * p2).toVector3DAffine();

    const QVector3D expected1 = {(float)1 / 3, (float)1 / 6, (float)1 / 3};
    const QVector3D expected2 = {-(float)1 / 3, -(float)1 / 2, (float)1 / 3};

    QVERIFY(qFuzzyCompare(actual1, expected1));
    QVERIFY(qFuzzyCompare(actual2, expected2));
}

void HomogeneousCoordinatesToolsTests::perspective_test04()
{
    const QMatrix4x4 p = HomogeneousCoordinatesTools::perspective(M_PI_2, (float)1 / 2, 1, 2);

    // points outside clip space
    const QVector4D p1 = {2.5, 2.5, -1.5, 1};
    const QVector4D p2 = {-0.5, -1.5, -2.5, 1};

    const QVector3D actual1 = QVector4D(p * p1).toVector3DAffine();
    const QVector3D actual2 = QVector4D(p * p2).toVector3DAffine();

    const QVector3D expected1 = {(float)5 / 3, (float)5 / 6, (float)1 / 3};
    const QVector3D expected2 = {-(float)1 / 5, -(float)3 / 10, (float)7 / 5};

    QVERIFY(qFuzzyCompare(actual1, expected1));
    QVERIFY(qFuzzyCompare(actual2, expected2));
}

void HomogeneousCoordinatesToolsTests::orthographic_test01()
{
    const QMatrix4x4 o = HomogeneousCoordinatesTools::orthographic(-1, 2, -3, 4, 5, 6);

    // points on edges of near plane
    const QVector4D p1 = {-1, 0, -5, 1};
    const QVector4D p2 = {2, 0, -5, 1};
    const QVector4D p3 = {0, -3, -5, 1};
    const QVector4D p4 = {0, 4, -5, 1};
    const QVector4D p5 = {0, 0, -5, 1};

    const float actual1 = QVector4D(o * p1).toVector3DAffine().x();
    const float actual2 = QVector4D(o * p2).toVector3DAffine().x();
    const float actual3 = QVector4D(o * p3).toVector3DAffine().y();
    const float actual4 = QVector4D(o * p4).toVector3DAffine().y();
    const float actual5 = QVector4D(o * p5).toVector3DAffine().z();

    const float expected1 = -1;
    const float expected2 = 1;
    const float expected3 = -1;
    const float expected4 = 1;
    const float expected5 = -1;

    QCOMPARE(actual1, expected1);
    QCOMPARE(actual2, expected2);
    QCOMPARE(actual3, expected3);
    QCOMPARE(actual4, expected4);
    QCOMPARE(actual5, expected5);
}

void HomogeneousCoordinatesToolsTests::orthographic_test02()
{
    const QMatrix4x4 o = HomogeneousCoordinatesTools::orthographic(-1, 2, -3, 4, 5, 6);

    // points on edges of far plane
    const QVector4D p1 = {-1, 0, -6, 1};
    const QVector4D p2 = {2, 0, -6, 1};
    const QVector4D p3 = {0, -3, -6, 1};
    const QVector4D p4 = {0, 4, -6, 1};
    const QVector4D p5 = {0, 0, -6, 1};

    const float actual1 = QVector4D(o * p1).toVector3DAffine().x();
    const float actual2 = QVector4D(o * p2).toVector3DAffine().x();
    const float actual3 = QVector4D(o * p3).toVector3DAffine().y();
    const float actual4 = QVector4D(o * p4).toVector3DAffine().y();
    const float actual5 = QVector4D(o * p5).toVector3DAffine().z();

    const float expected1 = -1;
    const float expected2 = 1;
    const float expected3 = -1;
    const float expected4 = 1;
    const float expected5 = 1;

    QCOMPARE(actual1, expected1);
    QCOMPARE(actual2, expected2);
    QCOMPARE(actual3, expected3);
    QCOMPARE(actual4, expected4);
    QCOMPARE(actual5, expected5);
}

void HomogeneousCoordinatesToolsTests::orthographic_test03()
{
    const QMatrix4x4 o = HomogeneousCoordinatesTools::orthographic(-1, 2, -3, 4, 5, 6);

    // points inside clip space
    const QVector4D p1 = {0.5, -2.5, -5.5, 1};
    const QVector4D p2 = {-0.5, 3.5, -5.5, 1};

    const QVector3D actual1 = QVector4D(o * p1).toVector3DAffine();
    const QVector3D actual2 = QVector4D(o * p2).toVector3DAffine();

    const QVector3D expected1 = {0, -(float)6 / 7, 0};
    const QVector3D expected2 = {-(float)2 / 3, (float)6 / 7, 0};

    QVERIFY(qFuzzyCompare(actual1, expected1));
    QVERIFY(qFuzzyCompare(actual2, expected2));
}

void HomogeneousCoordinatesToolsTests::orthographic_test04()
{
    const QMatrix4x4 o = HomogeneousCoordinatesTools::orthographic(-1, 2, -3, 4, 5, 6);

    // points outside clip space
    const QVector4D p1 = {-1.5, -3.5, -4, 1};
    const QVector4D p2 = {2.5, 4.5, -7, 1};

    const QVector3D actual1 = QVector4D(o * p1).toVector3DAffine();
    const QVector3D actual2 = QVector4D(o * p2).toVector3DAffine();

    const QVector3D expected1 = {-(float)4 / 3, -(float)8 / 7, -3};
    const QVector3D expected2 = {(float)4 / 3, (float)8 / 7, 3};

    QCOMPARE(actual1, expected1);
    QCOMPARE(actual2, expected2);
}

void HomogeneousCoordinatesToolsTests::viewport_test01()
{
    const QMatrix4x4 v = HomogeneousCoordinatesTools::viewport(1080, 1080);

    // 1 point for each corner of ndc cube
    const QVector4D p1 = {1, 1, 1, 1};
    const QVector4D p2 = {1, 1, -1, 1};
    const QVector4D p3 = {1, -1, 1, 1};
    const QVector4D p4 = {-1, 1, 1, 1};
    const QVector4D p5 = {1, -1, -1, 1};
    const QVector4D p6 = {-1, -1, 1, 1};
    const QVector4D p7 = {-1, 1, -1, 1};
    const QVector4D p8 = {-1, -1, -1, 1};

    const QVector3D actual1 = QVector4D(v * p1).toVector3DAffine();
    const QVector3D actual2 = QVector4D(v * p2).toVector3DAffine();
    const QVector3D actual3 = QVector4D(v * p3).toVector3DAffine();
    const QVector3D actual4 = QVector4D(v * p4).toVector3DAffine();
    const QVector3D actual5 = QVector4D(v * p5).toVector3DAffine();
    const QVector3D actual6 = QVector4D(v * p6).toVector3DAffine();
    const QVector3D actual7 = QVector4D(v * p7).toVector3DAffine();
    const QVector3D actual8 = QVector4D(v * p8).toVector3DAffine();

    const QVector3D expected1 = {1079, 0, 1};
    const QVector3D expected2 = {1079, 0, -1};
    const QVector3D expected3 = {1079, 1079, 1};
    const QVector3D expected4 = {0, 0, 1};
    const QVector3D expected5 = {1079, 1079, -1};
    const QVector3D expected6 = {0, 1079, 1};
    const QVector3D expected7 = {0, 0, -1};
    const QVector3D expected8 = {0, 1079, -1};

    QVERIFY(qFuzzyCompare(actual1, expected1));
    QVERIFY(qFuzzyCompare(actual2, expected2));
    QVERIFY(qFuzzyCompare(actual3, expected3));
    QVERIFY(qFuzzyCompare(actual4, expected4));
    QVERIFY(qFuzzyCompare(actual5, expected5));
    QVERIFY(qFuzzyCompare(actual6, expected6));
    QVERIFY(qFuzzyCompare(actual7, expected7));
    QVERIFY(qFuzzyCompare(actual8, expected8));
}

void HomogeneousCoordinatesToolsTests::viewport_test02()
{
    const QMatrix4x4 v = HomogeneousCoordinatesTools::viewport(1080, 1080);

    // points inside ndc cube
    const QVector4D p1 = {0, 0, 0, 1};
    const QVector4D p2 = {0.1, 0.2, 0.3, 1};
    const QVector4D p3 = {-0.4, -0.5, -0.6, 1};

    const QVector3D actual1 = QVector4D(v * p1).toVector3DAffine();
    const QVector3D actual2 = QVector4D(v * p2).toVector3DAffine();
    const QVector3D actual3 = QVector4D(v * p3).toVector3DAffine();

    // maybe it should convert to int for each coordinate
    const QVector3D expected1 = {539.5f, 539.5f, 0};
    const QVector3D expected2 = {593.45f, 431.6f, 0.3};
    const QVector3D expected3 = {323.7f, 809.25f, -0.6};

    QVERIFY(qFuzzyCompare(actual1, expected1));
    QVERIFY(qFuzzyCompare(actual2, expected2));
    QVERIFY(qFuzzyCompare(actual3, expected3));
}

void HomogeneousCoordinatesToolsTests::viewport_test03()
{
    const QMatrix4x4 v = HomogeneousCoordinatesTools::viewport(1080, 1080);

    // points outside ndc cube
    const QVector4D p1 = {1.1, 1.2, 1.3, 1};
    const QVector4D p2 = {-1.4, -1.5, -1.6, 1};

    const QVector3D actual1 = QVector4D(v * p1).toVector3DAffine();
    const QVector3D actual2 = QVector4D(v * p2).toVector3DAffine();

    // maybe it should convert to int for each coordinate
    const QVector3D expected1 = {1132.95f, -107.9f, 1.3};
    const QVector3D expected2 = {-215.8f, 1348.75f, -1.6};

    QVERIFY(qFuzzyCompare(actual1, expected1));
    QVERIFY(qFuzzyCompare(actual2, expected2));
}

void HomogeneousCoordinatesToolsTests::mapTexture_test01()
{
    const int width = 1080;
    const int height = 720;

    const QVector2D p1 = {0.0f, 0.0f};
    const QVector2D p2 = {1.0f, 0.0f};
    const QVector2D p3 = {0.0f, 1.0f};
    const QVector2D p4 = {1.0f, 1.0f};

    const QVector2D actual1 = HomogeneousCoordinatesTools::projectToTexturePixelCoordinates(p1, width, height);
    const QVector2D actual2 = HomogeneousCoordinatesTools::projectToTexturePixelCoordinates(p2, width, height);
    const QVector2D actual3 = HomogeneousCoordinatesTools::projectToTexturePixelCoordinates(p3, width, height);
    const QVector2D actual4 = HomogeneousCoordinatesTools::projectToTexturePixelCoordinates(p4, width, height);

    const QVector2D expected1 = {-0.5, 719.5};
    const QVector2D expected2 = {1079.5, 719.5};
    const QVector2D expected3 = {-0.5, -0.5};
    const QVector2D expected4 = {1079.5, -0.5};

    QCOMPARE(actual1, expected1);
    QCOMPARE(actual2, expected2);
    QCOMPARE(actual3, expected3);
    QCOMPARE(actual4, expected4);
}

void HomogeneousCoordinatesToolsTests::mapTexture_test02()
{

}

void HomogeneousCoordinatesToolsTests::mapTexture_test03()
{

}
