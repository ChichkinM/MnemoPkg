import QtQuick 2.0
import "./Base"
import ConfigType 1.0

BaseIndicator {
    id: root

    Text {
        text: root.text
        anchors.centerIn: parent
        color: root.textColor
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: root.fontSize
        font.bold: root.fontBold
        font.family: "Arial"
        z: 1
    }

    Rectangle {
        anchors.fill: root
        color: "transparent"
        border.color: root.borderColor
        border.width: 2 * ConfigObj.scale
        radius: 5 * ConfigObj.scale
    }

    Rectangle {
        width: Math.round(root.width - ConfigObj.minSizeScaled * 2)
        height: Math.round(root.height - ConfigObj.minSizeScaled * 2)
        anchors.centerIn: root
        color: root.fillingColor
        radius: 5 * ConfigObj.scale
    }
}
