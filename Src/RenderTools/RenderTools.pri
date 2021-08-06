!RENDER_TOOLS_PRI {
CONFIG += RENDER_TOOLS_PRI

INCLUDEPATH *= $$clean_path($$PWD/../)

include(../DrawingTools/DrawingTools.pri)
include(../ModelGeometry/Utils/Utils.pri)
include(../ModelGeometry/ModelGeometry/ModelGeometry.pri)
include(../Camera/Camera.pri)

SOURCES += \
    $$PWD/render_tools.cpp

HEADERS += \
    $$PWD/render_tools.h
}
