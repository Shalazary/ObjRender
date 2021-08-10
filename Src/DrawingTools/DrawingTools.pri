!DRAWING_TOOLS_PRI {
CONFIG += DRAWING_TOOLS_PRI

INCLUDEPATH *= $$clean_path($$PWD/../)

include($$PWD/../HomogeneousCoordinatesTools/HomogeneousCoordinatesTools.pri)
include($$PWD/../BarycentricCoordinatesTools/BarycentricCoordinatesTools.pri)
include($$PWD/../Point3D/Point3D.pri)
include($$PWD/../WorldCoordsTools/WorldCoordsTools.pri)
include($$PWD/../ImageTools/ImageTools.pri)

SOURCES += \
    $$PWD/drawingtools.cpp

HEADERS += \
    $$PWD/drawingtools.h
}
