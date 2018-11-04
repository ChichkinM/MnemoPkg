import QtQuick 2.0
import "./Base"
import ConfigType 1.0

BaseIndicator {
    id: root

    Rectangle {
        anchors.fill: root
        color: "transparent"
        border.color: ConfigObj.getPropertyFromSettings(ConfigType.DefaultColorForIndicatorBorder)
        border.width: 2 * ConfigObj.scale
        radius: 5 * ConfigObj.scale
    }

    Rectangle {
        width: Math.round(root.width - ConfigObj.minSizeScaled * 2)
        height: Math.round(root.height - ConfigObj.minSizeScaled * 2)
        anchors.centerIn: root
        color: "lightgray"
        radius: 5 * ConfigObj.scale
    }
}
