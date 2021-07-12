!DRAWING_TOOLS_PRI {
CONFIG += DRAWING_TOOLS_PRI

INCLUDEPATH *= $$clean_path($$PWD/../)

include(../WorldCoordsTools/WorldCoordsTools.pri)

SOURCES += \
    $$PWD/drawingtools.cpp

HEADERS += \
    $$PWD/drawingtools.h
}
