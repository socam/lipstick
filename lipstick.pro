TEMPLATE = subdirs
CONFIG += ordered console
SUBDIRS += src plugin tools

tools.depends = src

QMAKE_CLEAN += \
    build-stamp \
    configure-stamp \
    artifacts/*.deb \
    *.log.xml \
    *.log

QMAKE_DISTCLEAN += \
    build-stamp \
    configure-stamp \
    *.log.xml \
    *.log

OTHER_FILES += \
    qtc_packaging/meego.spec
