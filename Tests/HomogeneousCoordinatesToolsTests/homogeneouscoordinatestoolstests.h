#ifndef HOMOGENEOUS_COORDINATES_TOOLS_TESTS_H
#define HOMOGENEOUS_COORDINATES_TOOLS_TESTS_H

#include <QtTest>

class HomogeneousCoordinatesToolsTests : public QObject
{
    Q_OBJECT
private slots:
    void lookAt_test01();
    void lookAt_test02();
    void lookAt_test03();

    void frustum_test01();
    void frustum_test02();
    void frustum_test03();
    void frustum_test04();

    void perspective_test01();
    void perspective_test02();
    void perspective_test03();
    void perspective_test04();

    void orthographic_test01();
    void orthographic_test02();
    void orthographic_test03();
    void orthographic_test04();

    void viewport_test01();
    void viewport_test02();
    void viewport_test03();
};

#endif
