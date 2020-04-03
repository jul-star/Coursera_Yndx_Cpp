TEMPLATE = app
CONFIG += console c++1z
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp



win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Source/release/ -lWhiteWeek02
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Source/debug/ -lWhiteWeek02

INCLUDEPATH += $$PWD/../Source
DEPENDPATH += $$PWD/../Source
