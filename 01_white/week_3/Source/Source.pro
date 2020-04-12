CONFIG -= qt

TEMPLATE = lib
TARGET=WhiteWeek03

CONFIG += c++1z
#Linking as an internal lib.
#LIB_DIR = /../WhiteWeek03_Lib

#build_pass:CONFIG(debug, debug|release){
#DESTDIR=$$PWD$$LIB_DIR
#} else {
#DESTDIR=$$PWD$$LIB_DIR
#}


# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    wt_w3_Input.cpp

HEADERS += \
    wt_w3_Input.h \
    wt_w3_e01.h \
    wt_w3_e02.h \
    wt_w3_e03.h \
    wt_w3_e04.h \
    wt_w3_e05.h \
    wt_w3_e06.h \
    wt_w3_e07.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
