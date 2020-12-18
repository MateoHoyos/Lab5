#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <iostream>
#include <string>
#include <QPainter>
#include <QGraphicsItem>
#include <QRectF>
#include <QDesktopWidget>
#include <QDebug>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <conio.h>
#include <QMessageBox>


#include "pacman.h"
#include "pared.h"
#include "puntos.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QList<pared *> laberito;
    QList<puntos *> monedas;

private slots:  
    void mapa1();
    void mapa2();
    void mapa3();
    void funcionActivacionTimer();



private:

    void vidas();
    QTimer *cronometro=new QTimer(this);

    Ui::MainWindow *ui;

    QGraphicsScene *scene;
    pacman *Pacman;

    float x, y, ancho, alto;
    int puntajes = 0, contador=0, acomulado=30,life=3;

    void keyPressEvent(QKeyEvent *evento);
    QTimer *timerE;


};
#endif // MAINWINDOW_H
