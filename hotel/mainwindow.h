#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "chambre.h"

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:


    void on_ajouter_c_clicked();

    void on_pb_rechercher_clicked();

    void on_pb_trier_clicked();

    void on_pushButton_clicked();



    void on_modifier_clicked();

    void on_pushButton_2_clicked();







    void on_pushButton_4_clicked();



private:
    Ui::MainWindow *ui;

    chambre tmpchambre;


};
#endif // MAINWINDOW_H
