import QtQuick 2.0
import "qrc:/Mnemo" as Mnemo

Mnemo.MnemoPage {
    id: root
    title: "Страница 2"
    objectName: "page2"
    onGoBack: goTo("qrc:/Page1.qml")
    defaultFoucusObjectName: i1.objectName

    Mnemo.Indicator {
        id: i1
        objectName: makeItemObjectName("i1")
        anchors.right: root.right
        anchors.rightMargin: ConfigObj.minSizeScaledRounded * 2
        y: headerY + ConfigObj.minSizeScaledRounded * 2
        KeyNavigation.down: i2
    }

    Mnemo.Indicator {
        id: i2
        objectName: makeItemObjectName("i2")
        anchors.left: i1.left
        anchors.top: i1.bottom
        anchors.topMargin: ConfigObj.minSizeScaledRounded * 2
        KeyNavigation.down: i3

        onGoInside: {
            saveFocus(root.objectName, objectName)
            goTo("qrc:/Page3.qml")
        }
    }

    Column {
        anchors.centerIn: root
        spacing: ConfigObj.minSizeScaledRounded

        Mnemo.Indicator {
            id: i3
            objectName: makeItemObjectName("i3")
            KeyNavigation.down: i4

        }

        Mnemo.Indicator {
            id: i4
            objectName: makeItemObjectName("i4")
            KeyNavigation.down: i5
        }

        Mnemo.Indicator {
            id: i5
            objectName: makeItemObjectName("i5")
        }
    }
}
