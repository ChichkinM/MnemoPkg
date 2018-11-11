#ifndef MNEMOHELPER_H
#define MNEMOHELPER_H

#include <QObject>
#include <QVariant>
#include <QDebug>

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


    Q_INVOKABLE void saveItemWithFocus(QString pageObjectName, QString itemObjectName) {
        itemsWithFocus.insert(pageObjectName, itemObjectName);
    }

    Q_INVOKABLE QString getItemWithFocus(QString pageObjectName) {
        return itemsWithFocus.value(pageObjectName);
    }

    Q_INVOKABLE void trySetDefaultItemWithFocus(QString pageObjectName, QString itemObjectName) {
        if (itemsWithFocus.value(pageObjectName).isEmpty())
            itemsWithFocus.insert(pageObjectName, itemObjectName);
    }

private:
    QMap<QString, QString> itemsWithFocus;

signals:
    void setPropertyForNestedItem(QObject *repeaterObj, QString childObjName,
                                  QString propertyName, QVariant value);
};

#endif // MNEMOHELPER_H
