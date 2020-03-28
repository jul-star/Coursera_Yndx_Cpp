include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++1z
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
        tst_capitaltest.h

SOURCES += \
        main.cpp

win32: LIBS += -L$$PWD/../Capital_Lib/ -lCapital

INCLUDEPATH += $$PWD/../Capital_Lib
DEPENDPATH += $$PWD/../Capital_Lib
