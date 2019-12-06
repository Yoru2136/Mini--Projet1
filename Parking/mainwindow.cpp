#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPort>

QSerialPort serial;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    serial.setPortName("COM3");
    serial.setBaudRate(QSerialPort::Baud19200);
    serial.setDataBits(QSerialPort::Data8);                         //paramètres du port série
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setFlowControl(QSerialPort::NoFlowControl);
}

MainWindow::~MainWindow()
{
//    delete ui;
//    serial.close();
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->radioButton->isChecked())
    {
        QByteArray Rouge("\x15\x7B\x1A\xAA");       //allume en rouge le 15 7B
        serial.write(Rouge);
    }
    if(ui->radioButton_2->isChecked())
    {
        QByteArray Vert("\x15\x7B\x19\xA9");    //allume en vert 
        serial.write(Vert);
    }
    if(ui->radioButton_3->isChecked())
    {
        QByteArray Orange("\x15\x7B\x1B\xAB");  //allume en orange
        serial.write(Orange);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    serial.open(QIODevice::ReadWrite);  //ouverture du port
}

void MainWindow::on_pushButton_3_clicked()
{
    serial.close();     //fermeture du port
}
