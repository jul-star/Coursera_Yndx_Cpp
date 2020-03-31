include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++1z
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
        tst_uniquestringtest.h

SOURCES += \
        main.cpp




win32: LIBS += -L$$PWD/../UniqueString_Lib/ -lUniqueString

INCLUDEPATH += $$PWD/../UniqueString_Lib
DEPENDPATH += $$PWD/../UniqueString_Lib
