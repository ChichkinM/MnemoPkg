#include "mnemopkg.h"

#include <QDebug>
#include <QQmlContext>

#include "cline.h"

MnemoPkg::MnemoPkg(QQmlEngine *engine, QObject *parent) : QObject(parent) {
    engine->rootContext()->setContextProperty("ConfigObj", &mnemoConfig);
    engine->rootContext()->setContextProperty("MnemoHelper", &mnemoHelper);

    qmlRegisterType<MnemoConfig>("ConfigType", 1, 0, "ConfigType");
    CLine::registerComponents();
}
