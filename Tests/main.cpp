#include <QTest>
#include <QStringList>

#include "ObjReadingToolsTests/objreadingtoolstests.h"
#include "HomogeneousCoordinatesToolsTests/homogeneouscoordinatestoolstests.h"
#include "BarycentricCoordinatesToolsTests/barycentric_coordinates_tools_tests.h"
#include "ModelGeometryUtilsTests/model_geometry_utils_tests.h"
#include "ImageToolsTests/image_tools_test.h"

int main()
{
    QStringList args;
    args << "" << "-silent";

    ObjredingToolsTests test1;
    QTest::qExec(&test1, args);

    HomogeneousCoordinatesToolsTests test2;
    QTest::qExec(&test2, args);

    BarycentricCoordinatesToolsTests test3;
    QTest::qExec(&test3);

    ModelGeometryUtilsTests test4;
    QTest::qExec(&test4);

    ImageToolsTest test5;
    QTest::qExec(&test5);

    return 0;
}
