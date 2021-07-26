QT += core gui

CONFIG += c++17 object_parallel_to_source no_batch

DEFINES += QT_DEPRECATED_WARNINGS

include(Src/Camera/Camera.pri)
include(Src/Viewport/Viewport.pri)
include(Src/DrawableModel/DrawableModel.pri)
include(Src/ObjReadingTools/ObjReadingTools.pri)
include(Src/ModelGeometry/ModelGeometry/ModelGeometry.pri)

SOURCES += \
    Src/main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
