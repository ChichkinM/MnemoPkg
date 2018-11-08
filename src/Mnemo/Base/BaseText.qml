import QtQuick 2.0
import ConfigType 1.0

Text {
    font.pixelSize: /*Config.fontVerySmallWithScale*/12
    font.family: "Sans"
    color: ConfigObj.getPropertyFromSettings(ConfigType.DefaultColorForLabel)
    text: "Текст"
}
