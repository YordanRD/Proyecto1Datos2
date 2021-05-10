#ifndef LOCALSERVER_H
#define LOCALSERVER_H

#include <QObject>
#include <QLocalServer>

class QLocalSocket;

class LocalServer : public QLocalServer
{
public:
    explicit LocalServer(QObject *parent = nullptr);
    void send(const QString &msj);
private:
    QLocalSocket *mSocket;
};

#endif // LOCALSERVER_H
