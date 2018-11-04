INCLUDEPATH += $$PWD

HEADERS += \
    $$PWD/mnemopkg.h \
    $$PWD/mnemoconfig.h

SOURCES += \
    $$PWD/mnemopkg.cpp

RESOURCES += \
    $$PWD/qrc.qrc

include (Lib/CLine/Cline.pri)
