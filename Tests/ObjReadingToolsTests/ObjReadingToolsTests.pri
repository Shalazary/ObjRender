!OBJ_READING_TOOLS_TESTS_PRI {

DEFINES += OBJ_READING_TOOLS_TESTS_PRI

INCLUDEPATH *= $$clean_path($$PWD/../)

include(../../Src/ObjReadingTools/ObjReadingTools.pri)

SOURCES += \
    $$PWD/objreadingtoolstests.cpp

HEADERS += \
    $$PWD/objreadingtoolstests.h

}
