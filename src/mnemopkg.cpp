#include "mnemopkg.h"

#include <QDebug>
#include <QQmlContext>

MnemoPkg::MnemoPkg(QQmlEngine *engine, QObject *parent) : QObject(parent)
{
    qDebug() << "MnemoPkg::MnemoPkg";
    engine->rootContext()->setContextProperty("Config", &mnemoConfig);
}
