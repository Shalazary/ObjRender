!DRAWABLE_MODEL_PRI {
CONFIG += DRAWABLE_MODEL_PRI

INCLUDEPATH *= $$clean_path($$PWD/../)

include($$PWD/../DrawableObject/DrawableObject.pri)
include($$PWD/../ModelGeometry/ModelGeometry/ModelGeometry.pri)
include($$PWD/../ModelGeometry/Utils/Utils.pri)
include($$PWD/../DrawingTools/TexturePixelColorGetter/TexturePixelColorGetter.pri)
include($$PWD/../DrawingTools/PlainPixelColorGetter/PlainPixelColorGetter.pri)
include($$PWD/../DrawingTools/ShadePixelColorGetter/ShadePixelColorGetter.pri)
include($$PWD/../DrawingTools/LightPixelColorTransformer/LightPixelColorTransformer.pri)
include($$PWD/../DrawingTools/ShapeDrawingTools/ShapeDrawingTools.pri)
include($$PWD/../Array2D/Array2D.pri)

SOURCES += \
    $$PWD/drawablemodel.cpp

HEADERS += \
    $$PWD/drawablemodel.h
}
