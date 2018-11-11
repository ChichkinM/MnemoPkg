#ifndef MYMNEMO_H
#define MYMNEMO_H

#include <QObject>
#include <QTimer>

#include "mnemopkg.h"

class MyMnemo : public MnemoPkg
{
    Q_OBJECT
public:
    MyMnemo(QQmlApplicationEngine *engine, QObject *parent = nullptr) : MnemoPkg(engine, parent) {
        QTimer *t = new QTimer();
        connect(t, &QTimer::timeout, this, [this]() {
            static int i = 0;
            i++;

            if (i % 2 == 0) {
                handler.setPropertySafely("page1_i2", "borderColor", mnemoConfig.getPropertyFromSettings(
                                              MnemoConfig::Colors::GoodColorForIndicatorBorder));
                handler.setPropertySafely("page1_i1", "fillingColor", mnemoConfig.getPropertyFromSettings(
                                              MnemoConfig::Colors::GoodColorForIndicatorFilling));
                handler.setPropertySafely("page1_l1", "color", mnemoConfig.getPropertyFromSettings(
                                              MnemoConfig::Colors::GoodColorForLine));

                handler.setPropertySafely("page3_i1", "borderColor", mnemoConfig.getPropertyFromSettings(
                                              MnemoConfig::Colors::GoodColorForIndicatorBorder), "page3_repeater");
            } else {
                handler.setPropertySafely("page1_i2", "borderColor", mnemoConfig.getPropertyFromSettings(
                                              MnemoConfig::Colors::BadColorForIndicatorBorder));
                handler.setPropertySafely("page1_i1", "fillingColor", mnemoConfig.getPropertyFromSettings(
                                              MnemoConfig::Colors::DefaultColorForIndicatorFilling));
                handler.setPropertySafely("page1_l1", "color", mnemoConfig.getPropertyFromSettings(
                                              MnemoConfig::Colors::BadColorForLine));

                handler.setPropertySafely("page3_i1", "borderColor", mnemoConfig.getPropertyFromSettings(
                                              MnemoConfig::Colors::BadColorForIndicatorBorder), "page3_repeater");
            }
        });
        t->start(1000);
    }
};

#endif // MYMNEMO_H
