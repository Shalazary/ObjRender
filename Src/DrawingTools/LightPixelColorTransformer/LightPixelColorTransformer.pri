!DRAWING_TOOLS_LIGHT_PIXEL_COLOR_TRANSFORMER_PRI {
CONFIG += DRAWING_TOOLS_LIGHT_PIXEL_COLOR_TRANSFORMER_PRI

INCLUDEPATH *= $$clean_path($$PWD/../)

include($$PWD/../AbstractPixelColorTransformer/AbstractPixelColorTransformer.pri)
include($$PWD/../../BarycentricCoordinatesTools/BarycentricCoordinatesTools.pri)

SOURCES += \
    $$PWD/light_pixel_color_transformer.cpp

HEADERS += \
    $$PWD/light_pixel_color_transformer.h
}
