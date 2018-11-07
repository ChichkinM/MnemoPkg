#ifndef MNEMOHELPER_H
#define MNEMOHELPER_H

#include <QObject>

class MnemoHelper : public QObject
{
    Q_OBJECT
public:
    explicit MnemoHelper(QObject *parent = nullptr) : QObject(parent) {

    }

    Q_INVOKABLE QObject *findChild(QObject *root, QString objectName) {
        return root->findChild<QObject*>(objectName);
    }
};

#endif // MNEMOHELPER_H
