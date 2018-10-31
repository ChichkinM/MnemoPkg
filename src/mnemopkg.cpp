#include "mnemopkg.h"

#include <QDebug>

MnemoPkg::MnemoPkg(QObject *parent) : QObject(parent)
{
    qDebug() << "MnemoPkg::MnemoPkg";
}
