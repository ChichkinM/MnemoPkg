#ifndef MNEMOCONFIG_H
#define MNEMOCONFIG_H

#include <QObject>
#include <QDebug>

class MnemoConfig : public QObject
{
    Q_OBJECT

    Q_PROPERTY(double scale READ scale WRITE setScale NOTIFY scaleChanged)
    Q_PROPERTY(double minSizeScaled READ minSizeScaled NOTIFY scaleChanged)
    Q_PROPERTY(int minSizeScaledRounded READ minSizeScaledRounded NOTIFY scaleChanged)
    Q_ENUMS(Colors)

public:
    MnemoConfig(QObject *parent = nullptr) : QObject(parent) {

    }
    ~MnemoConfig() { }


    Q_INVOKABLE int minSize() const { return m_minSize; }

    double scale() const { return m_scale; }
    double minSizeScaled() const { return m_minSize * m_scale; }
    int minSizeScaledRounded() const { return m_minSize * m_scale; }

    enum class Colors { DefaultColorForIndicatorBorder, GoodColorForIndicatorBorder, BadColorForIndicatorBorder,
                        DefaultColorForIndicatorFilling, GoodColorForIndicatorFilling, BadColorForIndicatorFilling};

    Q_INVOKABLE QVariant getPropertyFromSettings(Colors colorEnum) {
        switch (colorEnum) {
        case Colors::DefaultColorForIndicatorBorder:
            return "steelblue";
        default:
            return "black";
        }
    }

private:
    double m_scale = 1;
    int m_minSize = 6;

signals:
    void scaleChanged(double scale);

public slots:
    void setScale(double scale) {
        if (m_scale != scale) {
            m_scale = scale;

            emit scaleChanged(scale);
        }
    }
};

#endif // MNEMOCONFIG_H
