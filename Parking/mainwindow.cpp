#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPort>
#include <QMessageBox>

QSerialPort serial;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    serial.setPortName("COM3");
    serial.setBaudRate(QSerialPort::Baud19200);
    serial.setDataBits(QSerialPort::Data8);
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
        QByteArray Rouge("\x15\x7B\x1A\xAA");
        serial.write(Rouge);
        QString t = ui->label->text();
        ui->label->setText(t+"\n15 7B 1A AA");
    }
    if(ui->radioButton_2->isChecked())
    {
        QByteArray Vert("\x15\x7B\x19\xA9");
        serial.write(Vert);
    }
    if(ui->radioButton_3->isChecked())
    {
        QByteArray Orange("\x15\x7B\x1B\xAB");
        serial.write(Orange);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    if(serial.open(QIODevice::ReadWrite))
    {
        ui->label->setText("Connecter");
    }
    else
    {
        ui->label->setText("Erreur");
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    serial.close();
    if(serial.isOpen() == false)
    {
        QString t = ui->label->text();
        ui->label->setText(t+"\nFermer");
    }
    else
    {
        ui->label->setText("Erreur");
    }

}
