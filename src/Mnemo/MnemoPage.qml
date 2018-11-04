import QtQuick 2.0

Item {
    id: root

    property bool showHeader: true

    signal goTo(string destinationPageSource)

    focus: true
    Keys.onEscapePressed: toGeneral()
    Keys.onPressed: if (event.key === Qt.Key_Backspace) goBack()

//    Connections { target: ConfigObj; onSetColorForRepeaterChild: {
//            for (var i = 0; ; i++) {
//                var item = repeaterObj.itemAt(i)
//                if (item !== null && item.objectName === childObjName) {
//                    item.color = value
//                    return
//                }
//                else if (item === null)
//                    return
//            }
//        }
//    }

//    Item {
//        id: headerBtn

//        anchors.right: root.right
//        anchors.rightMargin: Config.marginX1ScaledRounded
//        width: backImg.width
//        height: backImg.height

//        z: 5
//        visible: root.showHeader


//        MouseArea {
//            anchors.left: backImg.left
//            anchors.top: backImg.top

//            width: backImg.width * 0.35
//            height: backImg.height

//            onClicked: goBack()
//        }

//        MouseArea {
//            anchors.right: backImg.right
//            anchors.top: backImg.top

//            width: backImg.width * 0.65
//            height: backImg.height

//            onClicked: toGeneral()
//        }
//    }
}
