#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "reservation.h"
#include "mainwindow1.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_clicked();

    void on_tabWidget_tabBarClicked(int index);

    void on_comboBox_5_currentIndexChanged(const QString &arg1);

    void on_pb_rechercher_clicked();

    void on_pb_trier_clicked();

    void on_comboBox_11_currentIndexChanged(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();


    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();



private:
    Ui::Dialog *ui;
    reservation tmpid;
    reservation tmpreservation;

     MainWindow1 * main;
};

#endif // DIALOG_H
