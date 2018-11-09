#ifndef MNEMOHANDLER_H
#define MNEMOHANDLER_H

#include <QVariant>
#include <QObject>

class MnemoHandler : public QObject
{
    Q_OBJECT
public:
    explicit MnemoHandler(QObject *parent = nullptr) : QObject(parent) { }
    explicit MnemoHandler(QObject *qmlRootObject, QObject *parent = nullptr) : QObject(parent) {
        setRootObject(qmlRootObject);
    }

    /* parentObjName может быть использован, для доступа к объектам через индексы.
     * Например, когда необходимо установить свойство child объекта в Repeater-е. */
    void setPropertySafely(QString objectName, QString propertyName, QVariant propertyValue, QString parentObjectName = "") {
        if (qmlRootObject != nullptr) {

            if (parentObjectName.isEmpty()) {
                QObject *obj = qmlRootObject->findChild<QObject*>(objectName);
                if (obj != nullptr)
                    obj->setProperty(propertyName.toLatin1(), propertyValue);
            }
            else {
                QObject *parentObject = qmlRootObject->findChild<QObject*>(parentObjectName);
                if (parentObject != nullptr)
                    emit setPropertyForNestedItem(parentObject, objectName, propertyName, propertyValue);
            }
        }
    }

public slots:
    void setRootObject(QObject *qmlRootObject) {
        this->qmlRootObject = qmlRootObject;
    }

private:
    QObject *qmlRootObject = nullptr;

signals:
    void setPropertyForNestedItem(QObject *repeaterObj, QString childObjName,
                                  QString property, QVariant value);
};

#endif // MNEMOHANDLER_H
