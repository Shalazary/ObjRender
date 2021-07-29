#include "ObjReadingToolsTests/objreadingtoolstests.h"
#include "WorldCoordsToolsTests/worldcoordstoolstests.h"
#include "HomogeneousCoordinatesToolsTests/homogeneouscoordinatestoolstests.h"
#include "DrawingToolsTests/drawingtoolstests.h"
#include "CameraTests/cameratests.h"
#include "BarycentricCoordinatesToolsTests/barycentric_coordinates_tools_tests.h"

#include <QTest>
#include <QStringList>

int main()
{
    QStringList args("-silent");

    ObjredingToolsTests test1;
    QTest::qExec(&test1, args);

    HomogeneousCoordinatesToolsTests test2;
    QTest::qExec(&test2, args);

    WorldCoordsToolsTests test3;
    QTest::qExec(&test3, args);

    DrawingToolsTests test4;
    QTest::qExec(&test4, args);

    CameraTests test5;
    QTest::qExec(&test5);

    BarycentricCoordinatesToolsTests test6;
    QTest::qExec(&test6);

    return 0;
}
