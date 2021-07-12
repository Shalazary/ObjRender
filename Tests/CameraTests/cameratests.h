#ifndef CAMERA_TESTS_H
#define CAMERA_TESTS_H

#include <QtTest>

class CameraTests : public QObject
{
    Q_OBJECT
private slots:
    void validDataTest01();
    void validDataTest02();
    void validDataTest03();

    void invalidDataTest01();
    void invalidDataTest02();
};

#endif
