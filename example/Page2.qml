import QtQuick 2.0
import "qrc:/Mnemo" as Mnemo

Mnemo.MnemoPage {
    onGoBack: goTo("qrc:/Page1.qml")
}
