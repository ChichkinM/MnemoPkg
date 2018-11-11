import QtQuick 2.0
import ConfigType 1.0

Rectangle {
    id: root
    color: ConfigObj.getPropertyFromSettings(ConfigType.Background)

    property string mainPageSource

    property int defaultWidthForScale
    property int defaultHeightForScale

    onWidthChanged: setScale()
    onHeightChanged: setScale()
    function setScale() {
        if (defaultWidthForScale > 0 && defaultHeightForScale > 0) {
            if (root.width < root.height)
                ConfigObj.setScale(root.width / defaultWidthForScale)
            else
                ConfigObj.setScale(root.height / defaultHeightForScale)
        }
    }


    Loader {
        id: pageLoader

        width: Math.round(root.width)
        height: Math.round(root.height)
        focus: true

        property string mainPageSource: root.mainPageSource
        source: root.mainPageSource
    }

    Connections { target: pageLoader.item; onGoTo: {
            pageLoader.source = destinationPageSource
        }
    }
}
