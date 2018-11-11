import QtQuick 2.0
import "./Base"
import MnemoConfigType 1.0

BaseIndicator {
    id: root

    Label {
        text: root.text
        anchors.centerIn: parent
        color: root.textColor
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: root.fontSize
        font.bold: root.fontBold
        font.family: root.fontFamily
        z: 1
    }

    Rectangle {
        anchors.fill: root
        color: "transparent"
        border.color: root.borderColor
        border.width: 2 * MnemoConfigObj.scale
        radius: MnemoConfigObj.indicatorBorderRadiusScaledRounded
    }

    Rectangle {
        width: Math.round(root.width - MnemoConfigObj.minSizeScaled * 2)
        height: Math.round(root.height - MnemoConfigObj.minSizeScaled * 2)
        anchors.centerIn: root
        color: root.fillingColor
        radius: MnemoConfigObj.indicatorFillingRadiusScaledRounded
    }
}
