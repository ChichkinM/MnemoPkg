#ifndef MYMNEMO_H
#define MYMNEMO_H

#include <QObject>
#include <QTimer>

#include "mnemopkg.h"

class MyMnemo : public MnemoPkg
{
    Q_OBJECT
public:
    MyMnemo(QQmlApplicationEngine *engine, QObject *parent = nullptr) : MnemoPkg(engine, parent) {
        QTimer *t = new QTimer();
        connect(t, &QTimer::timeout, this, [this]() {
            static int i = 0;
            i++;

            if (i % 2 == 0)
                handler.setPropertySafely("page1_i2", "borderColor", "green");
            else
                handler.setPropertySafely("page1_i2", "borderColor", "red");
        });
        t->start(1000);
    }
};

#endif // MYMNEMO_H
