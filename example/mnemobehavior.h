#ifndef MNEMOBEHAVIOR_H
#define MNEMOBEHAVIOR_H

#include <QObject>
#include "mnemohandler.h"

class MnemoBehavior : public QObject
{
    Q_OBJECT
public:
    MnemoBehavior(QObject *qmlRootObject, QObject *parent = nullptr) : QObject(parent) {
        handler = new MnemoHandler(qmlRootObject, this);

        handler->setPropertySafely("page1_i1", "borderColor", "green");
    }

private:
    MnemoHandler *handler = nullptr;
};

#endif // MNEMOBEHAVIOR_H
