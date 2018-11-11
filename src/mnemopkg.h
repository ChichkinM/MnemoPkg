#ifndef MNEMOPKG_H
#define MNEMOPKG_H

#include <QDebug>
#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "mnemoconfig.h"
#include "mnemohelper.h"
#include "mnemohandler.h"

#include "cline.h"


class MnemoPkg : public QObject
{
    Q_OBJECT
public:
    explicit MnemoPkg(QQmlApplicationEngine *engine, QObject *parent = nullptr) : QObject(parent) {
        connect(engine, SIGNAL(objectCreated(QObject*,QUrl)), &handler, SLOT(setRootObject(QObject*)));
        registerComponents(engine);
    }

    explicit MnemoPkg(QQmlEngine *engine, QObject *parent = nullptr) : QObject(parent) {
        registerComponents(engine);
    }

    MnemoHandler handler;

protected:
    MnemoConfig mnemoConfig;
    MnemoHelper mnemoHelper;

private:
    void registerComponents(QQmlEngine *engine) {
        connect(&handler, SIGNAL(setPropertyForNestedItem(QObject*,QString,QString,QVariant)),
                &mnemoHelper, SIGNAL(setPropertyForNestedItem(QObject*,QString,QString,QVariant)));

        engine->rootContext()->setContextProperty("MnemoConfigObj", &mnemoConfig);
        engine->rootContext()->setContextProperty("MnemoHelper", &mnemoHelper);

        qmlRegisterType<MnemoConfig>("MnemoConfigType", 1, 0, "MnemoConfigType");
        CLine::registerComponents();
    }
};

#endif // MNEMOPKG_H
