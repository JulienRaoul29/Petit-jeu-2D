#include "MainWindow.h"
#include "tir.h"
#include "sword.h"
#include <QApplication>
#include <QBrush>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QPoint>
#include <QList>
int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    MainWindow mainWindow;
    mainWindow.show();
    return app.exec();
}


MainWindow::MainWindow()
{
this->setFixedSize(1200,700);
scene = new QGraphicsScene();
scene->setSceneRect(0,0,1200,700);
this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

setScene(scene);

//QGraphicsRectItem *
player=new QGraphicsRectItem();
player->setRect(0,0,50,50);
player->setBrush(QBrush(Qt::red));
scene->addItem(player);
player->setPos(600,350);

//initialisation des valeur du mouvement
for(int i=0;i<6;i++)
{
    MaTouche[i]=false;
}
QTimer * temps = new QTimer();
temps->start(30); //1 seconde
connect(temps, SIGNAL(timeout()),SLOT(mouvement()));
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{


    /*************************************************************/
    if((event->key() == Qt::Key_Right)||(event->key() == Qt::Key_D))
    {    
        MaTouche[0]=true;
        //x=x+0;
        //y=y+taillePlayerY/2;
    }
    else if((event->key() == Qt::Key_Left)||(event->key() == Qt::Key_Q))
    {
        //x=x+taillePlayerX;
        //y=y+taillePlayerY/2;
        MaTouche[1]=true;


    }
    else if((event->key() == Qt::Key_Up)||(event->key() == Qt::Key_Z))
    {
        MaTouche[2]=true;
        //x=x+taillePlayerX/2;
        //y=y+0;

    }
    else if((event->key() == Qt::Key_Down)||(event->key() == Qt::Key_S))
    {
        MaTouche[3]=true;
        //x=x+taillePlayerX/2;
        //y=y+taillePlayerY;

    }
    else if((event->key()== Qt::Key_Space))
    {

        MaTouche[4]=true;
        //munition();

    }
    else if((event->key()== Qt::Key_E))
    {

        MaTouche[5]=true;

    }
}
void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if((event->key() == Qt::Key_Right)||(event->key() == Qt::Key_D))
    {
        MaTouche[0]=false;
    }
    else if((event->key() == Qt::Key_Left)||(event->key() == Qt::Key_Q))
    {
        MaTouche[1]=false;

    }
    else if((event->key() == Qt::Key_Up)||(event->key() == Qt::Key_Z))
    {
        MaTouche[2]=false;
    }
    else if((event->key() == Qt::Key_Down)||(event->key() == Qt::Key_S))
    {
        MaTouche[3]=false;
    }
    else if((event->key()== Qt::Key_Space))
    {
        MaTouche[4]=false;

    }
    else if((event->key()== Qt::Key_E))
    {

        MaTouche[5]=false;

    }
}

void MainWindow::mouvement()
{
    /*********permet de mettre une arme au niveau du centre*******/
    double x,y;
    //int taillePlayerX=50;
   // int taillePlayerY=50;
    x=player->pos().x();
    y=player->pos().y();

    if(MaTouche[0]==true && (player->pos().x() <1200-50)){this->player->moveBy(5,0);}
    if(MaTouche[1]==true && (player->pos().x() >0)) this->player->moveBy(-5,0);
    if(MaTouche[2]==true && (player->pos().y() >0)) this->player->moveBy(0,-5);
    if(MaTouche[3]==true && (player->pos().y()<700-50)) this->player->moveBy(0,5);
    if(MaTouche[4]==true && flagCadence==1){
        flagCadence=0;
        Tir *obus= new Tir();
        obus->setPos(x+20,y);
        scene->addItem(obus);

    }
    if(MaTouche[4]==false)
    {
        flagCadence=1;

    }
    if(MaTouche[5]==true){

        Sword *epee =new Sword();
        epee->setPos(x,y);
        scene->addItem(epee);

    }



}



