#ifndef DRAWING_TOOLS_TESTS_H
#define DRAWING_TOOLS_TESTS_H

#include <QtTest>

class DrawingToolsTests : public QObject
{
    Q_OBJECT
private:
    const QColor r = Qt::red;
    const QColor g = Qt::green;
    const QColor b = Qt::blue;
    const QColor w = Qt::white;

private slots:
    void drawLine_test01();
    void drawLine_test02();
    void drawLine_test03();

    void drawTriangle_test01();
    void drawTriangle_test02();
    void drawTriangle_test03();
};

#endif
