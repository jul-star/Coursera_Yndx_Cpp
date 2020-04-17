include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++1z
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
    ToTest.h \ \
    tst_wt_w4_e01.h \
    tst_wt_w4_e02.h


SOURCES += \
        main.cpp


#win32: LIBS += -L$$PWD/../WhiteWeek04_Lib/ -lWhiteWeek04

INCLUDEPATH += $$PWD/../Source
DEPENDPATH += $$PWD/../Source
