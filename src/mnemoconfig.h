#ifndef MNEMOCONFIG_H
#define MNEMOCONFIG_H

#include <QObject>

class MnemoConfig : public QObject
{
    Q_OBJECT

    Q_PROPERTY(double scale READ scale WRITE setScale NOTIFY scaleChanged)
    Q_PROPERTY(int minSize READ minSize WRITE setMinSize NOTIFY scaleChanged)

public:
    MnemoConfig(QObject *parent = nullptr) : QObject(parent) {

    }
    ~MnemoConfig() { }


    double scale() const { return m_scale; }
    void setScale(double scale) {
        if (m_scale != scale) {
            m_scale = scale;

            emit scaleChanged(scale);
        }
    }

    int minSize() const { return m_minSize; }
    void setMinSize(int value) { m_minSize = value; }

private:
    double m_scale = 1;
    int m_minSize = 6;

signals:
    void scaleChanged(double scale);
};

#endif // MNEMOCONFIG_H
