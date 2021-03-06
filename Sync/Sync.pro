QT += core network multimedia sql
android: QT += androidextras
mac: QT += macextras
CONFIG += c++14

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Sync
TEMPLATE = lib

include('$$PWD/../QuasarAppLib/QuasarLib.pri');

DEFINES += SYNC_LIBRARY

CONFIG(release, debug|release): {
    DESTDIR = $$PWD/build/release

} else {
    DESTDIR = $$PWD/build/debug
}

DISTFILES += \
    sql/InitLacaleDataBase.sql

HEADERS += \
    basepackage.h \
    chronotime.h \
    config.h \
    ETcpSocket.h \
    exaptions.h \
    LocalScanner.h \
    Log.h \
    mysql.h \
    node.h \
    player.h \
    playlist.h \
    song.h \
    sync.h \
    syncpackage.h \
    sync_global.h

SOURCES += \
    basepackage.cpp \
    chronotime.cpp \
    ETcpSocket.cpp \
    exaptions.cpp \
    LocalScanner.cpp \
    Log.cpp \
    mysql.cpp \
    node.cpp \
    player.cpp \
    playlist.cpp \
    song.cpp \
    sync.cpp \
    syncpackage.cpp
