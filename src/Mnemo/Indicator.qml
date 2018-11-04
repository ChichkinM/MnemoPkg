import QtQuick 2.0
import "./Base"

BaseIndicator {
    id: root

    Rectangle {
        anchors.fill: root
        color: "transparent"
        border.color: "steelblue"
        border.width: 2 * Config.scale
        radius: 5 * Config.scale
    }

    Rectangle {
        width: root.width - Config.minSize * 2
        height: root.height - Config.minSize * 2
        anchors.centerIn: root
        color: "lightgray"
        radius: 5 * Config.scale
    }
}
