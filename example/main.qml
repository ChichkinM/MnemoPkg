import QtQuick 2.3
import QtQuick.Window 2.2
import "qrc:/Mnemo" as Mnemo


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
        x: 10
        y: 10
    }
}
