!DRAWING_TOOLS_TESTS_PRI {

DEFINES += DRAWING_TOOLS_TESTS_PRI

INCLUDEPATH *= $$clean_path($$PWD/../)

include(../../Src/DrawingTools/DrawingTools.pri)

SOURCES += \
    $$PWD/drawingtoolstests.cpp

HEADERS += \
    $$PWD/drawingtoolstests.cpp

}
