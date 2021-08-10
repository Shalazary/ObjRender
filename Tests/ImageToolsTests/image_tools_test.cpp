#include "image_tools_test.h"

#include <QVector2D>

#include "ImageTools/image_tools.h"

void ImageToolsTest::initTestCase()
{
    img = QImage(2, 2, QImage::Format_ARGB32);
    img.setPixelColor(0, 0, Qt::red); img.setPixelColor(1, 0, Qt::green);
    img.setPixelColor(0, 1, Qt::blue); img.setPixelColor(1, 1, Qt::transparent);
}

void ImageToolsTest::bilinear_test01()
{
    // point inside pixel
    QVector2D point = {0.75f, 0.25f};

    QColor actual = ImageTools::getPixelColorBilinear(img, point);

    QColor expected(255.0f * 3.0f / 16.0f, 255.0f * 9.0f / 16.0f, 255.0f * 1.0f / 16.0f, 255.0f * 13.0f / 16.0f);

    QCOMPARE(actual, expected);
}

void ImageToolsTest::bilinear_test02()
{
    // points on x bounds
   QVector2D point1 = {0.0f, 0.25f};
   QVector2D point2 = {1.0f, 0.75f};

   QColor actual1 = ImageTools::getPixelColorBilinear(img, point1);
   QColor actual2 = ImageTools::getPixelColorBilinear(img, point2);

   QColor expected1(255.0f * 12.0f / 16.0f, 0.0f, 255.0f * 4.0f / 16.0f, 255.0f);
   QColor expected2(0.0f, 255.0f * 4.0f / 16.0f, 0.0f, 255.0f * 4.0f / 16.0f);

   QCOMPARE(actual1, expected1);
   QCOMPARE(actual2, expected2);
}

void ImageToolsTest::bilinear_test03()
{
    // points on y bounds
    QVector2D point1 = {0.25f, 0.0f};
    QVector2D point2 = {0.75f, 1.0f};

    QColor actual1 = ImageTools::getPixelColorBilinear(img, point1);
    QColor actual2 = ImageTools::getPixelColorBilinear(img, point2);

    QColor expected1(255.0f * 12.0f / 16.0f, 255.0f * 4.0f / 16.0f, 0.0f, 255.0f);
    QColor expected2(0.0f, 0.0f, 255.0f * 4.0f / 16.0f, 255.0f * 4.0f / 16.0f);

    QCOMPARE(actual1, expected1);
    QCOMPARE(actual2, expected2);
}
