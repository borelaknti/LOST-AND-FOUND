#include "dialog1.h"
#include "ui_dialog1.h"
#include "dialog.h"
Dialog1::Dialog1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog1)
{
    ui->setupUi(this);
}

Dialog1::~Dialog1()
{
    delete ui;
}

void Dialog1::on_pushButton_clicked()
{
    hide();
    Dialog main1;
     main1.setModal(true);
     main1.exec();
}

void Dialog1::on_pushButton_2_clicked()
{
    hide();
 ch = new MainWindow;
 ch->show();
}