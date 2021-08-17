!DRAWING_TOOLS_SHADE_PIXEL_COLOR_GETTER_PRI {
CONFIG += DRAWING_TOOLS_SHADE_PIXEL_COLOR_GETTER_PRI

INCLUDEPATH *= $$clean_path($$PWD/../)

include($$PWD/../AbstractPixelColorGetter/AbstractPixelColorGetter.pri)
include($$PWD/../AbstractPixelColorTransformer/AbstractPixelColorTransformer.pri)

SOURCES += \
    $$PWD/shade_pixel_color_getter.cpp

HEADERS += \
    $$PWD/shade_pixel_color_getter.h
}
