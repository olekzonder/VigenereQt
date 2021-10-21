#ifndef VIGENERENCRYPT_H
#define VIGENERENCRYPT_H

#include <QObject>

class VigenerEncrypt
{
public:
    QString Encrypt( QString Alphabet, QString Input, QString Key);
    QString Decrypt( QString Alphabet, QString Input, QString Key);
};

#endif // VIGENERENCRYPT_H
