#ifndef PROFILELOADER_H
#define PROFILELOADER_H

#include <QObject>

class ProfileLoader: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString url)

public:
    Q_INVOKABLE QString getUrl() const;
    ProfileLoader(QObject *parent = nullptr);

private:
     QString url;

signals:
    void urlChanged();
};

#endif // PROFILELOADER_H
