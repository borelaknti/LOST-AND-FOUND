#ifndef DIALOG1_H
#define DIALOG1_H
#include "mainwindow.h"
#include <QDialog>

namespace Ui {
class Dialog1;
}

class Dialog1 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog1(QWidget *parent = nullptr);
    ~Dialog1();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Dialog1 *ui;
    MainWindow * ch;
};

#endif // DIALOG1_H
