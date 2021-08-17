!DRAWING_TOOLS_PLAIN_PIXEL_COLOR_GETTER_PRI {
CONFIG += DRAWING_TOOLS_PLAIN_PIXEL_COLOR_GETTER_PRI

INCLUDEPATH *= $$clean_path($$PWD/../)

include($$PWD/../AbstractPixelColorGetter/AbstractPixelColorGetter.pri)

SOURCES += \
    $$PWD/plain_pixel_color_getter.cpp

HEADERS += \
    $$PWD/plain_pixel_color_getter.h
}
