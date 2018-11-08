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
    Q_ENUMS(Colors)

public:
    MnemoConfig(QObject *parent = nullptr) : QObject(parent) {
        if (!QFile::exists("MnemoSettings.ini"))
            QFile::copy(":/MnemoSettings.ini", "MnemoSettings.ini");

        settings = new QSettings("MnemoSettings.ini", QSettings::IniFormat);
    }
    ~MnemoConfig() {
        delete settings;
    }


    Q_INVOKABLE int minSize() const { return m_minSize; }

    double scale() const { return m_scale; }
    double minSizeScaled() const { return m_minSize * m_scale; }
    int minSizeScaledRounded() const { return m_minSize * m_scale; }

    enum class Colors {
        Background,
        DefaultColorForIndicatorBorder, GoodColorForIndicatorBorder, BadColorForIndicatorBorder,
        DefaultColorForIndicatorFilling, GoodColorForIndicatorFilling, BadColorForIndicatorFilling,
        DefaultColorForIndicatorText, GoodColorForIndicatorText, BadColorForIndicatorText,
        DefaultColorForLine, GoodColorForLine, BadColorForLine,
        DefaultColorForLabel, GoodColorForLabel, BadColorForLabel

    };

    Q_INVOKABLE QVariant getPropertyFromSettings(Colors colorEnum) {
        auto getValue = [this](QString value, QString defaultValue) {
            return settings->value(settings->value("General/Theme", "Dark").toString() + "/" + value, defaultValue);
        };

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

        default:
            return "black";
        }
    }

private:
    double m_scale = 1;
    int m_minSize = 6;

    QSettings *settings;

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
