!DRAWABLE_MODEL_PRI {
CONFIG += DRAWABLE_MODEL_PRI

INCLUDEPATH *= $$clean_path($$PWD/../)

include($$PWD/../DrawableObject/DrawableObject.pri)
include($$PWD/../DrawingTools/DrawingTools.pri)
include($$PWD/../ModelGeometry/ModelGeometry/ModelGeometry.pri)
include($$PWD/../ModelGeometry/Utils/Utils.pri)
include($$PWD/../RenderTools/RenderTools.pri)

SOURCES += \
    $$PWD/drawablemodel.cpp

HEADERS += \
    $$PWD/drawablemodel.h
}
