#ifndef MNEMOPKG_H
#define MNEMOPKG_H

#include <QObject>

class MnemoPkg : public QObject
{
    Q_OBJECT
public:
    explicit MnemoPkg(QObject *parent = nullptr);

signals:

public slots:
};

#endif // MNEMOPKG_H