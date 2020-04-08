#include "chambre.h"
#include <QDebug>
chambre::chambre()
{
num_chambre=0;
etage=0;
prix=0;
disponiblilite="";
type_chambre="";
bloc="";
}
chambre::chambre(int a,QString b,QString c,int d,QString e,int f)
{
    this->num_chambre=a;
    this->bloc=b;
    this->type_chambre=c;
    this->prix=d;
    this->disponiblilite=e;
    this->etage=f;
}
QString chambre::get_type_chambre(){return type_chambre;}
QString chambre::get_bloc(){return bloc ;}
QString chambre::get_disponibilite(){return disponiblilite;}
int chambre::get_num_chambre(){return num_chambre;}
int chambre::get_etage(){return etage;}
int chambre::get_prix(){return prix;}
int chambre::test(int a){return a;}
int chambre::stat(){
    QSqlQuery query1;
int res=258;



    int prix1=0;
    query1.prepare("select * from chambre where NUM_CHAMBRE=:num_chambre");
   query1.bindValue(":num_chambre", res);

    if (query1.exec())
    {

        while (query1.next()) {

             prix1= query1.value(5).toInt();

        }
    }
    return prix1;
}
QSqlQueryModel * chambre::afficher3( )
{QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;


query.prepare("select NUM_CHAMBRE from CHAMBRE ");

query.exec();
model->setQuery(query);

model->setHeaderData(0, Qt::Horizontal, QObject::tr("num_chambre"));


    return model;
}
bool chambre::ajouter()
{
QSqlQuery query;
QString res= QString::number(num_chambre);
QString res1= QString::number(etage);
QString res2= QString::number(prix);

query.prepare("INSERT INTO chambre (NUM_CHAMBRE, TYPE_CHAMBRE, BLOC,ETAGE,DISPONIBILITE,PRIX) "
                    "VALUES (:num_chambre, :type_chambre, :bloc,:etage,:disponibilite,:prix)");
query.bindValue(":num_chambre", res);
query.bindValue(":type_chambre", type_chambre);
query.bindValue(":bloc", bloc);
query.bindValue(":disponibilite", disponiblilite);
query.bindValue(":etage", res1);
query.bindValue(":prix", res2);

return    query.exec();
}
bool chambre::supprimer(int num)
{
QSqlQuery query;
QString res= QString::number(num);
query.prepare("Delete from chambre where NUM_CHAMBRE = :num ");
query.bindValue(":num", res);
return    query.exec();
}
bool chambre::modifier(int num)
{
    QSqlQuery query;
    QString res= QString::number(num);
query.prepare("UPDATE  chambre SET TYPE_CHAMBRE= :type ,ETAGE=:etage,BLOC=:bloc,DISPONIBILITE=:dispo,"
              "PRIX=:prix WHERE NUM_CHAMBRE = :num ") ;
query.bindValue(":num", res);
query.bindValue(":type", type_chambre);
query.bindValue(":etage", etage);
query.bindValue(":bloc", bloc);
query.bindValue(":dispo", disponiblilite);
query.bindValue(":prix", prix);

   return query.exec();

}

QSqlQueryModel * chambre::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from chambre");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("num_chambre"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("type_chambre "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("bloc"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("etage"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("disponibilite "));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("prix"));


    return model;
}
QSqlQueryModel * chambre::afficher1(int num ) //hethi rechercher
{QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    QString res= QString::number(num); //hethi bich trod il int string

query.prepare("select * from chambre where NUM_CHAMBRE = :num");//hethi il commande sql
query.bindValue(":num", res);//hethi bich t7ot il valeur f :num
query.exec();//hethi tamel execution mtta requette sql
model->setQuery(query);//hethi t7ot les valeur fi model
//hethom bich t7ot kol colonne chfeha mratbin kif ma ma7toutin fil base
model->setHeaderData(0, Qt::Horizontal, QObject::tr("num_chambre"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("type_chambre "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("bloc"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("etage"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("disponibilite "));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("prix"));

    return model;
}
QSqlQueryModel * chambre::afficher2(QString tri)//hethi tri
{QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    QString res= tri;
if(tri=="prix_croissant")
query.prepare("select * from chambre order  by PRIX asc");
if(tri=="prix_decroissant")
    query.prepare("select * from chambre order  by PRIX desc");
query.bindValue(":id", res);
query.exec();
model->setQuery(query);

model->setHeaderData(0, Qt::Horizontal, QObject::tr("num_chambre"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("type_chambre "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("bloc"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("etage"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("disponibilite "));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("prix"));
    return model;
}
QChartView * chambre::statistique()
{
    QBarSet *set0 = new QBarSet("Jane");
    QBarSet *set1 = new QBarSet("John");
    QBarSet *set2 = new QBarSet("Axel");
    QBarSet *set3 = new QBarSet("Mary");
    QBarSet *set4 = new QBarSet("Samantha");
int x=50;
    *set0 << x << x << x << 4 << 5 << 6;
    *set1 << x << 0 << 0 << 4 << 0 << 7;
    *set2 << 3 << 5 << 8 << 13 << 8 << 5;
    *set3 << 5 << 6 << 7 << 3 << 4 << 5;
    *set4 << 9 << 7 << 5 << 3 << x << 2;
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
    chart->setTitle("Simple barchart example");
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
    return chartView;
}
