#include "datareceiver.h"
#include "profileloader.h"
#include "vk.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

ProfileLoader::ProfileLoader(QObject *parent) : QObject (parent)
{

}

QString ProfileLoader::getUrl() const
{
    DataReceiver receiver;
    VK vk;
    receiver.setUrl("https://api.vk.com/method/users.get?fields=photo_200&access_token=" + vk.getTokenFromFile()->getValue() + "&v=5.92");
    QByteArray data = receiver.getData();
    QJsonObject root = QJsonDocument::fromJson(data).object();
    return root.value("response").toArray().at(0).toObject().value("photo_200").toString();
}
