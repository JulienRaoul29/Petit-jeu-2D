 #include "tir.h"
 #include "mainwindow.h"
 #include <QTimer>
#include <QGraphicsScene>
#include<QDebug>
Tir::Tir()
{

    setRect(0,0,5,5);
    // mon signal pour rendement de bal
    QTimer * temps=new QTimer();
    connect(temps,SIGNAL(timeout()),this,SLOT(move()));
    temps->start(15);

}

void Tir::move()
{

 setPos(x(),y()-3);
 if (this->pos().y() + rect().height() < 0){
        scene()->removeItem(this);
        delete this;
  }
}
