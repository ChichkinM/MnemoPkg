import QtQuick 2.0
import CLine 1.0
import MnemoConfigType 1.0

CLine {
    id: root

    z: -1
    color: MnemoConfigObj.getPropertyFromSettings(MnemoConfigType.DefaultColorForLine)
    radius: MnemoConfigObj.lineRadiusScaledRounded
    penWidth: MnemoConfigObj.lineWidthScaledRounded
}
