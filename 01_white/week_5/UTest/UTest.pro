include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++1z
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
    ToTest.h \ \
    tst_wt_w5_e01.h


SOURCES += \
        main.cpp


#win32: LIBS += -L$$PWD/../WhiteWeek05_Lib/ -lWhiteWeek05

INCLUDEPATH += $$PWD/../Source
DEPENDPATH += $$PWD/../Source
