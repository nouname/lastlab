#include "token.h"

Token::Token(QObject* parent) : QObject (parent)
{

}

QString Token::getValue() {
    return this->value;
}

void Token::setValue(QString value) {
    this->value = value;
}

bool Token::isEmpty() {
    return this->getValue().isEmpty();
}
