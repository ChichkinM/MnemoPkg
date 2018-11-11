INCLUDEPATH += $$PWD

HEADERS += \
    $$PWD/mnemopkg.h \
    $$PWD/mnemoconfig.h \
    $$PWD/mnemohelper.h \
    $$PWD/mnemohandler.h

SOURCES += \
    $$PWD/mnemoconfig.cpp

RESOURCES += \
    $$PWD/qrc.qrc

include (Lib/CLine/Cline.pri)
