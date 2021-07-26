#ifndef CAMERA_TESTS_H
#define CAMERA_TESTS_H

#include <QtTest>

class CameraTests : public QObject
{
    Q_OBJECT
private slots:
    void camera_viewMatrix_test01();
    void camera_viewMatrix_test02();
    void camera_viewMatrix_test03();

    void camera_orthoMatrix_test01();
    void camera_orthoMatrix_test02();

    void camera_perspectiveMatrix_test01();
    void camera_perspectiveMatrix_test02();

    void camera_frustumMatrix_test01();
    void camera_frustumMatrix_test02();
};

#endif
