import QtQuick 2.0
import "qrc:/Mnemo" as Mnemo

Mnemo.MnemoPage {
    id: root
    title: "Страница 3"
    objectName: "page3"
    onGoBack: goTo("qrc:/Page2.qml")

    Repeater {
        id: repeater
        x: ConfigObj.minSizeScaledRounded * 70
        y: headerY + ConfigObj.minSizeScaledRounded * 2

        objectName: makeItemObjectName("repeater")
        model: [
            makeItemObjectName("i1"), makeItemObjectName("i2"),
            makeItemObjectName("i3"), makeItemObjectName("i4"),
            makeItemObjectName("i5"), makeItemObjectName("i6") ]
        focus: true

        Mnemo.Indicator {
            objectName: modelData
            x: repeater.x
            y: repeater.y + (height + ConfigObj.minSizeScaledRounded * 2) * index
        }
    }
}
