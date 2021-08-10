QT += core gui testlib

CONFIG += c++17 object_parallel_to_source no_batch

DEFINES += QT_DEPRECATED_WARNINGS

include(Tests/ObjReadingToolsTests/ObjReadingToolsTests.pri)
include(Tests/HomogeneousCoordinatesToolsTests/HomogeneousCoordinatesToolsTests.pri)
include(Tests/BarycentricCoordinatesToolsTests/BarycentricCoordinatesToolsTests.pri)
include(Tests/ModelGeometryUtilsTests/ModelGeometryUtilsTests.pri)
include(Tests/ImageToolsTests/ImageToolsTests.pri)

SOURCES += \
    Tests/main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
