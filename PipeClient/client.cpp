#include "client.h"

Client::Client(QObject *parent) : QObject(parent),
    m_socket(new QLocalSocket(this))
{
    m_socket->connectToServer("\\\\.\\pipe\\qt_socket_test");
    connect(m_socket,SIGNAL(connected()),this,SLOT(connected()));
    connect(m_socket,SIGNAL(readyRead()),this,SLOT(readyRead()));

}

void Client::connected(){
    qDebug()<<"Connected Successfully \n Waiting for data Transmission";

}

void Client::readyRead()
{
    QLocalSocket *socket = qobject_cast<QLocalSocket*>(sender());

    qDebug()<<"called";
    //while(socket->waitForReadyRead());

    qDebug()<<socket->readAll();
}
