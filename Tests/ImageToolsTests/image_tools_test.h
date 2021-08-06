#ifndef IMAGE_TOOLS_TESTS_H
#define IMAGE_TOOLS_TESTS_H

#include <QtTest>
#include <QImage>

class ImageToolsTest : public QObject
{
    Q_OBJECT
private:
    QImage img;
private slots:
    void initTestCase();
    void bilinear_test01();
    void bilinear_test02();
    void bilinear_test03();
};

#endif
