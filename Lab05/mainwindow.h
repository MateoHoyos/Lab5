#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QGraphicsItem>
#include <QRect>
#include <QtDebug>
#include <QGraphicsScene>
#include <QDesktopWidget>
#include <QKeyEvent>
#include <QTimer>

#include "pacman.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:

    Ui::MainWindow *ui;

    QGraphicsScene *scene;
    pacman *Pacman;

    float x, y, ancho, alto;

    void keyPressEvent(QKeyEvent *evento);
    QTimer *timerE;


};
#endif // MAINWINDOW_H
