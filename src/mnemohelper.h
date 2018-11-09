#ifndef MNEMOHELPER_H
#define MNEMOHELPER_H

#include <QObject>
#include <QVariant>

class MnemoHelper : public QObject
{
    Q_OBJECT
public:
    explicit MnemoHelper(QObject *parent = nullptr) : QObject(parent) {

    }

    Q_INVOKABLE QObject *findChild(QObject *root, QString objectName) {
        return root->findChild<QObject*>(objectName);
    }

    Q_INVOKABLE bool setProperty(QObject *object, QString property, QVariant value) {
        return object->setProperty(property.toLatin1(), value);
    }

signals:
    void setPropertyForNestedItem(QObject *repeaterObj, QString childObjName,
                                  QString propertyName, QVariant value);
};

#endif // MNEMOHELPER_H
