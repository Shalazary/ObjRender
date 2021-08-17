!DRAWING_TOOLS_TEXTURE_PIXEL_COLOR_GETTER_PRI {
CONFIG += DRAWING_TOOLS_TEXTURE_PIXEL_COLOR_GETTER_PRI

INCLUDEPATH *= $$clean_path($$PWD/../)

include($$PWD/../AbstractPixelColorGetter/AbstractPixelColorGetter.pri)
include($$PWD/../../HomogeneousCoordinatesTools/HomogeneousCoordinatesTools.pri)
include($$PWD/../../BarycentricCoordinatesTools/BarycentricCoordinatesTools.pri)
include($$PWD/../../ImageTools/ImageTools.pri)

SOURCES += \
    $$PWD/texture_pixel_color_getter.cpp

HEADERS += \
    $$PWD/texture_pixel_color_getter.h
}
