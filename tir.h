#ifndef TIR_H
#define TIR_H
#include <QGraphicsRectItem>
#include <QObject>
class Tir : public QObject,public QGraphicsRectItem
{
    Q_OBJECT
    public:
        Tir();
    public slots:
        void move();

};

#endif // TIR_H
