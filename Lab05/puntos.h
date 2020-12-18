#ifndef PUNTOS_H
#define PUNTOS_H

#include <QGraphicsItem>
#include <QPainter>

class puntos: public QGraphicsItem
{
    int r;
    int posx, posy;
    int velocidad = 5;
public:
    puntos(int r_, int x, int y);


    int getR() const;
    void setR(int radio);
    int getPosx() const;
    void setPosx(int px);
    int getPosy() const;
    void setPosy(int py);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};

#endif // PUNTOS_H
