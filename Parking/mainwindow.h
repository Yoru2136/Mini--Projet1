#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

};

#endif // MAINWINDOW_H
