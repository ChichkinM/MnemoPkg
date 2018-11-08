#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "mnemopkg.h"
#include "mnemobehavior.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    MnemoPkg pkg(&engine);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    MnemoBehavior behavior(engine.rootObjects().at(0));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
