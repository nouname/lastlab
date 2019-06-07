#include "webviewinterface.h"
#include "vk.h"
#include "globals.h"
#include <QEventLoop>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkReply>

WebViewInterface::WebViewInterface(QObject *parent) : QObject(parent) {
    this->setParent(parent);
}

void WebViewInterface::setError(QString error) {
    this->error = error;
}

QString WebViewInterface::getError() {
    return error;
}
