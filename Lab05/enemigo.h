#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include <QDebug>

class enemigo: public QObject, public QGraphicsItem
{
public:
    enemigo(int x, int y);

    QTimer * timer;
    QPixmap * pixmap;

    float fila, columna;
    float ancho, alto;
    float posicion;

    int minimo=0,maximo=90;
    int velocidad_e = 3;
    int posx,posy;

    int getPosx() const;
    void setPosx(int px);
    int getPosy() const;
    void setPosy(int py);
    void orientacion(int);

    void up();
    void down();
    void left();
    void right();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

public slots:
    void actualizacion();
};

#endif // ENEMIGO_H
