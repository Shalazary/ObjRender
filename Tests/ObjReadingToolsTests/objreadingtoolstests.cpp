#include "objreadingtoolstests.h"
#include "ObjReadingTools/objreadingtools.h"

#include <QVector3D>
#include <QString>
#include <QTextStream>


void ObjredingToolsTests::parseVertex_validData_test01()
{
    QString data1 = "1 2 3";
    QString data2 = "11 22 333";
    QString data3 = "-1 -2 33";

    QString errMsg;

    QVector3D actual1;
    QVector3D actual2;
    QVector3D actual3;

    QVERIFY(ObjReadingTools::Utils::parseVertex(data1, actual1, errMsg));
    QVERIFY(ObjReadingTools::Utils::parseVertex(data2, actual2, errMsg));
    QVERIFY(ObjReadingTools::Utils::parseVertex(data3, actual3, errMsg));

    QVector3D expected1 = {1, 2, 3};
    QVector3D expected2 = {11, 22, 333};
    QVector3D expected3 = {-1, -2, 33};

    QCOMPARE(actual1, expected1);
    QCOMPARE(actual2, expected2);
    QCOMPARE(actual3, expected3);
}

void ObjredingToolsTests::parseVertex_validData_test02()
{
    QString data1 = "1. 2.0 3.0";
    QString data2 = "11.1501 22.33 333.86";
    QString data3 = "-1.0 -2.012 33.0000";

    QString errMsg;

    QVector3D actual1;
    QVector3D actual2;
    QVector3D actual3;

    QVERIFY(ObjReadingTools::Utils::parseVertex(data1, actual1, errMsg));
    QVERIFY(ObjReadingTools::Utils::parseVertex(data2, actual2, errMsg));
    QVERIFY(ObjReadingTools::Utils::parseVertex(data3, actual3, errMsg));

    QVector3D expected1 = {1, 2, 3};
    QVector3D expected2 = {11.1501, 22.33, 333.86};
    QVector3D expected3 = {-1, -2.012, 33};

    QCOMPARE(actual1, expected1);
    QCOMPARE(actual2, expected2);
    QCOMPARE(actual3, expected3);
}

void ObjredingToolsTests::parseVertex_invalidData_test01()
{
    QString data = "1 2";

    QString errMsg;

    QVector3D actual;

    QVERIFY(!ObjReadingTools::Utils::parseVertex(data, actual, errMsg));

    QString expectedErrMsg = "Invalid number of vertex coordinates. Expected 3. Actual received 2";

    QCOMPARE(errMsg, expectedErrMsg);
}

void ObjredingToolsTests::parseVertex_invalidData_test02()
{
    QString data = "1 2. 4.011 5";

    QString errMsg;

    QVector3D actual;

    QVERIFY(!ObjReadingTools::Utils::parseVertex(data, actual, errMsg));

    QString expectedErrMsg = "Invalid number of vertex coordinates. Expected 3. Actual received 4";

    QCOMPARE(errMsg, expectedErrMsg);
}

void ObjredingToolsTests::parseVertex_invalidData_test03()
{
    QString data = "adc 1 2";

    QString errMsg;

    QVector3D actual;

    QVERIFY(!ObjReadingTools::Utils::parseVertex(data, actual, errMsg));

    QString expectedErrMsg = "To float conversion failed in string adc. Position 1";

    QCOMPARE(errMsg, expectedErrMsg);
}

void ObjredingToolsTests::parseVertex_invalidData_test04()
{
    QString data = "1 -11.-1bv 2";

    QString errMsg;

    QVector3D actual;

    QVERIFY(!ObjReadingTools::Utils::parseVertex(data, actual, errMsg));

    QString expectedErrMsg = "To float conversion failed in string -11.-1bv. Position 2";

    QCOMPARE(errMsg, expectedErrMsg);
}

void ObjredingToolsTests::parseTexCoord_validData_test01()
{
    QString data1 = "1 2 3";
    QString data2 = "11 22";
    QString data3 = "-1 -2";

    QString errMsg;

    QVector2D actual1;
    QVector2D actual2;
    QVector2D actual3;

    QVERIFY(ObjReadingTools::Utils::parseTexCoord(data1, actual1, errMsg));
    QVERIFY(ObjReadingTools::Utils::parseTexCoord(data2, actual2, errMsg));
    QVERIFY(ObjReadingTools::Utils::parseTexCoord(data3, actual3, errMsg));

    QVector2D expected1 = {1, 2};
    QVector2D expected2 = {11, 22};
    QVector2D expected3 = {-1, -2};

    QCOMPARE(actual1, expected1);
    QCOMPARE(actual2, expected2);
    QCOMPARE(actual3, expected3);
}

