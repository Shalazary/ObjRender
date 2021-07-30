!VIEWPORT {
CONFIG += VIEWPORT

INCLUDEPATH *= $$clean_path($$PWD/../)

include(../DrawableObject/DrawableObject.pri)
include(../Camera/Camera.pri)

SOURCES += \
    $$PWD/viewport.cpp

HEADERS += \
    $$PWD/viewport.h
}
