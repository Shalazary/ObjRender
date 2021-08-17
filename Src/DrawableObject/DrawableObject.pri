!DRAWABLE_OBJECT_PRI {
CONFIG += DRAWABLE_OBJECT_PRI

INCLUDEPATH *= $$clean_path($$PWD/../)

include($$PWD/../Array2D/Array2D.pri)

SOURCES += \
    $$PWD/drawableobject.cpp

HEADERS += \
    $$PWD/drawableobject.h
}
