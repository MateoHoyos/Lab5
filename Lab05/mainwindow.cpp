#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    x=0;
    y=0;
    ancho=1010;
    alto=500;
    scene=new QGraphicsScene(x,y,ancho,alto);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setStyleSheet("background-color:black;");

    Pacman =new pacman(100,100);
    scene->addItem(Pacman);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *evento){

    if(evento->key() == Qt::Key_A){
        Pacman->left();
        Pacman->orientacion(2);

    }

    if(evento->key() == Qt::Key_D){
        Pacman->right();
        Pacman->orientacion(0);

    }

    if(evento->key() == Qt::Key_W){
        Pacman->up();
        Pacman->orientacion(3);

    }

    if(evento->key() == Qt::Key_S){
        Pacman->down();
        Pacman->orientacion(1);

    }
}

