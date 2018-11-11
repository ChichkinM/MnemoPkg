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
        objectName: makeObjectName("i1")
        x: MnemoConfigObj.minSizeScaledRounded * 2
        y: headerY + MnemoConfigObj.minSizeScaledRounded * 2

        KeyNavigation.down: i2
    }

    Mnemo.Indicator {
        id: i2
        objectName: makeObjectName("i2")
        text: "Страница 2"

        anchors.left: i1.left
        anchors.top: i1.bottom
        anchors.topMargin: MnemoConfigObj.minSizeScaledRounded * 2

        onGoInside: {
            MnemoHelper.saveItemWithFocus(root.objectName, objectName)
            goTo("qrc:/Page2.qml")
        }
    }

    Mnemo.Line {
        objectName: makeObjectName("l1")
        points: [
            CPoint { x: i1.slotRightFromCenterX(); y: i1.slotRightFromCenterY(0) },
            CPoint { x: i1.slotRightFromCenterX() + MnemoConfigObj.minSizeScaledRounded * 8;
                y: i1.slotRightFromCenterY(0) },
            CPoint { x: i1.slotRightFromCenterX() + MnemoConfigObj.minSizeScaledRounded * 8;
                y: i2.slotRightFromCenterY(0) },
            CPoint { x: i2.slotRightFromCenterX(); y: i2.slotRightFromCenterY(0) }
        ]
    }
}
