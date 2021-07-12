!DRAWABLE_MODEL_PRI {
CONFIG += DRAWABLE_MODEL_PRI

INCLUDEPATH *= $$clean_path($$PWD/../)

include(../DrawableObject/DrawableObject.pri)

SOURCES += \
    $$PWD/drawablemodel.cpp

HEADERS += \
    $$PWD/drawablemodel.h
}
