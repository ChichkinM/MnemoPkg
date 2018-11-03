#ifndef MNEMOCONFIG_H
#define MNEMOCONFIG_H

#include <QObject>

class MnemoConfig : public QObject
{
    Q_OBJECT
public:
    MnemoConfig(QObject *parent = nullptr) : QObject(parent) {

    }
    ~MnemoConfig() { }
};

#endif // MNEMOCONFIG_H
