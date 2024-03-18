#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

void Widget::change(int mon){
    money += mon;
    ui->lcdNumber->display(money);
    changeimpos();
}

void Widget::changeimpos(){
    ui->pbC->setEnabled(money>=100);
    ui->pbm->setEnabled(money>=200);
    ui->pbt->setEnabled(money>=150);
    ui->pbreset->setEnabled(money>0);
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    changeimpos();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pb10_clicked()
{
    money +=10;
    ui->lcdNumber->display(money);
    changeimpos();
}


void Widget::on_pbC_clicked()
{
    change(-100);
}


void Widget::on_pbreset_clicked()
{
    QMessageBox mb;
    int l500 = money/500;
    int l100 = (money%500)/100;
    int l50 = (money%100)/50;
    int l10 =(money%50)/10;
    money = 0;
    QString msg = "";
    if (l500){
        msg = msg+ "500: " + QString::number(l500)+"\n";
    }
    if (l100){
        msg = msg+ "100: " + QString::number(l100)+"\n";
    }
    if (l50){
        msg = msg+ "50: " + QString::number(l50)+"\n";
    }
    if (l10){
        msg = msg+ "10: " + QString::number(l10)+"\n";
    }
    mb.information(nullptr,"Title",msg);

}


void Widget::on_pb50_clicked()
{
    change(50);
}


void Widget::on_pb100_clicked()
{
    change(100);
}


void Widget::on_pb500_clicked()
{
    change(500);
}


void Widget::on_pbt_clicked()
{
    change(-150);
}


void Widget::on_pbm_clicked()
{
    change(-200);
}

