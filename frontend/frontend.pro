QT       += core gui
QT += network
<<<<<<< HEAD
QT += sql

=======
<<<<<<< HEAD
<<<<<<< HEAD
QT +=sql
=======
QT += sql

>>>>>>> 658ea41d5065f5ff1dc63744e348242dc598a9d6
=======
>>>>>>> be618614738eeebfdc208efeda32e0f044646eeb
>>>>>>> 97c11493969ba6a7ca8972acff999586794d6e9e
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    choosecard.cpp \
    loginwindow.cpp \
    luottoraja.cpp \
    main.cpp \
    mainwindow.cpp \
    menuwindow.cpp \
    myurl.cpp \
    otto.cpp \
    saldo.cpp \
    tilitapahtumat.cpp

HEADERS += \
    choosecard.h \
    loginwindow.h \
    luottoraja.h \
    mainwindow.h \
    menuwindow.h \
    myurl.h \
    otto.h \
    saldo.h \
    tilitapahtumat.h

FORMS += \
    choosecard.ui \
    loginwindow.ui \
    luottoraja.ui \
    mainwindow.ui \
    menuwindow.ui \
    otto.ui \
    saldo.ui \
    tilitapahtumat.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
