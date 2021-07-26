#include "worldcoordstoolstests.h"
#include "WorldCoordsTools/worldcoordstools.h"

void WorldCoordsToolsTests::worldToScreanX_test01()
{
    float left = -10;
    float right = 10;
    float width = 1080;

    float data1 = 1;
    float data2 = -1;
    float data3 = 2.5;
    float data4 = -2.5;

    int actual1 = WorldCoordsTools::worldToScreanX(data1, left, right, width);
    int actual2 = WorldCoordsTools::worldToScreanX(data2, left, right, width);
    int actual3 = WorldCoordsTools::worldToScreanX(data3, left, right, width);
    int actual4 = WorldCoordsTools::worldToScreanX(data4, left, right, width);

    int expected1 = 594;
    int expected2 = 486;
    int expected3 = 675;
    int expected4 = 405;

    QCOMPARE(actual1, expected1);
    QCOMPARE(actual2, expected2);
    QCOMPARE(actual3, expected3);
    QCOMPARE(actual4, expected4);
}

void WorldCoordsToolsTests::worldToScreanX_test02()
{
    float left =  1.1;
    float right = 10.15;
    float width = 1080;

    float data1 = 1.2;
    float data2 = 2.5;

    int actual1 = WorldCoordsTools::worldToScreanX(data1, left, right, width);
    int actual2 = WorldCoordsTools::worldToScreanX(data2, left, right, width);

    int expected1 = 11;
    int expected2 = 167;

    QCOMPARE(actual1, expected1);
    QCOMPARE(actual2, expected2);
}

void WorldCoordsToolsTests::worldToScreanX_test03()
{
    float left =  1.1;
    float right = 10.15;
    float width = 1080;

    float data1 = -1;
    float data2 = 11;

    int actual1 = WorldCoordsTools::worldToScreanX(data1, left, right, width);
    int actual2 = WorldCoordsTools::worldToScreanX(data2, left, right, width);

    int expected1 = 0;
    int expected2 = 1079;

    QCOMPARE(actual1, expected1);
    QCOMPARE(actual2, expected2);
}

void WorldCoordsToolsTests::worldToScreanX_test04()
{
    float left =  1.1;
    float right = 10.15;
    float width = 1080;

    float data1 = 1.1;
    float data2 = 10.15;

    int actual1 = WorldCoordsTools::worldToScreanX(data1, left, right, width);
    int actual2 = WorldCoordsTools::worldToScreanX(data2, left, right, width);

    int expected1 = 0;
    int expected2 = 1079;

    QCOMPARE(actual1, expected1);
    QCOMPARE(actual2, expected2);
}



void WorldCoordsToolsTests::worldToScreanY_test01()
{
    float bottom = -10;
    float top = 10;
    float height = 1080;

    float data1 = 1;
    float data2 = -1;
    float data3 = 2.5;
    float data4 = -2.5;

    int actual1 = WorldCoordsTools::worldToScreanY(data1, bottom, top, height);
    int actual2 = WorldCoordsTools::worldToScreanY(data2, bottom, top, height);
    int actual3 = WorldCoordsTools::worldToScreanY(data3, bottom, top, height);
    int actual4 = WorldCoordsTools::worldToScreanY(data4, bottom, top, height);

    int expected1 = 486;
    int expected2 = 594;
    int expected3 = 405;
    int expected4 = 675;

    QCOMPARE(actual1, expected1);
    QCOMPARE(actual2, expected2);
    QCOMPARE(actual3, expected3);
    QCOMPARE(actual4, expected4);
}

void WorldCoordsToolsTests::worldToScreanY_test02()
{
    float bottom = -10;
    float top = -1.25;
    float height = 1080;

    float data1 = -5;
    float data2 = -2.5;

    int actual1 = WorldCoordsTools::worldToScreanY(data1, bottom, top, height);
    int actual2 = WorldCoordsTools::worldToScreanY(data2, bottom, top, height);

    int expected1 = 462;
    int expected2 = 154;

    QCOMPARE(actual1, expected1);
    QCOMPARE(actual2, expected2);
}

void WorldCoordsToolsTests::worldToScreanY_test03()
{
    float bottom = -10;
    float top = -1.25;
    float height = 1080;

    float data1 = 1;
    float data2 = -15;

    int actual1 = WorldCoordsTools::worldToScreanY(data1, bottom, top, height);
    int actual2 = WorldCoordsTools::worldToScreanY(data2, bottom, top, height);

    int expected1 = 0;
    int expected2 = 1079;

    QCOMPARE(actual1, expected1);
    QCOMPARE(actual2, expected2);
}


void WorldCoordsToolsTests::worldToScreanY_test04()
{
    float bottom = -10;
    float top = -1.25;
    float height = 1080;

    float data1 = -10;
    float data2 = -1.25;

    int actual1 = WorldCoordsTools::worldToScreanY(data1, bottom, top, height);
    int actual2 = WorldCoordsTools::worldToScreanY(data2, bottom, top, height);

    int expected1 = 1079;
    int expected2 = 0;

    QCOMPARE(actual1, expected1);
    QCOMPARE(actual2, expected2);
}


void WorldCoordsToolsTests::worldToScreanZ_test01()
{
    float near = -10;
    float far = 10;
    float depth = 1080;

    float data1 = 1;
    float data2 = 0;
    float data3 = -2.5;
    float data4 = 9;

    int actual1 = WorldCoordsTools::worldToScreanZ(data1, near, far, depth);
    int actual2 = WorldCoordsTools::worldToScreanZ(data2, near, far, depth);
    int actual3 = WorldCoordsTools::worldToScreanZ(data3, near, far, depth);
    int actual4 = WorldCoordsTools::worldToScreanZ(data4, near, far, depth);

    int expected1 = 594;
    int expected2 = 540;
    int expected3 = 405;
    int expected4 = 1026;

    QCOMPARE(actual1, expected1);
    QCOMPARE(actual2, expected2);
    QCOMPARE(actual3, expected3);
    QCOMPARE(actual4, expected4);
}

void WorldCoordsToolsTests::worldToScreanZ_test02()
{
    float near = -2;
    float far = 10;
    float depth = 1080;

    float data1 = 1;
    float data2 = 9;

    int actual1 = WorldCoordsTools::worldToScreanZ(data1, near, far, depth);
    int actual2 = WorldCoordsTools::worldToScreanZ(data2, near, far, depth);

    int expected1 = 270;
    int expected2 = 990;

    QCOMPARE(actual1, expected1);
    QCOMPARE(actual2, expected2);
}

void WorldCoordsToolsTests::worldToScreanZ_test03()
{
    float near = -2;
    float far = 10;
    float depth = 1080;

    float data1 = -2.5;
    float data2 = 11;

    int actual1 = WorldCoordsTools::worldToScreanZ(data1, near, far, depth);
    int actual2 = WorldCoordsTools::worldToScreanZ(data2, near, far, depth);

    int expected1 = 0;
    int expected2 = 1079;

    QCOMPARE(actual1, expected1);
    QCOMPARE(actual2, expected2);
}

void WorldCoordsToolsTests::worldToScreanZ_test04()
{
    float near = -2;
    float far = 10;
    float depth = 1080;

    float data1 = -2;
    float data2 = 10;

    int actual1 = WorldCoordsTools::worldToScreanZ(data1, near, far, depth);
    int actual2 = WorldCoordsTools::worldToScreanZ(data2, near, far, depth);

    int expected1 = 0;
    int expected2 = 1079;

    QCOMPARE(actual1, expected1);
    QCOMPARE(actual2, expected2);
}
