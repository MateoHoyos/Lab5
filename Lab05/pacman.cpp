#include "pacman.h"

pacman::pacman(int x, int y)
{
    posx = x;
    posy = y;
    setPos(posx,posy);
    timer = new QTimer();
    fila = 0;
    columna =510;
    pixmap =new QPixmap(":/imagenes/Pacmandeff.png");
    ancho=30;
    alto=30;
    timer->start(100);
    connect(timer,&QTimer::timeout,this,&pacman::actualizacion);
}


void pacman::orientacion(int num)
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

int pacman::getPosx() const
{
    return posx;
}

void pacman::setPosx(int px)
{
    posx=px;
}

int pacman::getPosy() const
{
    return posy;
}

void pacman::setPosy(int py)
{
    posy=py;
}

void pacman::up()
{
    posy-=velocidad;
    setPos(posx,posy);
}

void pacman::down()
{
    posy+=velocidad;
    setPos(posx,posy);
}

void pacman::left()
{
    posx-=velocidad;
    setPos(posx,posy);
}

void pacman::right()
{
    posx+=velocidad;
    setPos(posx,posy);
}


void pacman::actualizacion()
{
    fila +=30;
    if(fila>=maximo){
        fila=minimo;
    }
    this->update(-ancho/2,-alto/2,ancho,alto);
}

QRectF pacman::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void pacman::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,columna,fila,ancho,alto);
}