void ObjredingToolsTests::parseTexCoord_validData_test02()
{
    QString data1 = "1 2.12";
    QString data2 = "11.3 22.00";
    QString data3 = "-1.000 -2.006";

    QString errMsg;

    QVector2D actual1;
    QVector2D actual2;
    QVector2D actual3;

    QVERIFY(ObjReadingTools::Utils::parseTexCoord(data1, actual1, errMsg));
    QVERIFY(ObjReadingTools::Utils::parseTexCoord(data2, actual2, errMsg));
    QVERIFY(ObjReadingTools::Utils::parseTexCoord(data3, actual3, errMsg));

    QVector2D expected1 = {1, 2.12};
    QVector2D expected2 = {11.3, 22.00};
    QVector2D expected3 = {-1.000, -2.006};

    QCOMPARE(actual1, expected1);
    QCOMPARE(actual2, expected2);
    QCOMPARE(actual3, expected3);
}

void ObjredingToolsTests::parseTexCoord_invalidData_test01()
{
    QString data = "1 2 0 asd";

    QString errMsg;

    QVector2D actual;

    QVERIFY(!ObjReadingTools::Utils::parseTexCoord(data, actual, errMsg));

    QString expectedErrMsg = "Invalid number of texture coordinates. Expected 2 or 3. Actual received 4";

    QCOMPARE(errMsg, expectedErrMsg);
}

void ObjredingToolsTests::parseTexCoord_invalidData_test02()
{
    QString data = "1      ";

    QString errMsg;

    QVector2D actual;

    QVERIFY(!ObjReadingTools::Utils::parseTexCoord(data, actual, errMsg));

    QString expectedErrMsg = "Invalid number of texture coordinates. Expected 2 or 3. Actual received 1";

    QCOMPARE(errMsg, expectedErrMsg);
}

void ObjredingToolsTests::parseTexCoord_invalidData_test03()
{
    QString data = "1       as   dc";

    QString errMsg;

    QVector2D actual;

    QVERIFY(!ObjReadingTools::Utils::parseTexCoord(data, actual, errMsg));

    QString expectedErrMsg = "To float conversion failed in string as. Position 2";

    QCOMPARE(errMsg, expectedErrMsg);
}

void ObjredingToolsTests::parseTexCoord_invalidData_test04()
{
    QString data = "1   1e0-1";

    QString errMsg;

    QVector2D actual;

    QVERIFY(!ObjReadingTools::Utils::parseTexCoord(data, actual, errMsg));

    QString expectedErrMsg = "To float conversion failed in string 1e0-1. Position 2";

    QCOMPARE(errMsg, expectedErrMsg);
}

void ObjredingToolsTests::parseNormal_validData_test01()
{
    QString data1 = "1 2 3";
    QString data2 = "11 22 333";
    QString data3 = "-1 -2 33";

    QString errMsg;

    QVector3D actual1;
    QVector3D actual2;
    QVector3D actual3;

    QVERIFY(ObjReadingTools::Utils::parseNormal(data1, actual1, errMsg));
    QVERIFY(ObjReadingTools::Utils::parseNormal(data2, actual2, errMsg));
    QVERIFY(ObjReadingTools::Utils::parseNormal(data3, actual3, errMsg));

    QVector3D expected1 = {1, 2, 3};
    QVector3D expected2 = {11, 22, 333};
    QVector3D expected3 = {-1, -2, 33};

    QCOMPARE(actual1, expected1);
    QCOMPARE(actual2, expected2);
    QCOMPARE(actual3, expected3);
}

void ObjredingToolsTests::parseNormal_validData_test02()
{
    QString data1 = "001. 2.0 3.0";
    QString data2 = "11.1501 22.33 333.86";
    QString data3 = "-1.0 -2.012 33.0000";

    QString errMsg;

    QVector3D actual1;
    QVector3D actual2;
    QVector3D actual3;

    QVERIFY(ObjReadingTools::Utils::parseNormal(data1, actual1, errMsg));
    QVERIFY(ObjReadingTools::Utils::parseNormal(data2, actual2, errMsg));
    QVERIFY(ObjReadingTools::Utils::parseNormal(data3, actual3, errMsg));

    QVector3D expected1 = {1, 2, 3};
    QVector3D expected2 = {11.1501, 22.33, 333.86};
    QVector3D expected3 = {-1, -2.012, 33};

    QCOMPARE(actual1, expected1);
    QCOMPARE(actual2, expected2);
    QCOMPARE(actual3, expected3);
}

