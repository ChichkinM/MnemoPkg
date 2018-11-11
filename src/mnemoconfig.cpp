#include "mnemoconfig.h"

MnemoConfig::MnemoConfig(QObject *parent) : QObject(parent) {
    if (!QFile::exists("MnemoSettings.ini"))
        QFile::copy(":/MnemoSettings.ini", "MnemoSettings.ini");

    settings = new QSettings("MnemoSettings.ini", QSettings::IniFormat);

    m_lineWidth = getValue("Line/Width", "2").toInt();
    m_lineRadius = getValue("Line/Radius", "0").toInt();
    m_indicatorBorderRadius = getValue("Indicator/Border/Radius", "0").toInt();
    m_indicatorFillingRadius = getValue("Indicator/Border/Filling", "0").toInt();
    m_minFont = getValue("MinFont", "8").toInt();
}

MnemoConfig::~MnemoConfig() {
    delete settings;
}

QVariant MnemoConfig::getValue(QString value, QString defaultValue) {
    if (settings != nullptr)
        return settings->value(settings->value("Theme", "Dark").toString() + "/" + value, defaultValue);
    return QVariant();
}

void MnemoConfig::setScale(double scale) {
    if (m_scale != scale) {
        m_scale = scale;

        emit scaleChanged(scale);
    }
}

QVariant MnemoConfig::getPropertyFromSettings(MnemoConfig::Colors colorEnum) {
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
