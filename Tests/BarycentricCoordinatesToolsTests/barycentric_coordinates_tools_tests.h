#ifndef BARYCENTRIC_COOEDINATES_TOOLS_TESTS_H
#define BARYCENTRIC_COOEDINATES_TOOLS_TESTS_H

#include <QTest>

class BarycentricCoordinatesToolsTests : public QObject
{
    Q_OBJECT
private slots:
    void toBaricentric_test01();
    void toBaricentric_test02();
    void toBaricentric_test03();
    void toBaricentric_test04();
    void toBaricentric_test05();
};

#endif
