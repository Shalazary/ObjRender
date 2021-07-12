!WORLD_COORDS_TOOLS_TESTS_PRI {

DEFINES += WORLD_COORDS_TOOLS_TESTS_PRI

INCLUDEPATH *= $$clean_path($$PWD/../)

include(../../Src/WorldCoordsTools/WorldCoordsTools.pri)

SOURCES += \
    $$PWD/worldcoordstoolstests.cpp

HEADERS += \
    $$PWD/worldcoordstoolstests.h

}
