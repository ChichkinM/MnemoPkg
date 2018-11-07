import QtQuick 2.0

Item {
    id: root

    property string mainPageSource

    Loader {
        id: pageLoader

        width: Math.round(root.width)
        height: Math.round(root.height)
        focus: true

        property var elementWithFocus: []
        property var pageForElementWithFocus: []

        property string mainPageSource: root.mainPageSource
        source: root.mainPageSource

        function saveFocus(pageObjectName, itemObjectName) {
            for (var i = 0; i < pageForElementWithFocus.length; i++)
                if (pageForElementWithFocus[i] === pageObjectName) {
                    elementWithFocus[i] = itemObjectName
                    return
                }

            pageForElementWithFocus.push(pageObjectName)
            elementWithFocus.push(itemObjectName)
        }

        function getFocus(pageObjectName) {
            for (var i = 0; i < pageForElementWithFocus.length; i++)
                if (pageForElementWithFocus[i] === pageObjectName)
                    return elementWithFocus[i]
            return undefined
        }

        function trySetDefaultFocus(pageObjectName, itemObjectName) {
            for (var i = 0; i < pageForElementWithFocus.length; i++)
                if (pageForElementWithFocus[i] === pageObjectName)
                    return

            pageForElementWithFocus.push(pageObjectName)
            elementWithFocus.push(itemObjectName)
        }
    }

    Connections { target: pageLoader.item; onGoTo: {
            pageLoader.source = destinationPageSource
        }
    }
}
