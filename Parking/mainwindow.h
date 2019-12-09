#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtSerialPort/QSerialPort>
#include <QMessageBox>
#include <QDebug>
#include <QTimer>


#include <QMainWindow>
#include <QSerialPort>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();   //bouton envoyer

    void on_pushButton_2_clicked();     //bouton open

    void on_pushButton_3_clicked();     //bouton close
    void lectureDonnees();


    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;     //interface utilisateur
    QSerialPort *serial;
    QTimer *timer;
    QByteArray lire;

private:
    Ui::MainWindow *ui;     //interface utilisateur
    QSerialPort *port;


};

#endif // MAINWINDOW_H
