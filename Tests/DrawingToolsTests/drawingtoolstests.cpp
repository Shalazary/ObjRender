#include "drawingtoolstests.h"
#include "DrawingTools/drawingtools.h"

#include <QImage>

void DrawingToolsTests::drawLine_test01()
{
    int **zbuffer = new int*[5];
    for(int i = 0; i < 5; ++i)
        zbuffer[i] = new int[5];

    for(int i = 0; i < 5; ++i)
        for(int j = 0; j < 5; ++j)
            zbuffer[i][j] = INT_MAX;

    QImage actual(5, 5, QImage::Format_ARGB32);
    actual.fill(w);

    DrawingTools::drawLine(actual, {0, 0, 2}, {4, 0, 2}, zbuffer, r);
    DrawingTools::drawLine(actual, {4, 0, 1}, {0, 4, 1}, zbuffer, g);
    DrawingTools::drawLine(actual, {0, 4, 0}, {0, 0, 0}, zbuffer, b);

    QImage e(5, 5, QImage::Format_ARGB32);
    e.setPixelColor(0, 0, b); e.setPixelColor(1, 0, r); e.setPixelColor(2, 0, r); e.setPixelColor(3, 0, r); e.setPixelColor(4, 0, g);
    e.setPixelColor(0, 1, b); e.setPixelColor(1, 1, w); e.setPixelColor(2, 1, w); e.setPixelColor(3, 1, g); e.setPixelColor(4, 1, w);
    e.setPixelColor(0, 2, b); e.setPixelColor(1, 2, w); e.setPixelColor(2, 2, g); e.setPixelColor(3, 2, w); e.setPixelColor(4, 2, w);
    e.setPixelColor(0, 3, b); e.setPixelColor(1, 3, g); e.setPixelColor(2, 3, w); e.setPixelColor(3, 3, w); e.setPixelColor(4, 3, w);
    e.setPixelColor(0, 4, b); e.setPixelColor(1, 4, w); e.setPixelColor(2, 4, w); e.setPixelColor(3, 4, w); e.setPixelColor(4, 4, w);

    QCOMPARE(actual, e);
}

void DrawingToolsTests::drawLine_test02()
{
    int **zbuffer = new int*[5];
    for(int i = 0; i < 5; ++i)
        zbuffer[i] = new int[5];

    for(int i = 0; i < 5; ++i)
        for(int j = 0; j < 5; ++j)
            zbuffer[i][j] = INT_MAX;

    QImage actual(5, 5, QImage::Format_ARGB32);
    actual.fill(w);

    DrawingTools::drawLine(actual, {0, 4, 1}, {4, 0, 1}, zbuffer, r);
    DrawingTools::drawLine(actual, {0, 0, 0}, {4, 1, 0}, zbuffer, g);
    DrawingTools::drawLine(actual, {4, 1, 0}, {0, 3, 0}, zbuffer, b);

    QImage e(5, 5, QImage::Format_ARGB32);
    e.setPixelColor(0, 0, g); e.setPixelColor(1, 0, g); e.setPixelColor(2, 0, g); e.setPixelColor(3, 0, g); e.setPixelColor(4, 0, r);
    e.setPixelColor(0, 1, w); e.setPixelColor(1, 1, w); e.setPixelColor(2, 1, w); e.setPixelColor(3, 1, b); e.setPixelColor(4, 1, b);
    e.setPixelColor(0, 2, w); e.setPixelColor(1, 2, b); e.setPixelColor(2, 2, b); e.setPixelColor(3, 2, w); e.setPixelColor(4, 2, w);
    e.setPixelColor(0, 3, b); e.setPixelColor(1, 3, r); e.setPixelColor(2, 3, w); e.setPixelColor(3, 3, w); e.setPixelColor(4, 3, w);
    e.setPixelColor(0, 4, r); e.setPixelColor(1, 4, w); e.setPixelColor(2, 4, w); e.setPixelColor(3, 4, w); e.setPixelColor(4, 4, w);

    QCOMPARE(actual, e);
}

void DrawingToolsTests::drawLine_test03()
{
    int **zbuffer = new int*[5];
    for(int i = 0; i < 5; ++i)
        zbuffer[i] = new int[5];

    for(int i = 0; i < 5; ++i)
        for(int j = 0; j < 5; ++j)
            zbuffer[i][j] = INT_MAX;

    QImage actual(5, 5, QImage::Format_ARGB32);
    actual.fill(w);

    DrawingTools::drawLine(actual, {0, 4, 1}, {4, 0, 1}, zbuffer, r);
    DrawingTools::drawLine(actual, {0, 4, 2}, {4, 0, 0}, zbuffer, g);
    DrawingTools::drawLine(actual, {0, 4, 0}, {4, 0, 2}, zbuffer, b);

    QImage e(5, 5, QImage::Format_ARGB32);
    e.setPixelColor(0, 0, w); e.setPixelColor(1, 0, w); e.setPixelColor(2, 0, w); e.setPixelColor(3, 0, w); e.setPixelColor(4, 0, g);
    e.setPixelColor(0, 1, w); e.setPixelColor(1, 1, w); e.setPixelColor(2, 1, w); e.setPixelColor(3, 1, g); e.setPixelColor(4, 1, w);
    e.setPixelColor(0, 2, w); e.setPixelColor(1, 2, w); e.setPixelColor(2, 2, b); e.setPixelColor(3, 2, w); e.setPixelColor(4, 2, w);
    e.setPixelColor(0, 3, w); e.setPixelColor(1, 3, b); e.setPixelColor(2, 3, w); e.setPixelColor(3, 3, w); e.setPixelColor(4, 3, w);
    e.setPixelColor(0, 4, b); e.setPixelColor(1, 4, w); e.setPixelColor(2, 4, w); e.setPixelColor(3, 4, w); e.setPixelColor(4, 4, w);

    QCOMPARE(actual, e);
}

void DrawingToolsTests::drawTriangle_test01()
{

}

void DrawingToolsTests::drawTriangle_test02()
{

}

void DrawingToolsTests::drawTriangle_test03()
{

}

void DrawingToolsTests::test()
{
    int imgSize = 512;

    QImage i(imgSize, imgSize, QImage::Format_ARGB32);
    i.fill(Qt::red);

    QImage t(imgSize, imgSize, QImage::Format_ARGB32);
    t.load("../obj/1.png");

    float **zbuffer = new float*[imgSize];
    for(int i = 0; i < imgSize; ++i)
        zbuffer[i] = new float[imgSize];

    for(int i = 0; i < imgSize; ++i)
        for(int j = 0; j < imgSize; ++j)
            zbuffer[i][j] = 2.0f;

    DrawingTools::drawTriangel(i, {-1, 1, 0, 1}, {1, 1, 0, 1}, {-1, -1, 0, 1}, {0, 1}, {1, 1}, {0, 0}, t, zbuffer);
    DrawingTools::drawTriangel(i, {1, -1, 0, 1}, {1, 1, 0, 1}, {-1, -1, 0, 1}, {1, 0}, {1, 1}, {0, 0}, t, zbuffer);
    i.save("t.png");
}
