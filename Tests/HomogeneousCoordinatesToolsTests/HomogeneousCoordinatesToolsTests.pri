!HOMOGENEOUS_COORDINATES_TOOLS_TESTS_PRI {

DEFINES += HOMOGENEOUS_COORDINATES_TOOLS_TESTS_PRI

INCLUDEPATH *= $$clean_path($$PWD/../)

include(../../Src/HomogeneousCoordinatesTools/HomogeneousCoordinatesTools.pri)

SOURCES += \
    $$PWD/homogeneouscoordinatestoolstests.cpp

HEADERS += \
    $$PWD/homogeneouscoordinatestoolstests.h

}
