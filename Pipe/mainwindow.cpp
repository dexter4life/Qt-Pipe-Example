#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), m_localServer(new QLocalServer(this))
{
    ui->setupUi(this);

    if(!m_localServer->listen("\\\\.\\pipe\\qt_socket_test"))
    {
        QMessageBox::information(this, "error", "Something happened",QMessageBox::Ok);
        return;
    }
    connect(m_localServer, &QLocalServer::newConnection, this, &MainWindow::newConnection);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(sendData()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readyRead()
{

}
void MainWindow::newConnection()
{
    QLocalSocket  *newSocket = m_localServer->nextPendingConnection();
    connect(newSocket,SIGNAL(readyRead()), SLOT(readyRead()));

    m_clientPtr.push_back(newSocket);

    newSocket->write("Welcome to LocalSocket");
}

void MainWindow::writeToAll(QString data)
{
    foreach(QLocalSocket *socket, m_clientPtr){
        socket->write(data.toUtf8());
    }
}

void MainWindow::sendData()
{
   writeToAll(ui->textEdit->toPlainText());
}
