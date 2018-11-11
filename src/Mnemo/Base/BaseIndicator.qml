import QtQuick 2.0
import ConfigType 1.0

MouseArea {
    id: root

    //для симметрии должны быть четными
    property int widthPartsCount: 20
    property int heightPartsCount: 10

    width: Math.round(widthPartsCount * ConfigObj.minSizeScaled)
    height: Math.round(heightPartsCount * ConfigObj.minSizeScaled)

    property string text: "Модуль"
    property string textColor:
        ConfigObj.getPropertyFromSettings(ConfigType.DefaultColorForIndicatorText)
    property string borderColor:
        ConfigObj.getPropertyFromSettings(ConfigType.DefaultColorForIndicatorBorder)
    property string fillingColor:
        ConfigObj.getPropertyFromSettings(ConfigType.DefaultColorForIndicatorFilling)

    property string fontSize: ConfigObj.minFontScaled * 2
    property bool fontBold: ConfigObj.getPropertyFromSettings(ConfigType.BoldForIndicatorText)
    property string fontFamily: ConfigObj.getPropertyFromSettings(ConfigType.FamilyForIndicatorText)

    //необходимо для высчитывания абсолютных координат
    property var parents: [parent, parent.parent]

    signal goInside()

    onFocusChanged: {
        if (focus)
            MnemoHelper.saveItemWithFocus(pageObjectName, objectName)
    }


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
    function
    slotLeftFromCenterY(slotNumber) {
        return Math.round( getParentAdditionY() +
                          root.y + ConfigObj.minSizeScaled * (root.heightPartsCount / 2) + ConfigObj.minSizeScaled * slotNumber )
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
                          root.x + ConfigObj.minSizeScaled * (root.widthPartsCount / 2) + ConfigObj.minSizeScaled * slotNumber )
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


    Rectangle {
        width: 10 * ConfigObj.scale
        height: width
        radius: width / 2
        anchors.horizontalCenter: root.horizontalCenter
        anchors.bottom: root.top
        anchors.bottomMargin: - width / 2
        color: ConfigObj.getPropertyFromSettings(ConfigType.DefaultColorForIndicatorBorder)
        visible: root.focus
        z: 2
        Component.onCompleted: ConfigObj.getPropertyFromSettings(ConfigType.DefaultColorForIndicatorBorder)
    }
}
