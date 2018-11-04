import QtQuick 2.0

Item {
    id: root

    property string mainPageSource

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
