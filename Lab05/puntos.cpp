#include "puntos.h"

puntos::puntos(int r_, int x, int y)
{
    r = r_;
    posx = x;
    posy = y;
    setPos(posx,posy);
}
int puntos::getR() const
{
    return r;
}

void puntos::setR(int value)
{
    r = value;
}

int puntos::getPosx() const
{
    return posx;
}

void puntos::setPosx(int value)
{
    posx = value;
}

int puntos::getPosy() const
{
    return posy;
}

void puntos::setPosy(int value)
{
    posy = value;
}

QRectF puntos::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r);
}

void puntos::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::yellow);
    painter->drawEllipse(boundingRect());

}
