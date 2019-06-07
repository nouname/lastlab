#ifndef DATARECEIVER_H
#define DATARECEIVER_H

#include <QObject>

class DataReceiver : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString url READ getUrl WRITE setUrl NOTIFY urlChanged)

public:
    DataReceiver(QObject *parent = nullptr);
    QByteArray getData();
    void setUrl(QString url);
    QString getUrl();

private:
    QString url;

signals:
    void urlChanged();
};


#endif // DATARECEIVER_H
