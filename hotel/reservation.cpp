#include "reservation.h"
#include <QDebug>
reservation::reservation()
{
id_client=0;
num_chambre=0;
prix=0;
type_chambre="";
evenement="";
nombre_nuitee=0;

}
reservation::reservation(int a,QString b,QString c,int d,int e,QDate f,int g,QString k)
{

    this->id_client=a;
    this->evenement=b;
    this->type_chambre=c;
    this->num_chambre=d;
    this->prix=e;
    this->date_a=f;
    this->nombre_nuitee=g;
    this->evenement=k;

}
bool reservation::supprimer(int id)
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("Delete from reservation where ID_RESERVATION = :id ");
query.bindValue(":id", res);
return    query.exec();
}
int reservation::stat(){
    return 100;
}
int reservation::get_id_client(){return id_client;}
QString reservation::get_evenement(){return evenement;}
QString reservation::get_type_chambre(){return type_chambre;}
QDate reservation::get_date_a(){return date_a;}
int reservation::get_nombre_nuitee(){return nombre_nuitee;}
int reservation::get_prix(){return prix;}
int reservation::get_num_chambre(){return num_chambre;}
bool reservation::ajouter()
{
QSqlQuery query;
QSqlQuery query1,query2;
QString res= QString::number(num_chambre);
QString res1= QString::number(id_client);

QString res2;

int prixt;
int prix1;
int prix2;
query2.prepare("select * from evenement where NOM_EVENT=:event");
query2.bindValue(":event", evenement);

if (query2.exec())
{

    while (query2.next()) {

         prix2= query2.value(1).toInt();

    }
}
query1.prepare("select * from chambre where NUM_CHAMBRE=:num_chambre");
query1.bindValue(":num_chambre", res);

if (query1.exec())
{

    while (query1.next()) {

         prix1= query1.value(5).toInt();
         prixt=(prix1*nombre_nuitee)+prix2;
        res2= QString::number(prixt);
    }
}


query.prepare("INSERT INTO reservation (ID_CLIENT,NUM_CHAMBRE, TYPE_CHAMBRE, EVENEMENT, DATE_A,NOMBRE_NUITEE,PRIX) "
                    "VALUES (:id_client,:num_chambre, :type_chambre, :evenement,:date_a,:nbr_n,:prix)");
query.bindValue(":num_chambre", res);
query.bindValue(":id_client", res1);
query.bindValue(":prix", res2);
query.bindValue(":type_chambre", type_chambre);
query.bindValue(":evenement", evenement);
query.bindValue(":date_a", date_a);
query.bindValue(":nbr_n", nombre_nuitee);

return    query.exec();
}
QSqlQueryModel * reservation::afficher1( )
{QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;


query.prepare("select ID from client ");

query.exec();
model->setQuery(query);

model->setHeaderData(0, Qt::Horizontal, QObject::tr("num_chambre"));


    return model;
}
QSqlQueryModel * reservation::afficher6( )
{QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;


query.prepare("select ID_RESERVATION from reservation ");

query.exec();
model->setQuery(query);

model->setHeaderData(0, Qt::Horizontal, QObject::tr("num_chambre"));


    return model;
}
QSqlQueryModel * reservation::afficher7( )
{QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;


query.prepare("select NOM_EVENT from evenement ");

query.exec();
model->setQuery(query);

model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));


    return model;
}
QSqlQueryModel * reservation::afficher5( )
{QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;


query.prepare("select ID_RESERVATION from reservation ");

query.exec();
model->setQuery(query);

model->setHeaderData(0, Qt::Horizontal, QObject::tr("num_chambre"));


    return model;
}
QSqlQueryModel * reservation::afficher3(QString type)
{QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
QString libre="LIBRE";

query.prepare("select NUM_CHAMBRE from chambre where TYPE_CHAMBRE=:type AND DISPONIBILITE=:lib");
query.bindValue(":type", type);
query.bindValue(":lib", libre);
query.exec();
model->setQuery(query);

model->setHeaderData(0, Qt::Horizontal, QObject::tr("num_chambre"));


    return model;
}
QSqlQueryModel * reservation::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from reservation");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_reservation"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("id_client"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_arrivée"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("evenement"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("type_chambre"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("num_chambre"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("nombre de nuitée"));


    return model;
}
QSqlQueryModel * reservation::afficher2(QString tri)
{QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    QString res= tri;
if(tri=="prix_croissant")
query.prepare("select * from reservation order  by PRIX desc");
if(tri=="prix_decroissant")
    query.prepare("select * from reservation order  by PRIX asc");
query.bindValue(":id", res);
query.exec();
model->setQuery(query);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_reservation"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("id_client"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_arrivée"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("evenement"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("type_chambre"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("num_chambre"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("nombre de nuitée"));

    return model;
}
QSqlQueryModel * reservation::afficher4(int id )
{QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    QString res= QString::number(id);

query.prepare("select * from reservation where id_reservation = :num");
query.bindValue(":num", res);
query.exec();
model->setQuery(query);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_reservation"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("id_client"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_arrivée"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("evenement"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("type_chambre"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("num_chambre"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("nombre de nuitée"));


    return model;
}
bool reservation::modifier(int num)
{
    QSqlQuery query,query1;
    QString res= QString::number(num);
    QString res1= QString::number(num_chambre);
    QString res2;
    int prixt;
    int prix1;
    query1.prepare("select * from chambre where NUM_CHAMBRE=:num_chambre");
    query1.bindValue(":num_chambre", res1);

    if (query1.exec())
    {

        while (query1.next()) {

             prix1= query1.value(5).toInt();
             prixt=prix1*nombre_nuitee;
            res2= QString::number(prixt);
        }
    }
query.prepare("UPDATE  reservation SET ID_CLIENT= :id ,DATE_A=:date,EVENEMENT=:event,"
              "NOMBRE_NUITEE=:nb,PRIX=:prix ,NUM_CHAMBRE = :num,TYPE_CHAMBRE=:type WHERE ID_RESERVATION=:id_r ") ;
query.bindValue(":id_r", res);
query.bindValue(":type", type_chambre);
query.bindValue(":id", id_client);
query.bindValue(":date", date_a);
query.bindValue(":event", evenement);
query.bindValue(":prix", res2);
query.bindValue(":nb", nombre_nuitee);
query.bindValue(":num", num_chambre);
   return query.exec();

}

