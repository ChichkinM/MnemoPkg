import QtQuick 2.0
import "qrc:/Mnemo" as Mnemo
import CPoint 1.0

Mnemo.MnemoPage {
    Mnemo.Indicator {
        id: i1
        x: 10
        y: 10

        onGoInside: goTo("qrc:/Page2.qml")
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
