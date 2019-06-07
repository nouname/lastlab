#ifndef VK_H
#define VK_H

#include <QString>
#include <QObject>
#include <QWindow>
#include "token.h"
#include "webviewinterface.h"

class VK : public QObject
{
    Q_OBJECT
public:
    Q_PROPERTY(Token* token READ getToken WRITE setToken NOTIFY tokenChanged)
    Q_INVOKABLE void saveToken();
    Q_INVOKABLE QString checkAccess(Token *token);
    Q_INVOKABLE Token* getTokenFromFile();
    Q_INVOKABLE bool logout(QWindow *window);
    Q_INVOKABLE void quit();

    VK(QObject* parent = nullptr);
    Token* getToken();
    void setToken(Token *token);

private:
    Token* token;
    bool isError(QByteArray data);

signals:
    void tokenChanged();
    void done();
};

#endif // VK_H
