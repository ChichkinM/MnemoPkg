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
    MnemoConfig(QObject *parent = nullptr) : QObject(parent) {
        if (!QFile::exists("MnemoSettings.ini"))
            QFile::copy(":/MnemoSettings.ini", "MnemoSettings.ini");

        settings = new QSettings("MnemoSettings.ini", QSettings::IniFormat);

        m_lineWidth = getValue("Line/Width", "2").toInt();
        m_lineRadius = getValue("Line/Radius", "0").toInt();
        m_indicatorBorderRadius = getValue("Indicator/Border/Radius", "0").toInt();
        m_indicatorFillingRadius = getValue("Indicator/Border/Filling", "0").toInt();
        m_minFont = getValue("General/MinFont", "8").toInt();
    }
    ~MnemoConfig() {
        delete settings;
    }


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

    Q_INVOKABLE QVariant getPropertyFromSettings(Colors colorEnum) {
        switch (colorEnum) {
        case Colors::Background:
            return getValue("Background", "black");

        case Colors::DefaultColorForIndicatorBorder:
            return getValue("Indicator/Border/Default", "blue");
        case Colors::GoodColorForIndicatorBorder:
            return getValue("Indicator/Border/Good", "green");
        case Colors::BadColorForIndicatorBorder:
            return getValue("Indicator/Border/Bad", "red");

        case Colors::DefaultColorForIndicatorFilling:
            return getValue("Indicator/Filling/Default", "blue");
        case Colors::GoodColorForIndicatorFilling:
            return getValue("Indicator/Filling/Good", "green");
        case Colors::BadColorForIndicatorFilling:
            return getValue("Indicator/Filling/Bad", "red");

        case Colors::DefaultColorForIndicatorText:
            return getValue("Indicator/Text/Default", "blue");
        case Colors::GoodColorForIndicatorText:
            return getValue("Indicator/Text/Good", "green");
        case Colors::BadColorForIndicatorText:
            return getValue("Indicator/Text/Bad", "red");
        case Colors::FamilyForIndicatorText:
            return getValue("Indicator/Text/Family", "Arial");
        case Colors::BoldForIndicatorText:
            return getValue("Indicator/Text/Bold", "true");

        case Colors::DefaultColorForLine:
            return getValue("Line/Default", "blue");
        case Colors::GoodColorForLine:
            return getValue("Line/Good", "green");
        case Colors::BadColorForLine:
            return getValue("Line/Bad", "red");

        case Colors::DefaultColorForLabel:
            return getValue("Label/Default", "blue");
        case Colors::GoodColorForLabel:
            return getValue("Label/Good", "green");
        case Colors::BadColorForLabel:
            return getValue("Label/Bad", "red");
        case Colors::FamilyForLabel:
            return getValue("Label/Family", "Sans");
        case Colors::BoldForLabel:
            return getValue("Label/Bold", "false");

        default:
            return "black";
        }
    }

private:
    double m_scale = 1;
    int m_minSize = 6;
    int m_minFont = 0;

    int m_lineWidth = 0;
    int m_lineRadius = 0;
    int m_indicatorBorderRadius = 0;
    int m_indicatorFillingRadius = 0;

    QSettings *settings = nullptr;


    QVariant getValue(QString value, QString defaultValue) {
        if (settings != nullptr)
            return settings->value(settings->value("General/Theme", "Dark").toString() + "/" + value, defaultValue);
        return QVariant();
    }

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
