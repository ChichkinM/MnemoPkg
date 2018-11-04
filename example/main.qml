import QtQuick 2.3
import QtQuick.Window 2.2

import "qrc:/Mnemo" as Mnemo
import CPoint 1.0


Window {
    id: root

    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    onWidthChanged: setScale()
    onHeightChanged: setScale()

    function setScale() {
        if (root.width < root.height)
            ConfigObj.setScale(root.width / 640)
        else
            ConfigObj.setScale(root.height / 480)
    }


    Mnemo.Indicator {
        id: i1
        x: 10
        y: 10
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
