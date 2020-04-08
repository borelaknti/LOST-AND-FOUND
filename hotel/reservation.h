#ifndef RESERVATION_H
#define RESERVATION_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
class reservation
{
public:
    reservation();
    reservation(int,QString,QString,int,int,QDate,int,QString);
    int get_id_client();
    QString get_evenement();
    QString get_type_chambre();
    QDate get_date_a();
    int get_nombre_nuitee();
    int get_prix();
    int get_num_chambre();
    bool ajouter();
    int stat();
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficher1();
    QSqlQueryModel * afficher2(QString);
    QSqlQueryModel * afficher3(QString);
    QSqlQueryModel * afficher4(int);
    QSqlQueryModel * afficher5();
    QSqlQueryModel * afficher6();
    QSqlQueryModel * afficher7();
    bool supprimer(int);
    bool modifier(int);
private:
    QString evenement,type_chambre;
    int num_chambre,prix,id_client,nombre_nuitee;
    QDate date_a;

};

#endif // RESERVATION_H
