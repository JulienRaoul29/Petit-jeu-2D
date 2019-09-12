#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QPropertyAnimation>
#include <QKeyEvent>
#include <QDebug>
#include <QTimer>

class MainWindow : public QGraphicsView
{
    Q_OBJECT
public:
    MainWindow();
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private:
    QGraphicsScene *scene;
    QPropertyAnimation *animation;
public:
QGraphicsRectItem *player;
//QGraphicsRectItem *tir;
bool MaTouche[6];
int flagCadence=0;

signals:

public slots:
 void mouvement();

private slots:


};

#endif // MAINWINDOW_H