void ObjredingToolsTests::parseNormal_invalidData_test01()
{
    QString data = "1 2";

    QString errMsg;

    QVector3D actual;

    QVERIFY(!ObjReadingTools::Utils::parseNormal(data, actual, errMsg));

    QString expectedErrMsg = "Invalid number of normals coordinates. Expected 3. Actual received 2";

    QCOMPARE(errMsg, expectedErrMsg);
}

void ObjredingToolsTests::parseNormal_invalidData_test02()
{
    QString data = "1 2 3 4";

    QString errMsg;

    QVector3D actual;

    QVERIFY(!ObjReadingTools::Utils::parseNormal(data, actual, errMsg));

    QString expectedErrMsg = "Invalid number of normals coordinates. Expected 3. Actual received 4";

    QCOMPARE(errMsg, expectedErrMsg);
}

void ObjredingToolsTests::parseNormal_invalidData_test03()
{
    QString data = "1 2 034bfg";

    QString errMsg;

    QVector3D actual;

    QVERIFY(!ObjReadingTools::Utils::parseNormal(data, actual, errMsg));

    QString expectedErrMsg = "To float conversion failed in string 034bfg. Position 3";

    QCOMPARE(errMsg, expectedErrMsg);
}

void ObjredingToolsTests::parseNormal_invalidData_test04()
{
    QString data = "1 -2- 3";

    QString errMsg;

    QVector3D actual;

    QVERIFY(!ObjReadingTools::Utils::parseNormal(data, actual, errMsg));

    QString expectedErrMsg = "To float conversion failed in string -2-. Position 2";

    QCOMPARE(errMsg, expectedErrMsg);
}

void ObjredingToolsTests::parseFace_validData_test01()
{
    QString data = "1 2 3";

    QString errMsg;

    QVector<int> actualVertices;
    QVector<int> actualTexCoords;
    QVector<int> actualNormals;

    QVERIFY(ObjReadingTools::Utils::parseFace(data, actualVertices, actualTexCoords, actualNormals, errMsg));

    QVector<int> expectedVertices = {1, 2, 3};
    QVector<int> expectedTexCoords = {0, 0, 0};
    QVector<int> expectedNormals = {0, 0, 0};

    QCOMPARE(actualVertices, expectedVertices);
    QCOMPARE(actualTexCoords, expectedTexCoords);
    QCOMPARE(actualNormals, expectedNormals);
}

void ObjredingToolsTests::parseFace_validData_test02()
{
    QString data = "1/4 2/5 3/6";

    QString errMsg;

    QVector<int> actualVertices;
    QVector<int> actualTexCoords;
    QVector<int> actualNormals;

    QVERIFY(ObjReadingTools::Utils::parseFace(data, actualVertices, actualTexCoords, actualNormals, errMsg));

    QVector<int> expectedVertices = {1, 2, 3};
    QVector<int> expectedTexCoords = {4, 5, 6};
    QVector<int> expectedNormals = {0, 0, 0};

    QCOMPARE(actualVertices, expectedVertices);
    QCOMPARE(actualTexCoords, expectedTexCoords);
    QCOMPARE(actualNormals, expectedNormals);
}

void ObjredingToolsTests::parseFace_validData_test03()
{
    QString data = "1//4 2//5 3//6";

    QString errMsg;

    QVector<int> actualVertices;
    QVector<int> actualTexCoords;
    QVector<int> actualNormals;

    QVERIFY(ObjReadingTools::Utils::parseFace(data, actualVertices, actualTexCoords, actualNormals, errMsg));

    QVector<int> expectedVertices = {1, 2, 3};
    QVector<int> expectedTexCoords = {0, 0, 0};
    QVector<int> expectedNormals = {4, 5, 6};

    QCOMPARE(actualVertices, expectedVertices);
    QCOMPARE(actualTexCoords, expectedTexCoords);
    QCOMPARE(actualNormals, expectedNormals);
}

void ObjredingToolsTests::parseFace_validData_test04()
{
    QString data = "1/4/7 2/5/8 3/6/9";

    QString errMsg;

    QVector<int> actualVertices;
    QVector<int> actualTexCoords;
    QVector<int> actualNormals;

    QVERIFY(ObjReadingTools::Utils::parseFace(data, actualVertices, actualTexCoords, actualNormals, errMsg));

    QVector<int> expectedVertices = {1, 2, 3};
    QVector<int> expectedTexCoords = {4, 5, 6};
    QVector<int> expectedNormals = {7, 8, 9};

    QCOMPARE(actualVertices, expectedVertices);
    QCOMPARE(actualTexCoords, expectedTexCoords);
    QCOMPARE(actualNormals, expectedNormals);
}

