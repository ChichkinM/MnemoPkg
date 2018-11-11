import QtQuick 2.0
import MnemoConfigType 1.0

Text {
    font.pixelSize: MnemoConfigObj.minFontScaled * 1.5
    font.family: MnemoConfigObj.getPropertyFromSettings(MnemoConfigType.FamilyForLabel)
    font.bold: MnemoConfigObj.getPropertyFromSettings(MnemoConfigType.BoldForLabel)
    color: MnemoConfigObj.getPropertyFromSettings(MnemoConfigType.DefaultColorForLabel)
    text: "Текст"
}
