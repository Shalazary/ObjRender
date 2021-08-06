!MODEL_GEOMETRY_UTILS_TESTS_PRI {

CONFIG += MODEL_GEOMETRY_UTILS_TESTS_PRI

INCLUDEPATH *= $$clean_path($$PWD/../)

include(../../Src/ModelGeometry/Utils/Utils.pri)

SOURCES += \
    $$PWD/model_geometry_utils_tests.cpp

HEADERS += \
    $$PWD/model_geometry_utils_tests.h

}