void ObjredingToolsTests::parseFace_validData_test05()
{
    QString data = "1/4/7 2//8 3";

    QString errMsg;

    QVector<int> actualVertices;
    QVector<int> actualTexCoords;
    QVector<int> actualNormals;

    QVERIFY(ObjReadingTools::Utils::parseFace(data, actualVertices, actualTexCoords, actualNormals, errMsg));

    QVector<int> expectedVertices = {1, 2, 3};
    QVector<int> expectedTexCoords = {4, 0, 0};
    QVector<int> expectedNormals = {7, 8, 0};

    QCOMPARE(actualVertices, expectedVertices);
    QCOMPARE(actualTexCoords, expectedTexCoords);
    QCOMPARE(actualNormals, expectedNormals);
}

void ObjredingToolsTests::parseFace_validData_test06()
{
    QString data = "1//7 2//8 9";

    QString errMsg;

    QVector<int> actualVertices;
    QVector<int> actualTexCoords;
    QVector<int> actualNormals;

    QVERIFY(ObjReadingTools::Utils::parseFace(data, actualVertices, actualTexCoords, actualNormals, errMsg));

    QVector<int> expectedVertices = {1, 2, 9};
    QVector<int> expectedTexCoords = {0, 0, 0};
    QVector<int> expectedNormals = {7, 8, 0};

    QCOMPARE(actualVertices, expectedVertices);
    QCOMPARE(actualTexCoords, expectedTexCoords);
    QCOMPARE(actualNormals, expectedNormals);
}

void ObjredingToolsTests::parseFace_invalidData_test01()
{
    QString data = "1/4/7/8 2/5/8 3/6/9";

    QString errMsg;

    QVector<int> actualVertices;
    QVector<int> actualTexCoords;
    QVector<int> actualNormals;

    QVERIFY(!ObjReadingTools::Utils::parseFace(data, actualVertices, actualTexCoords, actualNormals, errMsg));

    QString expectedErrMsg = "Vertex format should be v, v/vt, v//vn or v/vt/vn. Now block contains 1/4/7/8. Block number 1";

    QCOMPARE(errMsg, expectedErrMsg);
}

void ObjredingToolsTests::parseFace_invalidData_test02()
{
    QString data = "1/4/ 2/5/8 3/6/9";

    QString errMsg;

    QVector<int> actualVertices;
    QVector<int> actualTexCoords;
    QVector<int> actualNormals;

    QVERIFY(!ObjReadingTools::Utils::parseFace(data, actualVertices, actualTexCoords, actualNormals, errMsg));

    QString expectedErrMsg = "Vertex format should be v, v/vt, v//vn or v/vt/vn. Now block contains 1/4/. Block number 1";

    QCOMPARE(errMsg, expectedErrMsg);
}

void ObjredingToolsTests::parseFace_invalidData_test03()
{
    QString data = "1/4 2/5/8";

    QString errMsg;

    QVector<int> actualVertices;
    QVector<int> actualTexCoords;
    QVector<int> actualNormals;

    QVERIFY(!ObjReadingTools::Utils::parseFace(data, actualVertices, actualTexCoords, actualNormals, errMsg));

    QString expectedErrMsg = "Face should contains 3 or more vertices. Actual received 2";

    QCOMPARE(errMsg, expectedErrMsg);
}

void ObjredingToolsTests::parseFace_invalidData_test04()
{
    QString data = "1/4 2/5/8 4/7 8.012/9";

    QString errMsg;

    QVector<int> actualVertices;
    QVector<int> actualTexCoords;
    QVector<int> actualNormals;

    QVERIFY(!ObjReadingTools::Utils::parseFace(data, actualVertices, actualTexCoords, actualNormals, errMsg));

    QString expectedErrMsg = "To int conversion failed in string 8.012";

    QCOMPARE(errMsg, expectedErrMsg);
}

void ObjredingToolsTests::parseFace_invalidData_test05()
{
    QString data = "1/4 2/abs/8 4/7";

    QString errMsg;

    QVector<int> actualVertices;
    QVector<int> actualTexCoords;
    QVector<int> actualNormals;

    QVERIFY(!ObjReadingTools::Utils::parseFace(data, actualVertices, actualTexCoords, actualNormals, errMsg));

    QString expectedErrMsg = "To int conversion failed in string abs";

    QCOMPARE(errMsg, expectedErrMsg);
}

