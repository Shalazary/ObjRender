!CAMERA_TESTS_PRI {

CONFIG += CAMERA_TESTS_PRI

INCLUDEPATH *= $$clean_path($$PWD/../)

include(../../Src/Camera/Camera.pri)

SOURCES += \
    $$PWD/cameratests.cpp

HEADERS += \
    $$PWD/cameratests.h

}
