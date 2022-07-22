QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    agregarproducto.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    agregarproducto.h \
    mainwindow.h

FORMS += \
    agregarproducto.ui \
    mainwindow.ui

TRANSLATIONS += \
    ControlTienda_ui_es_CR.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../src/tiendaLocal/release/ -ltiendaLocal
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../src/tiendaLocal/debug/ -ltiendaLocal
else:unix: LIBS += -L$$OUT_PWD/../src/tiendaLocal/ -ltiendaLocal

INCLUDEPATH += $$PWD/../src/tiendaLocal
DEPENDPATH += $$PWD/../src/tiendaLocal

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../src/tiendaLocal/release/libtiendaLocal.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../src/tiendaLocal/debug/libtiendaLocal.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../src/tiendaLocal/release/tiendaLocal.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../src/tiendaLocal/debug/tiendaLocal.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../src/tiendaLocal/libtiendaLocal.a
