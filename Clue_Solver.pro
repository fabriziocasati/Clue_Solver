QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Clue_Solver
TEMPLATE = app


SOURCES += \
    main.cpp \
    Main.cpp

HEADERS += \
    Main.h

RESOURCES += \
    resources.qrc

# Subfolders
include(reasoner/reasoner.pri)
include(gui/gui.pri)
include(game/game.pri)
