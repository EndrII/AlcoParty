
TEMPLATE = aux

SNAPCRAFT = runSnap.sh

DESTDIR = $$PWD

INPUT = $$PWD/snap/snapcraft.yaml
snapApp.input = INPUT
snapApp.output = $$SNAPCRAFT
LINUXDEPLOY = $$PWD/../../../CQtDeployer/build/release/CQtDeployer

QT_DIR = $$dirname(QMAKE_QMAKE)
QML_DIR = $$PWD/../../../SoundBand

unix {
    message($$DESTDIR);
    message($$TARGET_LIST);

    for(command, TARGET_LIST) {
        snapApp.commands += $$LINUXDEPLOY -bin $$TARGET_PATH/$$command -qmlDir $$QML_DIR -qmake $$QMAKE_QMAKE &&
    }

    snapApp.commands += $$DESTDIR/$$SNAPCRAFT
    snapApp.CONFIG += target_predeps no_link combine

    message( snapComands = "$$snapApp.commands")
}


QMAKE_EXTRA_COMPILERS += snapApp

DISTFILES += \

unix:extraclean.commands = $$SNAPCRAFT clean soundband

distclean.depends = extraclean
QMAKE_EXTRA_TARGETS += distclean extraclean
