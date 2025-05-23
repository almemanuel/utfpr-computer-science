QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    display_file.cpp \
    main.cpp \
    mainwindow.cpp \
    meu_frame.cpp \
    objeto_geometrico.cpp \
    poligono.cpp \
    ponto.cpp \
    reta.cpp \
    transformacao.cpp

HEADERS += \
    display_file.h \
    mainwindow.h \
    meu_frame.h \
    objeto_geometrico.h \
    poligono.h \
    ponto.h \
    reta.h \
    transformacao.h

FORMS += \
    mainwindow.ui

CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
