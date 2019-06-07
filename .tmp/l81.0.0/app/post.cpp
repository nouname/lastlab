#include "post.h"

Post::Post(QObject* parent) :
    QObject (parent)
{

}

void Post::setText(QString text)
{
    this->text = text;
}

void Post::setImages(QList<QVariant> images)
{
    this->images = images;
}

void Post::setAva(QString avaUrl)
{
    this->avaUrl = avaUrl;
}

void Post::setTitle(QString title)
{
    this->title = title;
}

QString Post::getAva()
{
    return avaUrl;
}

QString Post::getTitle()
{
    return title;
}

QString Post::getText()
{
    return text;
}

QList<QVariant> Post::getImages()
{
    return images;
}
