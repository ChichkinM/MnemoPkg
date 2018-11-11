# MnemoPkg
Набор компонентов для формирования мнемосхем с использованием Qt и QML.

## Get Started


### Подключение к проекту
Поместите исходники данного репозитория (папка src) в отдельной папке вашег проекта.
Перейдите в .pro файл вашего проекта и пропишите там следующее:

    include(Some/Path/MnemoPkg.pri)
    
### Создание вспомогательных компонентов в C++
Графические части не могут функционировать полностью автономно. Для них нужны дополнительно зарегестрированные типы и классы.
Создадим новый класс C++ и унаследуем его от класса MnemoPkg:

	#include "mnemopkg.h"
  
    class MyMnemo : public MnemoPkg
    {
        Q_OBJECT
    public:
        MyMnemo(QQmlApplicationEngine *engine, QObject *parent = nullptr) : MnemoPkg(engine, parent) { }
    };
    
Конструктору класса MnemoPkg необходимо передать указатель на QQmlApplicationEngine или QQmlEngine до того, как вызвалась функция load! 
Это необходимо для корректной регистрации всех компонентов.
Соответственно, создадим объект нашего класса до вызова данной функции:

    int main() {
        ...
        QQmlApplicationEngine engine;
        MyMnemo m(&engine);

        engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
        ...
    }
    
При использовании QQmlEngine необходимы дополнительные действия после функции load:

    int main() {
        ...
        QQmlEngine engine;
        MyMnemo m(&engine);

        engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
        m.handler.setRootObject(engine.rootObjects().at(0));
        ...
    }
    
### Создание графической части
Создадим qml файл с первой страницей мнемосхемы и простейшим индикатором:

    import "qrc:/Mnemo" as Mnemo
    
    Mnemo.MnemoPage {
        Mnemo.Indicator {
            anchors.centerIn: parent
        }
    }

В тот файл, в котором предполагается размещение мнемосхемы создадим основной объект, который будет загружать первую страницу:

    import "qrc:/Mnemo" as Mnemo
    
    Window {
        width: 640
        height: 480

        Mnemo.Main {
            anchors.fill: parent
            mainPageSource: "qrc:/Page1.qml"
        }
    }
    
### Панель навигации на странице
У объекта MnemoPage имеются настройки верхней панели:

    Mnemo.MnemoPage {
        showBackBtn: false
        showHomeBtn: false
        showPageTitle: false
        title: "Привет"
    }
    
### Навигация между страницами
Создадим вторую страницу, аналогичную первой. Для перехода на нее будем кликать по индикатору мышью:

    Mnemo.Indicator {
        onGoInside: goTo("qrc:/Page2.qml")
    }
    
Переход на основную страницу работает всегда с любой страницы ("Домой" на верхней панели или Esc). 
Переход на предыдущую страницу ("Назад" на верхней панели или BackSpace) необходимо указывать дополнительно:
    Mnemo.MnemoPage {
        onGoBack: goTo("qrc:/Page1.qml")
    }

### Навигация по индикаторам
На странице необходимо установить objectName первого индикатора, а в самих индикаторах прописать ссылки не переходы.
Для сохранения предыдущего положения указателя на активный инликатор необходимо установить objectName-ы как для инликаторов, так и для страниц.

    Mnemo.MnemoPage {
    objectName: "page2"
    defaultFoucusObjectName: i1.objectName
    
        Mnemo.Indicator {
            id: i1
            objectName: makeObjectName("i1") //будет page2_i1
            KeyNavigation.down: i2
        }
    
        Mnemo.Indicator {
            objectName: makeObjectName("i2") //будет page2_i2
            id: i2
        }
        
Теперь Enter должен работать для перехода во вложенную страницу.

### Подсветка мнемосхемы
Наиболее простой способ подсветки- установка свойств объектов через C++. 
Для этого в QML у каждого "активного" объекта должен быть установлен objectName.
Пример установки цвета:

    MyMnemo(QQmlApplicationEngine *engine, QObject *parent = nullptr) : MnemoPkg(engine, parent) {
        handler.setPropertySafely("page1_i1", "fillingColor", "orange");
    }
    
### Настройки
Некоторые вета могут пробрасываться из файла настроек MnemoSettings.ini. Данный файл создается автоматически рядом с бинарным файлом.
Для того, чтоб использовать цвета из него модифицируем предыдущий пример:

    MyMnemo(QQmlApplicationEngine *engine, QObject *parent = nullptr) : MnemoPkg(engine, parent) {
        handler.setPropertySafely("page1_i1", "fillingColor", mnemoConfig.getPropertyFromSettings(
                                                      MnemoConfig::Colors::GoodColorForIndicatorFilling));
    }
    
### Верстка и ее идеология
Все компоненты должны быть кратны некоторому MnemoConfigObj.minSizeScaled(MnemoConfigObj.minSizeScaledRounded).
Индикаторы уже сделаны таким образом. Для того, чтоб изменить их размер можно сделать следующее:

    Mnemo.Indicator {
        widthPartsCount: 40
        heightPartsCount: 20
    }
    
Для отрисовки линий оказалось очень удобно использовать слотовую систему на индикаторах.
Мы видим, что в последнем примере индикатор состоит из 40 минимальных размеров (MnemoConfigObj.minSizeScaledRounded) по горизонтали и 20 по вертикали.
У каждого индикатора есть функция, возвращающая глобальные значения координат. Каждая такая функция начинается со слова slot.
Чтоб получить глобальное значения x центра инликатора достаточно вызвать:

    i1.slotTopFromCenterX(0)
    
Отрицательные параметры будут смещать x на лево с шагом MnemoConfigObj.minSizeScaledRounded, положительные- направо.

Тогда простейшая линия между индикаторами может выглядеть следующим образом:

    import CPoint 1.0
    ...
    Mnemo.Line {
        objectName: makeObjectName("l1")
        points: [
            CPoint { x: i1.slotLeftFromCenterX(); y: i1.slotLeftFromCenterY(0) },
            CPoint { x: i2.slotRightFromCenterX(); y: i2.slotRightFromCenterY(0) }
        ]
    }
    
