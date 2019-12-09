#include "mainwindow.h"
#include "ui_mainwindow.h"





MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    serial = new QSerialPort(this);
    timer = new QTimer(this);

//    connect(serial,SIGNAL(error(QSerialPort::SerialPortError)),this,SLOT(serialPortError(QSerialPort::SerialPortError)));


    serial->setPortName("COM3");
    serial->setBaudRate(QSerialPort::Baud19200);
    serial->setDataBits(QSerialPort::Data8);                         //paramètres du port série
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    connect(serial,SIGNAL(readyRead()),this,SLOT(lectureDonnees()));
    connect(timer,SIGNAL(timeout()),this,SLOT(lectureDonnees()));
//    serial->waitForReadyRead(100);
//    QByteArray output = serial->readAll();
//    ui->label->setText(output);
}

MainWindow::~MainWindow()
{
    if(serial->isOpen())
    {
        serial->close();
    }
    delete ui;

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
                serial->write(Rouge);
                QString t = ui->label->text();
                ui->label->setText(t+"\n15 7B 1A AA");
            }
            if(ui->radioButton_2->isChecked())
            {
                QByteArray Vert("\x15\x7B\x19\xA9");    //allume en vert
                serial->write(Vert);
                QString t = ui->label->text();
                ui->label->setText(t+"\n15 7B 19 A9");
            }
            if(ui->radioButton_3->isChecked())
            {
                QByteArray Orange("\x15\x7B\x1B\xAB");  //allume en orange
                serial->write(Orange);
                QString t = ui->label->text();
                ui->label->setText(t+"\n15 7B 1B AB");
            }
        }
        if(ui->comboBox->currentText()=="SP0EB9")
        {
            if(ui->radioButton->isChecked())
            {
                QByteArray Rouge("\x0E\xB9\x1A\xE1");
                serial->write(Rouge);
                QString t = ui->label->text();
                ui->label->setText(t+"\n0E B9 1A E1");
            }
            if(ui->radioButton_2->isChecked())
            {
                QByteArray Vert("\x0E\xB9\x19\xE0");    //allume en vert
                serial->write(Vert);
                QString t = ui->label->text();
                ui->label->setText(t+"\n0E B9 19 E0");
            }
            if(ui->radioButton_3->isChecked())
            {
                QByteArray Orange("\x0E\xB9\x1B\xE2");  //allume en orange
                serial->write(Orange);
                QString t = ui->label->text();
                ui->label->setText(t+"\n0E B9 1B E2");
            }
        }

}

void MainWindow::lectureDonnees()
{

    lire = serial->readAll();
    ui->textEdit->append("DATA : " + lire.toHex() );


}

void MainWindow::on_pushButton_2_clicked()
{
//---------------ouverture du port--------------

    if(serial->open(QIODevice::ReadWrite))
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

    serial->close();
    if(serial->isOpen() == false)
    {

        QString t = ui->label->text();
        ui->label->setText(t+"\nFermer");
    }
    else
    {
        ui->label->setText("Erreur");
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->textEdit->clear();
}

void MainWindow::on_pushButton_5_clicked()
{

    serial->isOpen()==false;

}
