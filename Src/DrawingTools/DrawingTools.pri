!DRAWING_TOOLS_PRI {
CONFIG += DRAWING_TOOLS_PRI

INCLUDEPATH *= $$clean_path($$PWD/../)

include(../HomogeneousCoordinatesTools/HomogeneousCoordinatesTools.pri)
include(../BarycentricCoordinatesTools/BarycentricCoordinatesTools.pri)
include(../Point3D/Point3D.pri)

SOURCES += \
    $$PWD/drawingtools.cpp

HEADERS += \
    $$PWD/drawingtools.h
}
