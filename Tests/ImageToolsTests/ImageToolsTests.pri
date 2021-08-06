!IMAGE_TOOLS_TESTS_PRI {

CONFIG += IMAGE_TOOLS_TESTS_PRI

INCLUDEPATH *= $$clean_path($$PWD/../)

include(../../Src/ImageTools/ImageTools.pri)

SOURCES += \
    $$PWD/image_tools_test.cpp

HEADERS += \
    $$PWD/image_tools_test.h

}
