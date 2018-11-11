#ifndef MNEMOCONFIG_H
#define MNEMOCONFIG_H

#include <QObject>
#include <QSettings>
#include <QFile>
#include <QDebug>

class MnemoConfig : public QObject
{
    Q_OBJECT

    Q_PROPERTY(double scale READ scale WRITE setScale NOTIFY scaleChanged)
    Q_PROPERTY(double minSizeScaled READ minSizeScaled NOTIFY scaleChanged)
    Q_PROPERTY(int minSizeScaledRounded READ minSizeScaledRounded NOTIFY scaleChanged)
    Q_PROPERTY(double minFontScaled READ minFontScaled NOTIFY scaleChanged)

    Q_PROPERTY(int lineWidthScaledRounded READ lineWidthScaledRounded NOTIFY scaleChanged)
    Q_PROPERTY(int lineRadiusScaledRounded READ lineRadiusScaledRounded NOTIFY scaleChanged)
    Q_PROPERTY(int indicatorBorderRadiusScaledRounded READ indicatorBorderRadiusScaledRounded NOTIFY scaleChanged)
    Q_PROPERTY(int indicatorFillingRadiusScaledRounded READ indicatorBorderRadiusScaledRounded NOTIFY scaleChanged)
    Q_ENUMS(Colors)

public:
    MnemoConfig(QObject *parent = nullptr);
    ~MnemoConfig();


    Q_INVOKABLE int minSize() const { return m_minSize; }

    double scale() const { return m_scale; }
    double minSizeScaled() const { return m_minSize * m_scale; }
    int minSizeScaledRounded() const { return m_minSize * m_scale; }
    double minFontScaled() const { return m_minFont * m_scale; }

    int lineWidthScaledRounded() const { return m_lineWidth * m_scale; }
    int lineRadiusScaledRounded() const { return m_lineRadius * m_scale; }
    int indicatorBorderRadiusScaledRounded() const { return m_indicatorBorderRadius * m_scale; }
    int indicatorFillingRadiusScaledRounded() const { return m_indicatorFillingRadius * m_scale; }

    enum class Colors {
        Background,
        DefaultColorForIndicatorBorder, GoodColorForIndicatorBorder, BadColorForIndicatorBorder,
        DefaultColorForIndicatorFilling, GoodColorForIndicatorFilling, BadColorForIndicatorFilling,
        FamilyForIndicatorText, BoldForIndicatorText,
        DefaultColorForIndicatorText, GoodColorForIndicatorText, BadColorForIndicatorText,
        DefaultColorForLine, GoodColorForLine, BadColorForLine,
        DefaultColorForLabel, GoodColorForLabel, BadColorForLabel, FamilyForLabel, BoldForLabel

    };

    Q_INVOKABLE QVariant getPropertyFromSettings(Colors colorEnum);

private:
    double m_scale = 1;
    int m_minSize = 6;
    int m_minFont = 0;

    int m_lineWidth = 0;
    int m_lineRadius = 0;
    int m_indicatorBorderRadius = 0;
    int m_indicatorFillingRadius = 0;

    QSettings *settings = nullptr;


    QVariant getValue(QString value, QString defaultValue);

signals:
    void scaleChanged(double scale);

public slots:
    void setScale(double scale);
};

#endif // MNEMOCONFIG_H
