#include "sword.h"
#include "mainwindow.h"
#include <QTimer>
#include <QTime>
#include <QGraphicsScene>
#include <QPropertyAnimation>
#include<QDebug>
#include <QTimer>
Sword::Sword()
{
    setRect(0,-45,5,45);
    // mon signal pour rendement de bal
    temps=new QTimer();
    connect(temps,SIGNAL(timeout()),this,SLOT(Move()));
    temps->start(30);


}


void Sword::Move()
{

            scene()->removeItem(this);
            delete this;
}
