#ifndef WEBVIEWINTERFACE_H
#define WEBVIEWINTERFACE_H

#include "globals.h"

class WebViewInterface : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString error READ getError WRITE setError NOTIFY errorChanged)

public:
    WebViewInterface(QObject *parent = nullptr);
    QString getError();
    void setError(QString error);

private:
    QString error = NO_ERR;

signals:
    void errorChanged();
};

#endif // WEBVIEWINTERFACE_H
