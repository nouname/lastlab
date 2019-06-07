import QtQuick 2.0
import QtQuick.Window 2.2
import QtWebEngine 1.8
import WebViewInterface 1.0
import VK 1.0
import Token 1.0

Window {
    property string at_err: "access denied"
    property string no_err: "no error"

    visible: true
    width: 640
    height: 480
    title: qsTr("Log In")

    WebViewInterface {
        id: web
    }

    VK {
        id: vk
    }

    Token {
        id: token
    }

    Loader { id: loader }

    WebEngineView {

        function param(url, name) {
            var query = url;
            var vars = query.split("&");
            for (var i = 0; i < vars.length; i++) {
                var pair = vars[i].split("=");
                if (pair[0] === name) {
                    console.log(pair[1]);
                    return pair[1];
                }
            }
        }
        property string appId: "6902140"
        anchors.fill: parent
        url: "https://oauth.vk.com/authorize?client_id=" + appId + "&display=popup&redirect_uri=https://oauth.vk.com/blank.html&scope=wall,friends&response_type=token&v=5.52"

        onUrlChanged: {
            web.error = (token.value = param(url.toString(), "https://oauth.vk.com/blank.html#access_token")) ? no_err : at_err
            if (token.value) {
                vk.token = token
                vk.saveToken();
            } else {
                vk.logout(window)
                url = "https://oauth.vk.com/authorize?client_id=" + appId + "&display=popup&redirect_uri=https://oauth.vk.com/blank.html&scope=wall,friends&response_type=token&v=5.52";
            }

            console.log(web.error)
            loader.source = "newsfeed.qml"
            hide();
        }
    }
}

