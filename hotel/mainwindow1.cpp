#include "mainwindow1.h"
#include "ui_mainwindow1.h"
#include "QDialog"
#include "dialog.h"
MainWindow1::MainWindow1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow1)
{
    ui->setupUi(this);
}

MainWindow1::~MainWindow1()
{
    delete ui;
}


