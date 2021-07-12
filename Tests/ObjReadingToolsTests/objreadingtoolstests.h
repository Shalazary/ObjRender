#ifndef OBJ_READING_TOOLS_TESTS_H
#define OBJ_READING_TOOLS_TESTS_H

#include <QtTest>

class ObjredingToolsTests : public QObject
{
    Q_OBJECT
private slots:
    void parseVertex_validData_test01();
    void parseVertex_validData_test02();
    void parseVertex_invalidData_test01();
    void parseVertex_invalidData_test02();
    void parseVertex_invalidData_test03();
    void parseVertex_invalidData_test04();

    void parseTexCoord_validData_test01();
    void parseTexCoord_validData_test02();
    void parseTexCoord_invalidData_test01();
    void parseTexCoord_invalidData_test02();
    void parseTexCoord_invalidData_test03();
    void parseTexCoord_invalidData_test04();

    void parseNormal_validData_test01();
    void parseNormal_validData_test02();
    void parseNormal_invalidData_test01();
    void parseNormal_invalidData_test02();
    void parseNormal_invalidData_test03();
    void parseNormal_invalidData_test04();

    void parseFace_validData_test01();
    void parseFace_validData_test02();
    void parseFace_validData_test03();
    void parseFace_validData_test04();
    void parseFace_validData_test05();
    void parseFace_validData_test06();
    void parseFace_invalidData_test01();
    void parseFace_invalidData_test02();
    void parseFace_invalidData_test03();
    void parseFace_invalidData_test04();
    void parseFace_invalidData_test05();
    void parseFace_invalidData_test06();

    void readModel_validData_test01();
    void readModel_validData_test02();
    void readModel_invalidData_test01();
    void readModel_invalidData_test02();
};

#endif
