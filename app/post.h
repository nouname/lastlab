#ifndef POST_H
#define POST_H

#include <QObject>
#include <QString>
#include <QVariant>

class Post : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString avaUrl READ getAva WRITE setAva NOTIFY avaChanged)
    Q_PROPERTY(QString title READ getTitle WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QString text READ getText WRITE setText NOTIFY textChanged)
    Q_PROPERTY(QList<QVariant> images READ getImages WRITE setImages NOTIFY imagesChanged)
    Q_PROPERTY(bool showThisPost)

public:
    Post(QObject *parent = nullptr);
    void setText(QString text);
    void setImages(QList<QVariant> images);
    void setAva(QString avaUrl);
    void setTitle(QString title);
    QString getAva();
    QString getTitle();
    QString getText();
    Q_INVOKABLE QList<QVariant> getImages();
    bool showThisPost = true;

private:
    QString text;
    QString avaUrl;
    QString title;
    QList<QVariant> images;

signals:
    void groupChanged();
    void textChanged();
    void imagesChanged();
    void avaChanged();
    void titleChanged();
};

#endif // POST_H
