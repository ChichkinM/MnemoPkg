import QtQuick 2.3
import QtQuick.Window 2.2

import "qrc:/Mnemo" as Mnemo


Window {
    id: root

    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Mnemo.Main {
        anchors.fill: parent
        defaultWidthForScale: 640
        defaultHeightForScale: 480

        mainPageSource: "qrc:/Page1.qml"
    }
}
