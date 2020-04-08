#ifndef CHAMBRE_H
#define CHAMBRE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>

QT_CHARTS_USE_NAMESPACE

class chambre
{
public:
    chambre();
    chambre(int,QString,QString,int,QString,int);
    int get_num_chambre();
    QString get_type_chambre();
    QString get_bloc();
    QString get_disponibilite();
    int stat();
    int get_prix();
    int get_etage();
    int test(int);
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficher1(int);
    QSqlQueryModel * afficher2(QString);
    QSqlQueryModel * afficher3();
    QChartView * statistique();

    bool supprimer(int);
    bool modifier(int);
private:
    QString type_chambre,bloc,disponiblilite;

    int num_chambre,etage,prix;
};

#endif // CHAMBRE_H
