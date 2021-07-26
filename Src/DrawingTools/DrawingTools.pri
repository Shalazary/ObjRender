!DRAWING_TOOLS_PRI {
CONFIG += DRAWING_TOOLS_PRI

INCLUDEPATH *= $$clean_path($$PWD/../)

include(../WorldCoordsTools/WorldCoordsTools.pri)
include(../Point3D/Point3D.pri)

SOURCES += \
    $$PWD/drawingtools.cpp

HEADERS += \
    $$PWD/drawingtools.h
}
