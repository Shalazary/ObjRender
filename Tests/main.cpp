#include "ObjReadingToolsTests/objreadingtoolstests.h"
#include "WorldCoordsToolsTests/worldcoordstoolstests.h"
#include "HomogeneousCoordinatesToolsTests/homogeneouscoordinatestoolstests.h"
#include <QTest>

int main()
{
    ObjredingToolsTests test1;
    QTest::qExec(&test1);

    HomogeneousCoordinatesToolsTests test2;
    QTest::qExec(&test2);

    WorldCoordsToolsTests test3;
    QTest::qExec(&test3);
    return 0;
}
