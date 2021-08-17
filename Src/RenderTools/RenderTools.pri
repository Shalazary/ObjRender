!RENDER_TOOLS_PRI {
CONFIG += RENDER_TOOLS_PRI

INCLUDEPATH *= $$clean_path($$PWD/../)

include($$PWD/../DrawingTools/ShapeDrawingTools/ShapeDrawingTools.pri)
include($$PWD/../ModelGeometry/Utils/Utils.pri)
include($$PWD/../ModelGeometry/ModelGeometry/ModelGeometry.pri)
include($$PWD/../Camera/Camera.pri)
include($$PWD/../DrawingTools/TexturePixelColorGetter/TexturePixelColorGetter.pri)
include($$PWD/../DrawingTools/PlainPixelColorGetter/PlainPixelColorGetter.pri)
include($$PWD/../DrawingTools/ShadePixelColorGetter/ShadePixelColorGetter.pri)
include($$PWD/../DrawingTools/LightPixelColorTransformer/LightPixelColorTransformer.pri)
include($$PWD/../Array2D/Array2D.pri)

SOURCES += \
    $$PWD/render_tools.cpp

HEADERS += \
    $$PWD/render_tools.h
}

