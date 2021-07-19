QT += core gui

CONFIG += c++17 object_parallel_to_source no_batch

DEFINES += QT_DEPRECATED_WARNINGS

include(Camera/Camera.pri)
include(Viewport/Viewport.pri)
include(DrawableObject/DrawableObject.pri)
include(DrawableModel/DrawableModel.pri)
include(DrawingTools/DrawingTools.pri)
include(ObjReadingTools/ObjReadingTools.pri)
include(WorldCoordsTools/WorldCoordsTools.pri)
include(HomogeneousCoordinatesTools/HomogeneousCoordinatesTools.pri)

SOURCES += \
    main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
