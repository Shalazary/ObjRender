!CAMERA_PRI {
CONFIG += CAMERA_PRI

INCLUDEPATH *= $$clean_path($$PWD/../)

include(../HomogeneousCoordinatesTools/HomogeneousCoordinatesTools.pri)

SOURCES += \
    $$PWD/camera.cpp

HEADERS += \
    $$PWD/camera.h
}
