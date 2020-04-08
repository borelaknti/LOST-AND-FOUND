#include "dialog.h"
#include "dialog1.h"
#include "ui_dialog.h"
#include "reservation.h"
#include "mainwindow1.h"
#include <QMessageBox>
#include <QPrinter>
#include <QPainter>
#include <QPrintDialog>
#include <QMessageBox>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QDialog>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>

QT_CHARTS_USE_NAMESPACE
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->tabreservation->setModel(tmpreservation.afficher());
  ui->comboBox_10->setModel(tmpid.afficher1());
  ui->comboBox_16->setModel(tmpid.afficher1());
  ui->comboBox_17->setModel(tmpid.afficher5());
   ui->comboBox->setModel(tmpid.afficher6());
   ui->comboBox_2->setModel(tmpid.afficher6());
   ui->comboBox_9->setModel(tmpid.afficher7());
   ui->comboBox_15->setModel(tmpid.afficher7());


}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{

    int id_client = ui->comboBox_10->currentText().toInt();
     QDate date_a = ui->dateEdit_3->date();
     int nombre_nuitee = ui->lineEdit->text().toInt();
      int num_chambre = ui->comboBox_6->currentText().toInt();
      QString type_chambre = ui->comboBox_5->currentText();
      QString evenement = ui->comboBox_9->currentText();
      int prix=50;



  reservation  r(id_client,evenement,type_chambre,num_chambre,prix,date_a,nombre_nuitee,evenement);
  bool test=r.ajouter();



  if(test)
{
ui->tabreservation->setModel(tmpreservation.afficher());
QMessageBox::information(nullptr, QObject::tr("Ajouter une chambre"),
                  QObject::tr("Chambre ajoutée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une chambre"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void Dialog::on_tabWidget_tabBarClicked(int )
{
      ui->tabreservation->setModel(tmpreservation.afficher());
    ui->comboBox_10->setModel(tmpid.afficher1());
    ui->comboBox_16->setModel(tmpid.afficher1());
    ui->comboBox_17->setModel(tmpid.afficher5());
     ui->comboBox->setModel(tmpid.afficher6());
     ui->comboBox_2->setModel(tmpid.afficher6());
}

void Dialog::on_comboBox_5_currentIndexChanged(const QString &)
{
    QString type=ui->comboBox_5->currentText();
     ui->comboBox_6->setModel(tmpid.afficher3(type));
}

void Dialog::on_pb_rechercher_clicked()
{
    int num = ui->lineEdit_s->text().toInt();
    ui->tabreservation->setModel(tmpreservation.afficher4(num));
}

void Dialog::on_pb_trier_clicked()
{
    QString tri =ui->box_t->currentText();
    ui->tabreservation->setModel(tmpreservation.afficher2(tri));
}

void Dialog::on_comboBox_11_currentIndexChanged(const QString &)
{
    QString type=ui->comboBox_11->currentText();
     ui->comboBox_12->setModel(tmpid.afficher3(type));
}

void Dialog::on_pushButton_2_clicked()
{
    int id_r = ui->comboBox_17->currentText().toInt();
     int id_client = ui->comboBox_16->currentText().toInt();
      QDate date_a = ui->dateEdit_4->date();
      int nombre_nuitee = ui->lineEdit_2->text().toInt();
       int num_chambre = ui->comboBox_12->currentText().toInt();
       QString type_chambre = ui->comboBox_11->currentText();
       QString evenement = ui->comboBox_15->currentText();
       int prix=50;




  reservation  r(id_client,evenement,type_chambre,num_chambre,prix,date_a,nombre_nuitee,evenement);
  bool test=r.modifier(id_r);



  if(test)
{
ui->tabreservation->setModel(tmpreservation.afficher());
QMessageBox::information(nullptr, QObject::tr("Ajouter une chambre"),
                  QObject::tr("Chambre ajoutée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une chambre"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);




}

void Dialog::on_pushButton_3_clicked()
{
    int num = ui->comboBox_2->currentText().toInt();

    QSqlQuery query1;




    QString idr="";
    QString id_c="";
    QDate date;
      QString date1="";
    QString nbre="";
    QString type="";
    QString nc="";
    QString prix="";
    query1.prepare("select * from reservation where ID_RESERVATION=:id");
   query1.bindValue(":id", num);

    if (query1.exec())
    {

        while (query1.next()) {

             idr= query1.value(0).toString();
             date = query1.value(2).toDate();
             date1=date.toString("yyyy-MM-dd");
             type= query1.value(5).toString();
             nbre= query1.value(7).toString();
             nc= query1.value(6).toString();
             id_c= query1.value(1).toString();
             prix= query1.value(4).toString();


        }
    }
          QPrinter printer(QPrinter::HighResolution);
              printer.setPageSize(QPrinter::A4);

             QPrintDialog *dialog = new QPrintDialog(&printer);
              if (dialog->exec() == QDialog::Accepted)
              {               QPainter painter (&printer);
                              painter.begin(&printer);
                              QFont f;
                                  f.setPointSize(20);
                                  f.setBold(true);
                                  painter.setFont(f);
                               painter.drawText(100, 500, "RESERVATION N°:");
                                painter.drawText(2000, 500, idr);
                               f.setPointSize(15);
                               f.setBold(true);
                               painter.setFont(f);
                               painter.drawText(100, 1000, "ID_CLIENT :");
                               painter.drawText(1000, 1000, id_c);
                               painter.drawText(100, 1200, "DATE ARRIVEE :");
                               painter.drawText(1200, 1200, date1);
                               painter.drawText(100, 1400, "NOMBRE DE NUITEE :");
                               painter.drawText(1500, 1400, nbre);
                               painter.drawText(100, 1600, " TYPE CHAMBRE :");
                               painter.drawText(1500, 1600, type);
                               painter.drawText(100, 1800, " NUM CHAMBRE :");
                               painter.drawText(1500, 1800, nc);
                               painter.drawText(100, 2000, " PRIX TOTAL :");
                               painter.drawText(1500, 2000, prix);

                              painter.end();

              }

}

void Dialog::on_pushButton_4_clicked()
{
    QBarSet *set0 = new QBarSet("2020");
    QBarSet *set1 = new QBarSet("2019");
    QBarSet *set2 = new QBarSet("1018");
    QBarSet *set3 = new QBarSet("2017");
    QBarSet *set4 = new QBarSet("2016");
    QSqlQuery query1;
    int prix1,prixj=0,prixj1=0,prixj2=0,prixj3=0,prixj4=0;
    int prixf=0,prixf1=0,prixf2=0,prixf3=0,prixf4=0;
    int prixm=0,prixm1=0,prixm2=0,prixm3=0,prixm4=0;
    int prixa=0,prixa1=0,prixa2=0,prixa3=0,prixa4=0;
    int prixma=0,prixma1=0,prixma2=0,prixma3=0,prixma4=0;
    int prixju=0,prixju1=0,prixju2=0,prixju3=0,prixju4=0;
    QDate date1;

    query1.prepare("select * from reservation ");


    if (query1.exec())
    {

        while (query1.next()) {

            date1=query1.value(2).toDate();
            prix1= query1.value(4).toInt();
            if(date1.month()==01 and date1.year()==2020 )
            {
             prixj=prixj+prix1;
            }
            if(date1.month()==01 and date1.year()==2019 )
            {
             prixj1=prixj1+prix1;
            }
            if(date1.month()==01 and date1.year()==2018 )
            {
             prixj2=prixj2+prix1;
            }
            if(date1.month()==01 and date1.year()==2017 )
            {
             prixj3=prixj3+prix1;
            }
            if(date1.month()==01 and date1.year()==2016 )
            {
             prixj4=prixj4+prix1;
            }

            if(date1.month()==02 and date1.year()==2020 )
            {
             prixf=prixf+prix1;
            }
            if(date1.month()==02 and date1.year()==2019 )
            {
             prixf1=prixf1+prix1;
            }
            if(date1.month()==02 and date1.year()==2018 )
            {
             prixf2=prixf2+prix1;
            }
            if(date1.month()==03 and date1.year()==2017 )
            {
             prixf3=prixf3+prix1;
            }
            if(date1.month()==03 and date1.year()==2016 )
            {
             prixf4=prixf4+prix1;
            }
            if(date1.month()==03 and date1.year()==2020 )
            {
             prixm=prixm+prix1;
            }
            if(date1.month()==03 and date1.year()==2019 )
            {
             prixm1=prixm1+prix1;
            }
            if(date1.month()==03 and date1.year()==2018 )
            {
             prixm2=prixm2+prix1;
            }
            if(date1.month()==03 and date1.year()==2017 )
            {
             prixm3=prixm3+prix1;
            }
            if(date1.month()==03 and date1.year()==2016 )
            {
             prixm4=prixm4+prix1;
            }
            if(date1.month()==04 and date1.year()==2020 )
            {
             prixa=prixa+prix1;
            }
            if(date1.month()==04 and date1.year()==2019 )
            {
             prixa1=prixa1+prix1;
            }
            if(date1.month()==04 and date1.year()==2018 )
            {
             prixa2=prixa2+prix1;
            }
            if(date1.month()==04 and date1.year()==2017 )
            {
             prixa3=prixa3+prix1;
            }
            if(date1.month()==04 and date1.year()==2016 )
            {
             prixa4=prixa4+prix1;
            }
            if(date1.month()==05 and date1.year()==2020 )
            {
             prixma=prixma+prix1;
            }
            if(date1.month()==05 and date1.year()==2019 )
            {
             prixma1=prixma1+prix1;
            }
            if(date1.month()==05 and date1.year()==2018 )
            {
             prixma2=prixma2+prix1;
            }
            if(date1.month()==05 and date1.year()==2017 )
            {
             prixma3=prixma3+prix1;
            }
            if(date1.month()==05 and date1.year()==2016 )
            {
             prixma4=prixma4+prix1;
            }
            if(date1.month()==06 and date1.year()==2019 )
            {
             prixju1=prixju1+prix1;
            }
            if(date1.month()==06 and date1.year()==2018 )
            {
             prixju2=prixju2+prix1;
            }
            if(date1.month()==06 and date1.year()==2017 )
            {
             prixju3=prixju3+prix1;
            }
            if(date1.month()==06 and date1.year()==2016 )
            {
             prixju4=prixju4+prix1;
            }
            if(date1.month()==06 and date1.year()==2020 )
            {
             prixju=prixju+prix1;
            }



        }
    }
    *set0 << prixj << prixf << prixm << prixa << prixma << prixju;
    *set1 << prixj1 << prixf1 << prixm1 << prixa1 << prixma1 << prixju1;
    *set2 << prixj2 << prixf2 << prixm2 << prixa2 << prixma2 << prixju2;
    *set3 << prixj3 << prixf3 << prixm3 << prixa3 << prixma3 << prixju3;
    *set4 << prixj4 << prixf4 << prixm4 << prixa4 << prixma4 << prixju4;
//![1]

//![2]
    QBarSeries *series = new QBarSeries();
    series->append(set0);
    series->append(set1);
    series->append(set2);
    series->append(set3);
    series->append(set4);

//![2]

//![3]
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistique Chiffre d'affaires ");
    chart->setAnimationOptions(QChart::SeriesAnimations);
//![3]

//![4]
    QStringList categories;
    categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun";
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();
    chart->setAxisX(axis, series);
//![4]

//![5]
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
//![5]

//![6]
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
//![6]

//![7]
main= new MainWindow1(this);
    main->setCentralWidget(chartView);
    main->resize(420, 300);
    main->show();

}



void Dialog::on_pushButton_5_clicked()
{
    int id = ui->comboBox->currentText().toInt();
    bool test=tmpreservation.supprimer(id);
    if(test)
    {ui->tabreservation->setModel(tmpreservation.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une reservation"),
                    QObject::tr("Reservation  supprimée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une reservation"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialog::on_pushButton_6_clicked()
{
    hide();
    Dialog1 main1;
     main1.setModal(true);
     main1.exec();
}


