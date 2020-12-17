#ifndef PARED_H
#define PARED_H
#include <QGraphicsItem>
#include <QPainter>

#include <QGraphicsPixmapItem>
class pared: public QGraphicsPixmapItem //herencia
{
    //int w,h;
    //int posx, posy;

    QPixmap *image;
    QRectF boundingRect() const;
public:
    pared(short x, short y,short type);

    ~pared() {
        delete image;
    };

    //QRectF boundingRect() const;
    //void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};

#endif // PARED_H
