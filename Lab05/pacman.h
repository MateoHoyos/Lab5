#ifndef PACMAN_H
#define PACMAN_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include <QDebug>

class pacman : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    pacman(int x, int y);

    QTimer * timer;
    QPixmap * pixmap;

    float fila, columna;
    float ancho, alto;
    float posicion;
    int minimo=0,maximo=90;
    int velocidad = 6;
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


#endif // PACMAN_H
