QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    atualizar.cpp \
    bancodados.cpp \
    cadastro.cpp \
    checklogin.cpp \
    main.cpp \
    mainwindow.cpp \
    telalogin.cpp \
    user.cpp

HEADERS += \
    atualizar.h \
    bancodados.h \
    cadastro.h \
    checklogin.h \
    mainwindow.h \
    telalogin.h \
    user.h

FORMS += \
    atualizar.ui \
    cadastro.ui \
    checklogin.ui \
    mainwindow.ui \
    telalogin.ui

TRANSLATIONS += \
    CRUD_pt_BR.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
