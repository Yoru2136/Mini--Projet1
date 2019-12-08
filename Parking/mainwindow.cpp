#include "mainwindow.h"
#include "ui_mainwindow.h"


QSerialPort serial;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
//-------------paramètres du port série---------------------|
    ui->setupUi(this);
    serial.setPortName("COM3");
    serial.setBaudRate(QSerialPort::Baud19200);
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setFlowControl(QSerialPort::NoFlowControl);
//    ui->comboBox->addItem("SP157B");
//    ui->comboBox->addItem("SP0EB9");
}

MainWindow::~MainWindow()
{
//    delete ui;
//    serial.close();
}

void MainWindow::on_pushButton_clicked()
{
//------------SYSTEME SP ADDRESSE ---> 15 7B---------------

//    QString Text = ui->comboBox->currentText();
    if(ui->comboBox->currentText()=="SP157B")
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
            QByteArray Vert("\x15\x7B\x19\xA9");    //allume en vert
            serial.write(Vert);
            QString t = ui->label->text();
            ui->label->setText(t+"\n15 7B 19 A9");
        }
        if(ui->radioButton_3->isChecked())
        {
            QByteArray Orange("\x15\x7B\x1B\xAB");  //allume en orange
            serial.write(Orange);
            QString t = ui->label->text();
            ui->label->setText(t+"\n15 7B 1B AB");
        }
    }
    if(ui->comboBox->currentText()=="SP0EB9")
    {
        if(ui->radioButton->isChecked())
        {
            QByteArray Rouge("\x0E\xB9\x1A\xE1");
            serial.write(Rouge);
            QString t = ui->label->text();
            ui->label->setText(t+"\n0E B9 1A E1");
        }
        if(ui->radioButton_2->isChecked())
        {
            QByteArray Vert("\x0E\xB9\x19\xA9");    //allume en vert
            serial.write(Vert);
            QString t = ui->label->text();
            ui->label->setText(t+"\n0E B9 19 E0");
        }
        if(ui->radioButton_3->isChecked())
        {
            QByteArray Orange("\x0E\xB9\x1B\xE2");  //allume en orange
            serial.write(Orange);
            QString t = ui->label->text();
            ui->label->setText(t+"\n0E B9 1B E2");
        }
    }


}

void MainWindow::on_pushButton_2_clicked()
{
//---------------ouverture du port--------------
    if(serial.open(QIODevice::ReadWrite))
    {
        ui->label->setText("Connecter");
        while(!port->atEnd())
        {
            QByteArray output;
            output = port->readAll();
            ui->label->setText("output");
//            QByteArray data = port->readAll();
//            ui->label->setText(data);                              //https://stackoverrun.com/fr/q/8689536
           
        }
    }
    else
    {
        ui->label->setText("Erreur");
    }

}

void MainWindow::on_pushButton_3_clicked()
{
//---------------fermeture du port-------------
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
