import QtQuick 2.0
import ConfigType 1.0

Text {
    font.pixelSize: ConfigObj.minFontScaled * 1.5
    font.family: ConfigObj.getPropertyFromSettings(ConfigType.FamilyForLabel)
    font.bold: ConfigObj.getPropertyFromSettings(ConfigType.BoldForLabel)
    color: ConfigObj.getPropertyFromSettings(ConfigType.DefaultColorForLabel)
    text: "Текст"
}
