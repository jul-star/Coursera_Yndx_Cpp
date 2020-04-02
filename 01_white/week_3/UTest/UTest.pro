include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++1z
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
    ToTest.h \
    tst_wt_w3_e01.h \
    tst_wt_w3_e02.h \
    tst_wt_w3_input.h

SOURCES += \
        main.cpp


win32: LIBS += -L$$PWD/../WhiteWeek03_Lib/ -lWhiteWeek03

INCLUDEPATH += $$PWD/../Source
DEPENDPATH += $$PWD/../Source
