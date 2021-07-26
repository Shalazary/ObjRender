!OBJ_READING_TOOLS_PRI {
CONFIG += OBJ_READING_TOOLS_PRI

INCLUDEPATH *= $$clean_path($$PWD/../)

include(../ModelGeometry/ModelGeometry/ModelGeometry.pri)

SOURCES += \
    $$PWD/objreadingtools.cpp

HEADERS += \
    $$PWD/objreadingtools.h
}
