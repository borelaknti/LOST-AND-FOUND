#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "chambre.h"
#include "dialog1.h"
#include <QDebug>
#include <QMessageBox>
#include <QPrinter>

#include <QPrintDialog>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>

QT_CHARTS_USE_NAMESPACE
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tabchambre->setModel(tmpchambre.afficher());
    ui->comboBox->setModel(tmpchambre.afficher3());
    ui->comboBox_4->setModel(tmpchambre.afficher3());

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_ajouter_c_clicked()
{
    int num_chambre = ui->lineEdit_2->text().toInt();
     int etage = ui->lineEdit_4->text().toInt();
      int prix = ui->lineEdit_6->text().toInt();
    QString type_chambre= ui->comboBox_5->currentText();
    QString bloc = ui->lineEdit_3->text();
    QString disponibilite = ui->comboBox_3->currentText();

  chambre  c(num_chambre,bloc,type_chambre,prix,disponibilite,etage);
  bool test=c.ajouter();

  if(test)
{
       ui->tabchambre->setModel(tmpchambre.afficher());
       ui->comboBox->setModel(tmpchambre.afficher3());
       ui->comboBox_4->setModel(tmpchambre.afficher3());
QMessageBox::information(nullptr, QObject::tr("Ajouter une chambre"),
                  QObject::tr("Chambre ajoutée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une chambre"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}





void MainWindow::on_pb_rechercher_clicked()
{
    int num = ui->lineEdit_s->text().toInt();
    ui->tabchambre->setModel(tmpchambre.afficher1(num));

}

void MainWindow::on_pb_trier_clicked()
{
    QString tri =ui->box_t->currentText();
    ui->tabchambre->setModel(tmpchambre.afficher2(tri));
}

void MainWindow::on_pushButton_clicked()
{
 //Dialog main1;
 //main1.setModal(true);
 //main1.exec();


}




void MainWindow::on_modifier_clicked()
{
    int num_chambre = ui->comboBox->currentText().toInt();
     int etage = ui->lineEdit_9->text().toInt();
      int prix = ui->lineEdit_11->text().toInt();
    QString type_chambre= ui->comboBox_6->currentText();
    QString bloc = ui->lineEdit_8->text();
    QString disponibilite = ui->comboBox_2->currentText();
    chambre  c(num_chambre,bloc,type_chambre,prix,disponibilite,etage);
    bool test=c.modifier(num_chambre);
  if(test)
{ ui->tabchambre->setModel(tmpchambre.afficher());
QMessageBox::information(nullptr, QObject::tr("Modifer une chambre"),
                  QObject::tr("Chambre modifiée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifer une chambre"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}


void MainWindow::on_pushButton_2_clicked()
{
    int num = ui->comboBox_4->currentText().toInt();
    bool test=tmpchambre.supprimer(num);
    if(test)
    {ui->tabchambre->setModel(tmpchambre.afficher());//refresh
        ui->comboBox->setModel(tmpchambre.afficher3());
        ui->comboBox_4->setModel(tmpchambre.afficher3());
        QMessageBox::information(nullptr, QObject::tr("Supprimer une chambre"),
                    QObject::tr("Chambre supprimée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une chambre"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}






void MainWindow::on_pushButton_4_clicked()
{
    hide();
    Dialog1 main1;
     main1.setModal(true);
     main1.exec();

}

