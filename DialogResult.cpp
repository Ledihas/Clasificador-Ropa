#include "DialogResult.h"
#include "ui_DialogResult.h"
#include "mainwindow.h"
#include "QDebug"
#include "QTimer"


Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)

{
    ui->setupUi(this);


    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Dialog::showResp);
    timer->start(1000);

}




Dialog::~Dialog()
{
    delete ui;
    showResp();
}

QString res;

void MainWindow:: recived()
{
    qDebug() << DefinitiveResp;
    res =  DefinitiveResp;
}

void Dialog::showResp()
{
    qDebug() << res;
    ui->label->setText(res);
}


void Dialog::on_accept_clicked()
{

    close();

}




