QT += core gui testlib

CONFIG += c++17 object_parallel_to_source no_batch

DEFINES += QT_DEPRECATED_WARNINGS

include(ObjReadingToolsTests/ObjReadingToolsTests.pri)
include(DrawingToolsTests/DrawingToolsTests.pri)
include(WorldCoordsToolsTests/WorldCoordsToolsTests.pri)
include(HomogeneousCoordinatesToolsTests/HomogeneousCoordinatesToolsTests.pri)

SOURCES += \
    main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
