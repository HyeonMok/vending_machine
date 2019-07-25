#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QString>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbCoffe->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbCoke->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int n){
    money += n;
    ui->lcdNumber->display(money);
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
    moneyCheck();
}

void Widget::on_pb50_clicked()
{

    changeMoney(50);
    moneyCheck();
}


void Widget::on_pb100_clicked()
{
    changeMoney(100);
    moneyCheck();
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
    moneyCheck();
}

void Widget::on_pbCoffe_clicked()
{
    changeMoney(-100);
    moneyCheck();
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
    moneyCheck();
}

void Widget::on_pbCoke_clicked()
{
    changeMoney(-200);
    moneyCheck();
}

void Widget::getChange(){

    if(money >= 500){
        while(true){
            money -= 500;
            count500++;
            if(money < 500){break;}}}
     if (money >= 100){
        while(true){
            money -= 100;
            count100++;
            if(money < 100){break;}}}
     if (money >= 50){
        while(true){
            money -= 50;
            count50++;
            if(money < 50){break;}}}
     if (money >= 10){
        while(true){
            money -= 10;
            count10++;
            if(money < 10){break;}}}
     if (money == 0){
        money = 0;
        ui->lcdNumber->display(money);
    }
    else { QMessageBox msg;
           msg.information(nullptr, "ERROR", "This Program Fail....");}
}
void Widget::varRest(){
    money = 0;
    count500 = 0;
    count100 = 0;
    count50 = 0;
    count10 = 0;
    total = 0;
}
void Widget::moneyCheck(){
    if(money>=100){ui->pbCoffe->setEnabled(true);}
    if(money<100){ui->pbCoffe->setEnabled(false);}

    if(money>=150){ui->pbTea->setEnabled(true);}
    if(money<150){ui->pbTea->setEnabled(false);}

    if(money>=200){ui->pbCoke->setEnabled(true);}
    if(money<200){ui->pbCoke->setEnabled(false);}

}
void Widget::on_pbReturn_clicked()
{
    getChange();
    total = ((count500*500)+(count100*100)+(count50*50)+(count10*10));
    QString str;
    str.sprintf("Your money~!!!!!!!!!!!!!!!!\n\n500: %d (EA)\n100: %d (EA)\n"
                "50: %d (EA)\n10: %d (EA)\n\nTOTAL: %d(KRW)\n\nBye~!", count500, count100, count50, count10, total);

    QMessageBox msg;
    msg.information(nullptr, "Money is most of life", str);
    varRest();
    moneyCheck();

}
