import QtQuick 2.0
import "qrc:/Mnemo" as Mnemo

Mnemo.MnemoPage {
    id: root
    title: "Страница 3"
    objectName: "page3"
    onGoBack: goTo("qrc:/Page2.qml")

    Repeater {
        id: repeater
        x: MnemoConfigObj.minSizeScaledRounded * 70
        y: headerY + MnemoConfigObj.minSizeScaledRounded * 2

        objectName: makeObjectName("repeater")
        model: [
            makeObjectName("i1"), makeObjectName("i2"),
            makeObjectName("i3"), makeObjectName("i4"),
            makeObjectName("i5"), makeObjectName("i6") ]
        focus: true

        Mnemo.Indicator {
            objectName: modelData
            x: repeater.x
            y: repeater.y + (height + MnemoConfigObj.minSizeScaledRounded * 2) * index
        }
    }
}
