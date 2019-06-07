import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.5
import QtQuick.Controls.Styles 1.4
import VK 1.0

Window {
    property string at_err: "access denied"
    property string no_err: "no error"

    visible: true
    width: 400
    height: 300
    id: window
    title: qsTr("Log In")

    VK {
        id: vk
    }

    Loader { id: loader }

    Button {
        id: login
        background: Rectangle {
            color: login.hovered ? "#29536d": "#4c75a3"
        }
        width : 200
        height: 60
        text: "<font color='white'>Log In</font>"
        anchors.centerIn: parent
        onClicked: {
            if (vk.checkAccess(vk.getTokenFromFile()) === no_err) {
                loader.source = "newsfeed.qml"
            } else {
                loader.source = "form.qml"
            }
            window.hide()
        }
    }
}
