#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLocalServer>
#include <QLocalSocket>
#include <QMap>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected slots:
    void newConnection();
    void readyRead();
    void writeToAll(QString);
    void sendData();
private:
    Ui::MainWindow *ui;

    QLocalServer *m_localServer;
    QVector<QLocalSocket*> m_clientPtr;
};

#endif // MAINWINDOW_H
