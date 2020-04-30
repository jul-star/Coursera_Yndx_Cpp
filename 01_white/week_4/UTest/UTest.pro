include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++1z
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
    ToTest.h \
#    tst_wt_w4_e01.h \
#    tst_wt_w4_e02.h \
#    tst_wt_w4_e03.h \
#    tst_wt_w4_e04.h \
#    tst_wt_w4_e05.h \
#    tst_wt_w4_e06.h \
#    tst_wt_w4_e07.h \
#    tst_wt_w4_e08.h \
#    tst_wt_w4_e09.h \
    tst_wt_w4_e10.h \
    tst_wt_w4_e11.h \
    tst_wt_w4_e12.h


SOURCES += \
        main.cpp


#win32: LIBS += -L$$PWD/../WhiteWeek04_Lib/ -lWhiteWeek04

INCLUDEPATH += $$PWD/../Source
DEPENDPATH += $$PWD/../Source
