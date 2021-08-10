!RENDER_TOOLS_PRI {
CONFIG += RENDER_TOOLS_PRI

INCLUDEPATH *= $$clean_path($$PWD/../)

include($$PWD/../DrawingTools/DrawingTools.pri)
include($$PWD/../ModelGeometry/Utils/Utils.pri)
include($$PWD/../ModelGeometry/ModelGeometry/ModelGeometry.pri)
include($$PWD/../Camera/Camera.pri)

SOURCES += \
    $$PWD/render_tools.cpp

HEADERS += \
    $$PWD/render_tools.h
}
