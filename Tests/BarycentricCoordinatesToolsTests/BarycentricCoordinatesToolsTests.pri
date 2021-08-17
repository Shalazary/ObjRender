!BARYCENTRIC_COOEDINATES_TOOLS_TESTS_PRI {

CONFIG += BARYCENTRIC_COOEDINATES_TOOLS_TESTS_PRI

INCLUDEPATH *= $$clean_path($$PWD/../)

include($$PWD/../../Src/BarycentricCoordinatesTools/BarycentricCoordinatesTools.pri)

SOURCES += \
    $$PWD/barycentric_coordinates_tools_tests.cpp

HEADERS += \
    $$PWD/barycentric_coordinates_tools_tests.h

}
