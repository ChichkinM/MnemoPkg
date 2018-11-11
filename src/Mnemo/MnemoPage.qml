import QtQuick 2.0

Item {
    id: root

    property string pageObjectName: objectName
    property bool showBackBtn: true
    property bool showHomeBtn: true
    property bool showPageTitle: true
    property string title: "Страница мнемосхемы"
    property int headerY: backBtn.y + backBtn.height
    property string defaultFoucusObjectName

    signal goTo(string destinationPageSource)
    signal goBack()
    function goToGeneral() {
        goTo(mainPageSource)
    }

    function makeItemObjectName(itemName) {
        return root.objectName + "_" + itemName
    }

    Component.onCompleted: {
        if (defaultFoucusObjectName !== "")
            MnemoHelper.trySetDefaultItemWithFocus(objectName, defaultFoucusObjectName)

        var itemWithFocus = MnemoHelper.getItemWithFocus(objectName)
        if (itemWithFocus !== undefined && itemWithFocus !== null && itemWithFocus !== "")
            MnemoHelper.findChild(root, itemWithFocus).forceActiveFocus()
    }

    Connections { target: MnemoHelper; onSetPropertyForNestedItem: {
            for (var i = 0; i < repeaterObj.count; i++) {
                var item = repeaterObj.itemAt(i)
                if (item !== null && item.objectName === childObjName) {
                    MnemoHelper.setProperty(item, propertyName, value)
                    break
                }
            }
        }
    }

    focus: true
    Keys.onEscapePressed: goToGeneral()
    Keys.onPressed: if (event.key === Qt.Key_Backspace) goBack()

    Label {
        id: backBtn
        anchors.top: root.top
        anchors.left: root.left
        anchors.leftMargin: ConfigObj.minSizeScaled * 2
        text: "Назад"
        visible: root.showBackBtn

        MouseArea {
            anchors.fill: backBtn
            onClicked: goBack()
        }
    }

    Label {
        id: homeBtn
        anchors.top: backBtn.top
        anchors.left: backBtn.right
        anchors.leftMargin: ConfigObj.minSizeScaled * 2
        text: "Домой"
        visible: root.showHomeBtn

        MouseArea {
            anchors.fill: homeBtn
            onClicked: goToGeneral()
        }
    }

    Label {
        anchors.top: backBtn.top
        anchors.horizontalCenter: root.horizontalCenter
        anchors.rightMargin: ConfigObj.minSizeScaled * 2
        text: root.title
        visible: root.showPageTitle
    }
}