void ObjredingToolsTests::parseFace_invalidData_test06()
{
    QString data = "1/4 2/5/8 4/7 8.0/9";

    QString errMsg;

    QVector<int> actualVertices;
    QVector<int> actualTexCoords;
    QVector<int> actualNormals;

    QVERIFY(!ObjReadingTools::Utils::parseFace(data, actualVertices, actualTexCoords, actualNormals, errMsg));

    QString expectedErrMsg = "To int conversion failed in string 8.0";

    QCOMPARE(errMsg, expectedErrMsg);
}

void ObjredingToolsTests::readModel_validData_test01()
{
    QString errMsg;

    QString data = "v -1 1 0\n"
                   "v 1 1 0\n"
                   "v 1 -1 0\n"
                   "v -1 -1 0\n"
                   "f 1 2 3\n"
                   "f 1 3 4\n";

    QTextStream stream(&data);

    ModelGeometry actual;
    ObjReadingTools::readModelGeometry(stream, actual, errMsg);

    ModelGeometry expected;
    expected.m_vertices = {
        {-1, 1, 0},
        {1, 1, 0},
        {1, -1, 0},
        {-1, -1, 0}
    };
    expected.m_polygonsVerticesIndices = {
        {1, 2, 3},
        {1, 3, 4}
    };
    expected.m_polygonsTexCoordsIndices = {
        {0, 0, 0},
        {0, 0, 0}
    };
    expected.m_polygonsNormalsIndices = {
        {0, 0, 0},
        {0, 0, 0}
    };

    QCOMPARE(actual, expected);
}

void ObjredingToolsTests::readModel_validData_test02()
{
    QString errMsg;

    QString data = "v -1 1 0\n"
                   "v 1 1 0\n"
                   "v 1 -1 0\n"
                   "v -1 -1 0\n"
                   "vt 0 1\n"
                   "vt 1 1\n"
                   "vt 1 0\n"
                   "vt 0 0\n"
                   "f 3/3 2/2 1/1\n"
                   "f 4/4 3/3 1/1\n";

    QTextStream stream(&data);

    ModelGeometry actual;
    ObjReadingTools::readModelGeometry(stream, actual, errMsg);

    ModelGeometry expected;
    expected.m_vertices = {
        {-1, 1, 0},
        {1, 1, 0},
        {1, -1, 0},
        {-1, -1, 0}
    };
    expected.m_texCoords = {
        {0, 1},
        {1, 1},
        {1, 0},
        {0, 0}
    };
    expected.m_polygonsVerticesIndices = {
        {3, 2, 1},
        {4, 3, 1}
    };
    expected.m_polygonsTexCoordsIndices = {
        {3, 2, 1},
        {4, 3, 1}
    };
    expected.m_polygonsNormalsIndices = {
        {0, 0, 0},
        {0, 0, 0}
    };

    QCOMPARE(actual, expected);
}

void ObjredingToolsTests::readModel_invalidData_test01()
{
    QString errMsg;

    QString data = "v -1 1 0\n"
                   "v 1 1 0\n"
                   "v 1 -1 0\n"
                   "v -1 -1 0\n"
                   "vt 0 1\n"
                   "vt 1 1\n"
                   "vt 1 0\n"
                   "vt 0 0\n"
                   "ff 3/3 2/2 1/1\n"
                   "f 4/4 3/3 1/1\n";

    QTextStream stream(&data);

    ModelGeometry actual;
    QVERIFY(!ObjReadingTools::readModelGeometry(stream, actual, errMsg));

    QString expected = "Line 9. Invalid token ff";

    QCOMPARE(errMsg, expected);
}

void ObjredingToolsTests::readModel_invalidData_test02()
{
    QString errMsg;

    QString data = "v -1 1 0\n"
                   "v 1 1 0\n"
                   "v 1 -1 0\n"
                   "v -1 -1 0\n"
                   "vt 0 1\n"
                   "vt 1 1\n"
                   "vt 1 0\n"
                   "vt 0 0\n"
                   "f 3/3 2.15/2 1/1\n"
                   "f 4/4 3/3 1/1\n";

    QTextStream stream(&data);

    ModelGeometry actual;
    QVERIFY(!ObjReadingTools::readModelGeometry(stream, actual, errMsg));

    QString expected = "Line 9. To int conversion failed in string 2.15";

    QCOMPARE(errMsg, expected);
}
