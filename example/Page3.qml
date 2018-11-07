import QtQuick 2.0
import "qrc:/Mnemo" as Mnemo

Mnemo.MnemoPage {
    id: root
    title: "Страница 3"
    onGoBack: goTo("qrc:/Page2.qml")
}
