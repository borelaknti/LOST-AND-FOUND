#include "mainwindow.h"
#include "dialog.h"
#include "dialog1.h"
#include <QApplication>
#include <QMessageBox>
#include "connexion.h"
#include <QPrinter>
#include "chambre.h"
#include "mainwindow1.h"
#include <QPrintDialog>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
QT_CHARTS_USE_NAMESPACE
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connexion c;

    bool test=c.ouvrirConnexion();
    Dialog1 w;



//![7]


    if(test)
    {   w.show();


        QMessageBox::critical(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


    return a.exec();
}
