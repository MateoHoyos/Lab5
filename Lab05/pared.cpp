#include "pared.h"


QRectF pared::boundingRect() const {
    return QRectF(0, 0, 25, 25);
}

pared::pared(short x, short y, short type) {

    if (type == 3) {
        image = new QPixmap(":/imagenes/pared.png");
        *image = image->transformed(QTransform().translate(-13, -13).rotate(90).translate(13, 13));
    }
    else if (type == 4) image = new QPixmap(":/imagenes/pared.png");
    else image = new QPixmap(":/imagenes/empty.png");

    setPixmap(*image);
    setPos(x, y);
}








/*
pared::pared(int w_, int h_, int x, int y)
{
    w=w_;
    h=h_;
    posx=x;
    posy=y;

}

QRectF pared::boundingRect() const
{
    return QRectF(-posx,-posy,w,h);
}

void pared::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::blue);
    painter->drawRect(boundingRect());
}
*/
