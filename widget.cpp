#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int n)
{
     money +=n;
     ui->lcdNumber->display(money);

     if(money < 100)
     {
         ui->pbCoffe->setEnabled(0);

     }
     else
     {
         ui->pbCoffe->setEnabled(1);
     }

     if(money < 150)
     {
         ui->pbIceTea->setEnabled(0);

     }
     else
     {
        ui->pbIceTea->setEnabled(1);
     }

     if(money < 200)
     {
         ui->pbCoke->setEnabled(0);
     }
     else
     {
         ui->pbCoke->setEnabled(1);
     }

}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
}

void Widget::on_pbCoffe_clicked()
{
    changeMoney(-100);

}

void Widget::on_pbIceTea_clicked()
{
    changeMoney(-150);
}

void Widget::on_pbCoke_clicked()
{
    changeMoney(-200);
}

void Widget::on_pbReset_clicked()
{
   int temp = money;

   QString str = "";
   QMessageBox msg;

   if((int)(temp/500) != 0)
   {
       str += "500 : " + QString::number((int)(temp / 500)) + "\n";
       temp -= (int)(temp / 500) * 500;

   }
   if((int)(temp/100) != 0)
   {
       str += "100 : " + QString::number((int)(temp / 100)) + "\n";
       temp -= (int)(temp / 100) * 100;
   }
   if((int)(temp/50) != 0)
   {
       str += "50 : " + QString::number((int)(temp / 50)) + "\n";
       temp -= (int)(temp / 50) * 50;
   }
   if((int)(temp/10) != 0)
   {
       str += "10 : " + QString::number((int)(temp / 10)) + "\n";
   }

   msg.information(0,"Result",str);

   money = 0;

}
