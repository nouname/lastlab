#ifndef TOKEN_H
#define TOKEN_H

#include <QObject>
#include <QString>

class Token : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString value READ getValue WRITE setValue NOTIFY valueChanged)

public:
    Token(QObject* parent = nullptr);
    QString getValue();
    void setValue(QString value);
    bool isEmpty();

private:
    QString value;

signals:
    void valueChanged();
};

#endif // TOKEN_H
