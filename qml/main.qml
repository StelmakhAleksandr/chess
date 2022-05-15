import QtQuick 2.15
import QtQuick.Controls 6.2

Window {
    width: 640
    height: 480
    visible: true
    id: wrapper
    title: qsTr("Hello World")

    Button {
        id: button
        x: 147
        y: 150
        text: qsTr("Hello World")
        onClicked: {
            App.changeLanguage("chess_uk_UA.qm")
        }
    }

}

