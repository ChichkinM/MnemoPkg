#ifndef MNEMOPKG_H
#define MNEMOPKG_H

#include <QObject>
#include <QQmlEngine>

#include "mnemoconfig.h"
#include "mnemohelper.h"

class MnemoPkg : public QObject
{
    Q_OBJECT
public:
    explicit MnemoPkg(QQmlEngine *engine, QObject *parent = nullptr);

private:
    MnemoConfig mnemoConfig;
    MnemoHelper mnemoHelper;

signals:

public slots:
};

#endif // MNEMOPKG_H
