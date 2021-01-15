QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    card.cpp \
    cardcreator.cpp \
    controller.cpp \
    cpuplayer.cpp \
    cpuplayerinfo.cpp \
    discardcardscard.cpp \
    drawcardscard.cpp \
    healcard.cpp \
    healtheffectcard.cpp \
    main.cpp \
    model.cpp \
    multipleattackcard.cpp \
    player.cpp \
    playercardseffectcard.cpp \
    playerinfo.cpp \
    radiobuttonslist.cpp \
    singleattackcard.cpp \
    skipturncard.cpp \
    view.cpp

HEADERS += \
    DLList.h \
    card.h \
    cardcreator.h \
    controller.h \
    cpuplayer.h \
    cpuplayerinfo.h \
    deck.h \
    deepptr.h \
    discardcardscard.h \
    drawcardscard.h \
    healcard.h \
    healtheffectcard.h \
    model.h \
    multipleattackcard.h \
    player.h \
    playercardseffectcard.h \
    playerinfo.h \
    radiobuttonslist.h \
    singleattackcard.h \
    skipturncard.h \
    view.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
