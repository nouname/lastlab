#ifndef POSTLOADER_H
#define POSTLOADER_H

#include "loadthread.h"

class PostLoader : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Post* data READ getData WRITE setData NOTIFY dataChanged)

public:
    PostLoader(QObject *parent = nullptr);
    void setData(Post *post);
    Post* getData();
    void getPosts(int offset);
    void timeout(int ms);
    LoadThread* thread;

private:
     Post* data;

private slots:
    void loaded(QString title, QString avaUrl, QString text, QList<QVariant>, bool showThisPost);
    void loadMore();

signals:
    void dataChanged();
    void idChanged();
    void done();
};

#endif // POSTLOADER_H
