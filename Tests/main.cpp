#include "ObjReadingToolsTests/objreadingtoolstests.h"
#include "WorldCoordsToolsTests/worldcoordstoolstests.h"
#include <QtTest>
#include <QMatrix4x4>

int main()
{
    ObjredingToolsTests test1;
    QTest::qExec(&test1);

    WorldCoordsToolsTests test2;
    QTest::qExec(&test2);

    return 0;
}
