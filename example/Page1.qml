import QtQuick 2.0
import "qrc:/Mnemo" as Mnemo
import CPoint 1.0

Mnemo.MnemoPage {
    id: root
    title: "Страница 1"
    objectName: "page1"
    defaultFoucusObjectName: i1.objectName

    Mnemo.Indicator {
        id: i1
        objectName: makeItemObjectName("i1")
        x: ConfigObj.minSizeScaledRounded * 2
        y: headerY + ConfigObj.minSizeScaledRounded * 2

        KeyNavigation.down: i2
    }

    Mnemo.Indicator {
        id: i2
        objectName: makeItemObjectName("i2")
        anchors.left: i1.left
        anchors.top: i1.bottom
        anchors.topMargin: ConfigObj.minSizeScaledRounded * 2

        onGoInside: {
            saveFocus(root.objectName, objectName)
            goTo("qrc:/Page2.qml")
        }
    }

    Mnemo.Line {
        points: [
            CPoint { x: i1.slotRightFromCenterX(); y: i1.slotRightFromCenterY(0) },
            CPoint { x: i1.slotRightFromCenterX() + ConfigObj.minSizeScaledRounded * 8;
                y: i1.slotRightFromCenterY(0) },
            CPoint { x: i1.slotRightFromCenterX() + ConfigObj.minSizeScaledRounded * 8;
                y: i1.slotRightFromCenterY(0) + ConfigObj.minSizeScaledRounded * 8 }
        ]
    }
}
