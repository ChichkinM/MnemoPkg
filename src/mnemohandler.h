#ifndef MNEMOHANDLER_H
#define MNEMOHANDLER_H

#include <QVariant>
#include <QObject>

class MnemoHandler : public QObject
{
    Q_OBJECT
public:
    explicit MnemoHandler(QObject *qmlRootObject, QObject *parent = nullptr) : QObject(parent) {
        this->qmlRootObject = qmlRootObject;
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
//            else {
//                QObject *parentObject = qmlRootObj->findChild<QObject*>(parentObjectName);
//                if (parentObject != nullptr)
//                    emit Config::get()->setColorForRepeaterChild(parentObj, objName,
//                                                                    propertyName, propertyValue);
//            }
        }
    }

private:
    QObject *qmlRootObject = nullptr;
};

#endif // MNEMOHANDLER_H
