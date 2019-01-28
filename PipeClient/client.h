#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QLocalSocket>

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = nullptr);

signals:

public slots:

protected slots:
    void connected();
    void readyRead();
private:
    QLocalSocket *m_socket;
};

#endif // CLIENT_H
