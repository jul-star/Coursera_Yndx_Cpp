include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++1z
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
        tst_sort_01_test.h

SOURCES += \
        main.cpp


win32: LIBS += -L$$PWD/../WhiteWeek03_Lib/ -lWhiteWeek03

INCLUDEPATH += $$PWD/../Source
DEPENDPATH += $$PWD/../Source
