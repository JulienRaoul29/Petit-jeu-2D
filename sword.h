#ifndef SWORD_H
#define SWORD_H
#include <QGraphicsRectItem>
#include <QPropertyAnimation>
#include <QObject>
#include <QTimer>
class Sword: public QObject,public QGraphicsRectItem
{
     Q_OBJECT
public:
    Sword();
public slots:
    void Move();
private:
    QPropertyAnimation *animation;
    QTimer * temps;
};

#endif // SWORD_H
