#include "enemigo.h"

enemigo::enemigo(int x, int y)
{
    posx = x;
    posy = y;
    setPos(posx,posy);
    timer = new QTimer();
    fila = 0;
    columna =30;
    pixmap =new QPixmap(":/imagenes/Pacmandeff.png");
    ancho=30;
    alto=30;
    timer->start(100);
    connect(timer,&QTimer::timeout,this,&enemigo::actualizacion);
}


void enemigo::orientacion(int num)
{
    switch (num) {
        case 0:
            minimo=0;
            maximo=90;
            fila=minimo;
        break;
        case 1:
            minimo=90;
            maximo=180;
            fila=minimo;
        break;
        case 2:
            minimo=180;
            maximo=270;
            fila=minimo;
        break;
        case 3:
            minimo=270;
            maximo=360;
            fila=minimo;
        break;
   }
}

int enemigo::getPosx() const
{
    return posx;
}

void enemigo::setPosx(int px)
{
    posx=px;
}

int enemigo::getPosy() const
{
    return posy;
}

void enemigo::setPosy(int py)
{
    posy=py;
}

void enemigo::up()
{
    posy-=velocidad_e;
    setPos(posx,posy);
}

void enemigo::down()
{
    posy+=velocidad_e;
    setPos(posx,posy);
}

void enemigo::left()
{
    posx-=velocidad_e;
    setPos(posx,posy);
}

void enemigo::right()
{
    posx+=velocidad_e;
    setPos(posx,posy);
}


void enemigo::actualizacion()
{
    fila +=30;
    if(fila>=maximo){
        fila=minimo;
    }
    this->update(-ancho/2,-alto/2,ancho,alto);
}

QRectF enemigo::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void enemigo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,columna,fila,ancho,alto);
}
