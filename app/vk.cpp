#include "vk.h"
#include "globals.h"
#include "datareceiver.h"
#include <QFile>
#include <QException>
#include <QNetworkAccessManager>
#include <QDir>
#include <QEventLoop>
#include <QTimer>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonDocument>
#include <QStandardPaths>
#include <QWebEngineCookieStore>
#include <QWebEngineProfile>

VK::VK(QObject *parent) :
    QObject (parent)
{

}

void VK::quit() {
    emit done();
}

bool VK::logout(QWindow *window) {
    quit();
    bool result = true;
    QStringList paths = QStandardPaths::standardLocations(QStandardPaths::DataLocation);
    for (int i = 0; i < paths.size(); i++) {
        QDir dir(paths.at(i) + "/QtWebEngine");
        if (dir.isReadable())
            dir.removeRecursively();

        result *= dir.isEmpty();
    }
    QFile file("data");
    file.remove();
    window->close();
    return result && !file.exists();
}

void VK::setToken(Token* token) {
    this->token = token;
}

Token* VK::getToken() {
    return this->token;
}

QString VK::checkAccess(Token *token) {
    token = getTokenFromFile();
    if (token && !token->isEmpty()) {
        DataReceiver receiver(nullptr);
        receiver.setUrl("https://api.vk.com/method/users.get?access_token=" + token->getValue() + "&v=5.92");
        QByteArray data = receiver.getData();
        QJsonObject root = QJsonDocument::fromJson(data).object();
        qDebug() << data;
        return !root.value("error").isUndefined() ? AT_ERR : NO_ERR;

    } else
        return DATA_FILE_ERR;
}

Token* VK::getTokenFromFile() {
    QFile data("data");
    data.open(QFile::ReadOnly);
    if (!data.isOpen())
        return nullptr;
    Token *token = new Token();
    token->setValue(data.readAll());
    data.close();
    return token;
}

void VK::saveToken() {
    QString string = getToken()->getValue();
    QFile data("data");
    data.open(QFile::WriteOnly);
    if(data.isOpen())
       data.write(string.toStdString().c_str());
    data.close();
}
