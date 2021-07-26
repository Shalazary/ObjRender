#include "cameratests.h"
#include "Camera/camera.h"

#include <QtMath>

void CameraTests::camera_viewMatrix_test01()
{
    // zero translation, zero rotation
    Camera camera;
    camera.setPos(0, 0, 0);
    camera.setTarget(0, 0, -1);
    camera.setUp(0, 1, 0);

    QMatrix4x4 actual = camera.view();

    QMatrix4x4 expected = {
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };

    QVERIFY(qFuzzyCompare(actual, expected));
}

void CameraTests::camera_viewMatrix_test02()
{
    // only translation
    Camera camera;
    camera.setPos(1, 2, 3);
    camera.setTarget(1, 2, 0);
    camera.setUp(0, 1, 0);

    QMatrix4x4 actual = camera.view();

    QMatrix4x4 expected = {
        1.0f, 0.0f, 0.0f, -1.0f,
        0.0f, 1.0f, 0.0f, -2.0f,
        0.0f, 0.0f, 1.0f, -3.0f,
        0.0f, 0.0f, 0.0f,  1.0f
    };

    QVERIFY(qFuzzyCompare(actual, expected));
}

void CameraTests::camera_viewMatrix_test03()
{
    // only rotation
    Camera camera;
    camera.setPos(0, 0, 0);
    camera.setTarget(1, 0, 1);
    camera.setUp(0, 1, 0);

    QMatrix4x4 actual = camera.view();

    QMatrix4x4 expected = {
        -(float)qSqrt(2) / 2, 0.0f,  (float)qSqrt(2) / 2, 0.0f,
                        0.0f, 1.0f,                 0.0f, 0.0f,
        -(float)qSqrt(2) / 2, 0.0f, -(float)qSqrt(2) / 2, 0.0f,
                        0.0f, 0.0f,                 0.0f, 1.0f
    };

    QVERIFY(qFuzzyCompare(actual, expected));
}

void CameraTests::camera_orthoMatrix_test01()
{
    // cube
    Camera camera(CameraMode::Orthographic);
    camera.setLeft(-1);
    camera.setRight(1);
    camera.setBottom(-1);
    camera.setTop(1);
    camera.setNear(1);
    camera.setFar(2);

    QMatrix4x4 actual = camera.projection();

    QMatrix4x4 expected = {
        1.0f, 0.0f,  0.0f,  0.0f,
        0.0f, 1.0f,  0.0f,  0.0f,
        0.0f, 0.0f, -2.0f, -3.0f,
        0.0f, 0.0f,  0.0f,  1.0f
    };

    QVERIFY(qFuzzyCompare(actual, expected));
}

void CameraTests::camera_orthoMatrix_test02()
{
    // asymmetric parallelepiped
    Camera camera(CameraMode::Orthographic);
    camera.setLeft(-1);
    camera.setRight(2);
    camera.setBottom(-3);
    camera.setTop(4);
    camera.setNear(5);
    camera.setFar(6);

    QMatrix4x4 actual = camera.projection();

    QMatrix4x4 expected = {
        2.0f / 3.0f,        0.0f,  0.0f,  -1.0f / 3.0f,
               0.0f, 2.0f / 7.0f,  0.0f,  -1.0f / 7.0f,
               0.0f,        0.0f, -2.0f,        -11.0f,
               0.0f,        0.0f,  0.0f,          1.0f
    };

    QVERIFY(qFuzzyCompare(actual, expected));
}

void CameraTests::camera_perspectiveMatrix_test01()
{
    Camera camera(CameraMode::Perspective);
    camera.setFov(M_PI_2);
    camera.setAspectRatio(1);
    camera.setNear(1);
    camera.setFar(2);

    QMatrix4x4 actual = camera.projection();

    QMatrix4x4 expected = {
        1.0f, 0.0f,  0.0f,  0.0f,
        0.0f, 1.0f,  0.0f,  0.0f,
        0.0f, 0.0f, -3.0f, -4.0f,
        0.0f, 0.0f, -1.0f,  0.0f
    };

    QVERIFY(qFuzzyCompare(actual, expected));
}

void CameraTests::camera_perspectiveMatrix_test02()
{
    Camera camera(CameraMode::Perspective);
    camera.setFov(M_PI / 3.0f);
    camera.setAspectRatio(2);
    camera.setNear(2);
    camera.setFar(3);

    QMatrix4x4 actual = camera.projection();

    QMatrix4x4 expected = {
        (float)qSqrt(3.0f),                      0.0f,  0.0f,   0.0f,
                      0.0f, 2.0f * (float)qSqrt(3.0f),  0.0f,   0.0f,
                      0.0f,                      0.0f, -5.0f, -12.0f,
                      0.0f,                      0.0f, -1.0f,   0.0f
    };

    QVERIFY(qFuzzyCompare(actual, expected));
}

void CameraTests::camera_frustumMatrix_test01()
{
    // cube
    Camera camera(CameraMode::Frustum);
    camera.setLeft(-1);
    camera.setRight(1);
    camera.setBottom(-1);
    camera.setTop(1);
    camera.setNear(1);
    camera.setFar(2);

    QMatrix4x4 actual = camera.projection();

    QMatrix4x4 expected = {
        1.0f, 0.0f,  0.0f,  0.0f,
        0.0f, 1.0f,  0.0f,  0.0f,
        0.0f, 0.0f, -3.0f, -4.0f,
        0.0f, 0.0f, -1.0f,  0.0f
    };

    QVERIFY(qFuzzyCompare(actual, expected));
}

void CameraTests::camera_frustumMatrix_test02()
{
    // asymmetric parallelepiped
    Camera camera(CameraMode::Frustum);
    camera.setLeft(-1);
    camera.setRight(2);
    camera.setBottom(-3);
    camera.setTop(4);
    camera.setNear(5);
    camera.setFar(6);

    QMatrix4x4 actual = camera.projection();

    QMatrix4x4 expected = {
        10.0f / 3.0f,         0.0f,  1.0f / 3.0f,   0.0f,
                0.0f, 10.0f / 7.0f,  1.0f / 7.0f,   0.0f,
                0.0f,         0.0f,       -11.0f, -60.0f,
                0.0f,         0.0f,        -1.0f,   0.0f
    };

    QVERIFY(qFuzzyCompare(actual, expected));
}
