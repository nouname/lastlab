import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.5
import QtQuick.Controls.Styles 1.4
import QtGraphicalEffects 1.12
import QtWebEngine 1.8
import PostLoader 1.0
import ProfileLoader 1.0
import Post 1.0
import VK 1.0

ApplicationWindow {
    color: "#d7dfed"
    visible: true
    width: 1340
    minimumWidth: 1340
    height: 780
    minimumHeight: 780
    id: window
    title: qsTr("News")

    ProfileLoader {
        id: profileLoader
    }

    VK {
        id: vk
    }

    onClosing: {
        vk.quit()
        visibile: false
    }

    Rectangle {
        id: profile
        color: "white"
        x: 10
        y: 10
        width: 220
        height: 290
        Image {
            width: 200
            height: 200
            x: 10
            y: 10
            source: profileLoader.getUrl()
        }
        Button {
            x: 10
            y: 220
            width: 200
            height: 60
            id: logout
            background: Rectangle {
                color: logout.hovered ? "#29536d": "#4c75a3"
            }
            text: "<font color='white'>Log Out</font>"
            onClicked: {
                vk.logout(window)
            }
        }
    }



    DropShadow {
        anchors.fill: profile
        horizontalOffset: 0
        verticalOffset: 1
        radius: 8.0
        samples: 17
        color: "#c4c4c4"
        source: profile
    }

    ListModel {
        id: listModel
    }

    function element(title, avaUrl, text, images) {
        var str = ""
        for (var i = 0; i < images.length; i++) {
            str += images[i] + "&";
        }
        return {
            title: title,
            avaUrl: avaUrl,
            txt: text,
            images: str
        };
    }

    Post {
        id: postData
    }

    PostLoader {
        id: loader

        onDataChanged: {
            if (data.text && data.title && data.avaUrl)
                listModel.append((element(data.title, data.avaUrl, data.text, data.images)));
        }
    }
    Rectangle {
        color: "#c7d4e0"
        width: 780
        x: (window.width - width) / 2
        height: window.height
        ListView {
            spacing: 10
            clip: true
            model: listModel
            highlightFollowsCurrentItem: false
            anchors.fill: parent
            id: list
            topMargin: 20
            bottomMargin: 20
            leftMargin: 20
            rightMargin: 20
            focus: true
            flickableDirection: Flickable.VerticalFlick
            boundsBehavior: Flickable.StopAtBounds
            cacheBuffer: 1000
            preferredHighlightBegin: 0

            MouseArea {
                anchors.fill: parent
                acceptedButtons: Qt.NoButton
            }

            ScrollBar.vertical: ScrollBar {
                id: scrollBar
                smooth: true
                active: pressed || list.moving
                orientation: Qt.Vertical

                contentItem: Rectangle {
                    implicitWidth: 4
                    radius: 2
                    implicitHeight: parent.height
                    color: "#747a84"
                }
            }

            delegate: Item {
                x: (760 - width) / 2
                visible: true
                anchors.left: parent.left
                anchors.right: parent.right

                anchors.margins: 10

                height: i.height + t.height + c2.height + 40
                Rectangle {
                    id: rect
                    color: "white"
                    height: i.height + t.height + c2.height + 40
                    width: 720

                    Column {
                        x: (720 - width) / 2
                        id: c1
                        spacing: 10
                        y: 10
                        Row {
                            anchors.margins: 10
                            spacing: 10
                            Image {
                                id: i
                                source: avaUrl
                            }
                            Text {
                                font.bold: true
                                text: title
                                y: (parent.height - height) / 2;
                                wrapMode: Text.WordWrap
                            }
                        }
                        Row {
                            Text {
                                anchors.margins: 10
                                id: t
                                width: 700
                                text: txt
                                wrapMode: Text.WordWrap
                            }
                        }
                        Column {
                            width: 700
                            clip: true
                            id: c2
                            spacing: 10
                            Repeater {
                                id: repeater
                                clip: true
                                width: 700
                                model: images.split("&")
                                Image {
                                    clip: true
                                    id: image
                                    source: modelData.split("*")[0]
                                    width: 700
                                    height: modelData.split("*")[1]
                                    fillMode: Image.PreserveAspectFit
                                }
                            }
                        }
                    }
                }
                DropShadow {
                    anchors.fill: rect
                    horizontalOffset: 0
                    verticalOffset: 1
                    radius: 8.0
                    samples: 17
                    color: "#c4c4c4"
                    source: rect
                }
            }
        }
    }
}

