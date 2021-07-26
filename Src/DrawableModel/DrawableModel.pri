!DRAWABLE_MODEL_PRI {
CONFIG += DRAWABLE_MODEL_PRI

INCLUDEPATH *= $$clean_path($$PWD/../)

include(../DrawableObject/DrawableObject.pri)
include(../DrawingTools/DrawingTools.pri)
include(../Point3D/Point3D.pri)
include(../HomogeneousCoordinatesTools/HomogeneousCoordinatesTools.pri)
include(../ModelGeometry/ModelGeometry/ModelGeometry.pri)
include(../ModelGeometry/Utils/Utils.pri)

SOURCES += \
    $$PWD/drawablemodel.cpp

HEADERS += \
    $$PWD/drawablemodel.h
}
