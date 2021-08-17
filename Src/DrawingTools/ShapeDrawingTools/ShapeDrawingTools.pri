!SHAPE_DRAWING_TOOLS_PRI {
CONFIG += SHAPE_DRAWING_TOOLS_PRI

INCLUDEPATH *= $$clean_path($$PWD/../)

include($$PWD/../../HomogeneousCoordinatesTools/HomogeneousCoordinatesTools.pri)
include($$PWD/../../BarycentricCoordinatesTools/BarycentricCoordinatesTools.pri)
include($$PWD/../../ImageTools/ImageTools.pri)
include($$PWD/../../Array2D/Array2D.pri)
include($$PWD/../AbstractPixelColorGetter/AbstractPixelColorGetter.pri)

SOURCES += \
    $$PWD/shapedrawingtools.cpp

HEADERS += \
    $$PWD/shapedrawingtools.h
}
