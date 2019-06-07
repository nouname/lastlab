#include "loadthread.h"
#include "postloader.h"
#include "profileloader.h"
#include "vk.h"
#include <QtWebEngine>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QWebEnginePage>
#include <QWebEngineProfile>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QtWebEngine::initialize();

    qmlRegisterType<WebViewInterface>("WebViewInterface", 1, 0, "WebViewInterface");
    qmlRegisterType<VK>("VK", 1, 0, "VK");
    qmlRegisterType<Token>("Token", 1, 0, "Token");
    qmlRegisterType<Post>("Post", 1, 0, "Post");

    qmlRegisterType<PostLoader>("PostLoader", 1, 0, "PostLoader");
    qmlRegisterType<ProfileLoader>("ProfileLoader", 1, 0, "ProfileLoader");

    QQmlApplicationEngine engine;

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
