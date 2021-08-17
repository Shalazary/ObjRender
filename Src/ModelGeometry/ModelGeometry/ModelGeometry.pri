!MODEL_GEOMETRY_PRI {
CONFIG += MODEL_GEOMETRY_PRI

INCLUDEPATH *= $$clean_path($$PWD/../)

include($$PWD/../Utils/Utils.pri)

SOURCES += \
    $$PWD/modelgeometry.cpp

HEADERS += \
    $$PWD/modelgeometry.h
} 
