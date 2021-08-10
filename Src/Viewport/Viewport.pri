!VIEWPORT {
CONFIG += VIEWPORT

INCLUDEPATH *= $$clean_path($$PWD/../)

include($$PWD/../DrawableObject/DrawableObject.pri)
include($$PWD/../Camera/Camera.pri)

SOURCES += \
    $$PWD/viewport.cpp

HEADERS += \
    $$PWD/viewport.h
}
