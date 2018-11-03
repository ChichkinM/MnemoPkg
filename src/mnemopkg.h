#ifndef MNEMOPKG_H
#define MNEMOPKG_H

#include <QObject>
#include <QQmlEngine>
#include "mnemoconfig.h"

class MnemoPkg : public QObject
{
    Q_OBJECT
public:
    explicit MnemoPkg(QQmlEngine *engine, QObject *parent = nullptr);

private:
    MnemoConfig mnemoConfig;

signals:

public slots:
};

#endif // MNEMOPKG_H
