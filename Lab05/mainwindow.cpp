#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QRect desktop = QApplication::desktop()->screenGeometry();
    x = desktop.x();
    y = desktop.y();
    ancho=500;
    alto=500;
    scene=new QGraphicsScene(x,y,ancho,alto);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setStyleSheet("background-color:black;");


    Pacman =new pacman(40,40);
    scene->addItem(Pacman);


    //puntos

    for (int i = 85; i < 600 ; i+= 40){
            monedas.push_back(new puntos(4,i,40));scene->addItem(monedas.back());
     }

    for (int a = 80; a < 600 ; a+= 40){

        for (int i = 45; i < 600 ; i+= 40){
            monedas.push_back(new puntos(4,i,a));scene->addItem(monedas.back());
        }
    }



    //laberito

    laberito.push_back(new pared(1500, 30, -5, -5)); scene->addItem(laberito.back());
    laberito.push_back(new pared(1500, 30, 0, 430)); scene->addItem(laberito.back());
    laberito.push_back(new pared(30, 1010, 475, -5)); scene->addItem(laberito.back());
    laberito.push_back(new pared(30, 1010, -7, -5)); scene->addItem(laberito.back());


    laberito.push_back(new pared(30, 150, 70, 60)); scene->addItem(laberito.back());
    laberito.push_back(new pared(30, 125, 70, 260)); scene->addItem(laberito.back());
    laberito.push_back(new pared(30, 125, 150, 300)); scene->addItem(laberito.back());
    laberito.push_back(new pared(30, 120, 310, 310)); scene->addItem(laberito.back());
    laberito.push_back(new pared(30, 125, 230, 260)); scene->addItem(laberito.back());
    laberito.push_back(new pared(30, 280, 390, 90)); scene->addItem(laberito.back());

    laberito.push_back(new pared(150, 30, 100, 60)); scene->addItem(laberito.back());
    laberito.push_back(new pared(150, 30, 310, 60)); scene->addItem(laberito.back());

    laberito.push_back(new pared(60, 60, 150, 150)); scene->addItem(laberito.back());
    laberito.push_back(new pared(30, 40, 150, 210)); scene->addItem(laberito.back());

    laberito.push_back(new pared(60, 60, 280, 150)); scene->addItem(laberito.back());
    laberito.push_back(new pared(30, 40, 310, 210)); scene->addItem(laberito.back());





}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *evento){

    if(evento->key() == Qt::Key_A){
        Pacman->left();
        Pacman->orientacion(2);

        for (int i = 0;i < laberito.size();i++) {
            if(Pacman->collidesWithItem(laberito.at(i))){
                Pacman->right();
            }
        }


        for (int i = 0;i < monedas.size();i++) {
           if(Pacman->collidesWithItem(monedas.at(i))){
               scene->removeItem(monedas.at(i));
               monedas.removeAt(i);
               puntajes = puntajes+1;

           }
       }

    }




    if(evento->key() == Qt::Key_D){
        Pacman->right();
        Pacman->orientacion(0);

        for (int i = 0;i < laberito.size();i++){
            if(Pacman->collidesWithItem(laberito.at(i))){
                Pacman->left();
            }
        }



        for (int i = 0;i < monedas.size();i++) {
            if(Pacman->collidesWithItem(monedas.at(i))){
                scene->removeItem(monedas.at(i));
                monedas.removeAt(i);

            }
        }



    }






    if(evento->key() == Qt::Key_W){
        Pacman->up();
        Pacman->orientacion(3);

        for (int i = 0;i < laberito.size();i++){
            if(Pacman->collidesWithItem(laberito.at(i))){
                Pacman->down();
            }
        }



        for (int i = 0;i < monedas.size();i++) {
              if(Pacman->collidesWithItem(monedas.at(i))){
                  scene->removeItem(monedas.at(i));
                  monedas.removeAt(i);
              }
          }

    }






    if(evento->key() == Qt::Key_S){
        Pacman->down();
        Pacman->orientacion(1);

        for (int i = 0;i < laberito.size();i++){
            if(Pacman->collidesWithItem(laberito.at(i))){
                Pacman->up();
            }
        }


        for (int i = 0;i < monedas.size();i++) {
               if(Pacman->collidesWithItem(monedas.at(i))){
                   scene->removeItem(monedas.at(i));
                   monedas.removeAt(i);
               }
           }

    }
}


