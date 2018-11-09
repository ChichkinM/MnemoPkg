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
        engine->rootContext()->setContextProperty("ConfigObj", &mnemoConfig);
        engine->rootContext()->setContextProperty("MnemoHelper", &mnemoHelper);

        qmlRegisterType<MnemoConfig>("ConfigType", 1, 0, "ConfigType");
        CLine::registerComponents();

        connect(engine, SIGNAL(objectCreated(QObject*,QUrl)), this, SLOT(addRootObject(QObject*)));
    }

public slots:
    void addRootObject(QObject *qmlRootObject) {
        handler = new MnemoHandler(qmlRootObject);
    }

protected:
    MnemoConfig mnemoConfig;
    MnemoHelper mnemoHelper;
    MnemoHandler *handler = nullptr;
};

#endif // MNEMOPKG_H
