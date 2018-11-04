import QtQuick 2.0

MouseArea {
    id: root

    //для симметрии должны быть четными
    property int widthPartsCount: 20
    property int heightPartsCount: 10

    width: Math.round(widthPartsCount * ConfigObj.minSizeScaled)
    height: Math.round(heightPartsCount * ConfigObj.minSizeScaled)

    property string text: "Модуль"
//    property string img: Config.indicatorImgOrangeDotted()
    property string color: /*Config.textColorWhite()*/"black"

    property string fontSize: /*Config.fontMediumWithScale*/"12"
    property bool fontBold: true

    //необходимо для высчитывания абсолютных координат
    property var parents: [parent, parent.parent]

    signal goInside()


    function objIsExist(obj) {
        if (obj === null || obj === undefined)
            return false
        return true
    }


    function getParentAdditionX() {
        var parentsAddition = 0
        root.parents.forEach(function(oneParent) {
            if (objIsExist(oneParent))
                parentsAddition += oneParent.x
        })
        return parentsAddition
    }

    function getParentAdditionY() {
        var parentsAddition = 0
        root.parents.forEach(function(oneParent) {
            if (objIsExist(oneParent))
                parentsAddition += oneParent.y
        })
        return parentsAddition
    }




    function slotLeftFromCenterX() {
        return Math.round( getParentAdditionX() +
                          root.x )
    }
    function slotLeftFromCenterY(slotNumber) {
        return Math.round( getParentAdditionY() +
                          root.y + root.partOfSize * (root.heightPartsCount / 2) + root.partOfSize * slotNumber )
    }

    function slotRightFromCenterX() {
        return Math.round( getParentAdditionX() +
                          root.x + root.width )
    }
    function slotRightFromCenterY(slotNumber) {
        return slotLeftFromCenterY(slotNumber)
    }

    function slotBottomFromCenterX(slotNumber) {
        return Math.round( getParentAdditionX() +
                          root.x + root.partOfSize * (root.widthPartsCount / 2) + root.partOfSize * slotNumber )
    }
    function slotBottomFromCenterY() {
        return Math.round( getParentAdditionY() +
                          root.y + root.height )
    }

    function slotTopFromCenterX(slotNumber) {
        return slotBottomFromCenterX(slotNumber)
    }
    function slotTopFromCenterY() {
        return Math.round( getParentAdditionY() +
                          root.y )
    }

    Keys.onPressed: {
        if ((event.key === Qt.Key_Enter || event.key === Qt.Key_Return) && goInside !== undefined)
            goInside()
    }
    onClicked: goInside()

    hoverEnabled: true
    onEntered: if (KeyNavigation.right !== null || KeyNavigation.left !== null ||
                       KeyNavigation.up !== null || KeyNavigation.down !== null)
                   focus = true

    Text {
        text: root.text
        anchors.centerIn: parent
        color: root.color
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: root.fontSize
        font.bold: root.fontBold
        font.family: "Arial"
        z: 1

        rotation: -root.rotation
    }

    Rectangle {
        width: 20 * ConfigObj.scale
        height: width
        radius: width / 2
        color: "red"
        visible: root.focus
        Component.onCompleted: if (focus == true) console.log( objectName )
    }
}
