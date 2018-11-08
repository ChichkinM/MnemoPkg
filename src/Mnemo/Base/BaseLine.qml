import QtQuick 2.0
import CLine 1.0
import ConfigType 1.0

CLine {
    id: root

    z: -1
    color: ConfigObj.getPropertyFromSettings(ConfigType.DefaultColorForLine)
    radius: /*Config.radiusMedium*/5
    penWidth: /*Math.round(2 * Config.scale)*/2
}
