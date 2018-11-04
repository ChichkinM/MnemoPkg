#include "mnemopkg.h"

#include <QDebug>
#include <QQmlContext>

MnemoPkg::MnemoPkg(QQmlEngine *engine, QObject *parent) : QObject(parent) {
    engine->rootContext()->setContextProperty("ConfigObj", &mnemoConfig);
    qmlRegisterType<MnemoConfig>("ConfigType", 1, 0, "ConfigType");
}