#ifndef MAINWINDOW_H
#define MAINWINDOW_H
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

private:
    Ui::MainWindow *ui;     //interface utilisateur
    QSerialPort *port;

};

#endif // MAINWINDOW_H
