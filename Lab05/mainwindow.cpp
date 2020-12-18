#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qtimer.h>
#include "qdatetime.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(cronometro, SIGNAL(timeout()), this, SLOT(funcionActivacionTimer()));
    cronometro->start(1000);



    QRect desktop = QApplication::desktop()->screenGeometry();
    x = desktop.x();
    y = desktop.y();
    ancho=500;
    alto=500;
    scene=new QGraphicsScene(x,y,ancho,alto);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setStyleSheet("background-color:black;");


    ui->puntos->setText("Puntaje: " + QString::number(puntajes));
    ui->vida->setText("Vidas: " + QString::number(life));


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


void MainWindow::funcionActivacionTimer(){
    ui->lcdNumber->display(acomulado);
    acomulado--;
    if(acomulado==-1){
        life--;
        ui->vida->setText("Vidas: " + QString::number(life));
        if(life==0){
            ui->puntos->setText("Puntaje: " + QString::number(puntajes));
            QMessageBox::about (this,":c" , "\nPerdiste");
            mapa1();
        }
        acomulado=30;
    }
}

void MainWindow::vidas()
{

}




void MainWindow::mapa1()
{

    acomulado=30;
    life=3;
    ui->vida->setText("Vidas: " + QString::number(life));

    laberito.clear();
    monedas.clear();
    puntajes=0;
    QRect desktop = QApplication::desktop()->screenGeometry();
    x = desktop.x();
    y = desktop.y();
    ancho=500;
    alto=500;
    scene=new QGraphicsScene(x,y,ancho,alto);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setStyleSheet("background-color:black;");



    ui->puntos->setText("Puntaje: " + QString::number(puntajes));


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


    //mapa 1
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

void MainWindow::mapa2()
{
    //acomulado+=puntajes;
    //ui->total->setText("Total: " + QString::number(acomulado));

    laberito.clear();
    monedas.clear();
   // puntajes=0;
    QRect desktop = QApplication::desktop()->screenGeometry();
    x = desktop.x();
    y = desktop.y();
    ancho=500;
    alto=500;
    scene=new QGraphicsScene(x,y,ancho,alto);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setStyleSheet("background-color:black;");



    ui->puntos->setText("Puntaje: " + QString::number(puntajes));


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


    //mapa 2
    laberito.push_back(new pared(1500, 30, -5, -5)); scene->addItem(laberito.back());
    laberito.push_back(new pared(1500, 30, 0, 430)); scene->addItem(laberito.back());
    laberito.push_back(new pared(30, 1010, 475, -5)); scene->addItem(laberito.back());
    laberito.push_back(new pared(30, 1010, -7, -5)); scene->addItem(laberito.back());


      laberito.push_back(new pared(60, 60, 70, 70)); scene->addItem(laberito.back());
      laberito.push_back(new pared(60, 60, 230, 30)); scene->addItem(laberito.back());
      laberito.push_back(new pared(60, 60, 390, 70)); scene->addItem(laberito.back());
      laberito.push_back(new pared(60, 60, 40, 230)); scene->addItem(laberito.back());
      laberito.push_back(new pared(60, 60, 150, 150)); scene->addItem(laberito.back());
      laberito.push_back(new pared(60, 60, 310, 150)); scene->addItem(laberito.back());
      laberito.push_back(new pared(60, 60, 230, 310)); scene->addItem(laberito.back());
      laberito.push_back(new pared(60, 60, 70, 350)); scene->addItem(laberito.back());
      laberito.push_back(new pared(60, 60, 390, 350)); scene->addItem(laberito.back());
      laberito.push_back(new pared(60, 60, 320, 270)); scene->addItem(laberito.back());

}




void MainWindow::mapa3()
{

    //acomulado+=puntajes;
    //ui->total->setText("Total: " + QString::number(acomulado));

    laberito.clear();
    monedas.clear();
    //puntajes=0;
    QRect desktop = QApplication::desktop()->screenGeometry();
    x = desktop.x();
    y = desktop.y();
    ancho=500;
    alto=500;
    scene=new QGraphicsScene(x,y,ancho,alto);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setStyleSheet("background-color:black;");



    ui->puntos->setText("Puntaje: " + QString::number(puntajes));


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


    //mapa 3
    laberito.push_back(new pared(1500, 30, -5, -5)); scene->addItem(laberito.back());
    laberito.push_back(new pared(1500, 30, 0, 430)); scene->addItem(laberito.back());
    laberito.push_back(new pared(30, 1010, 475, -5)); scene->addItem(laberito.back());
    laberito.push_back(new pared(30, 1010, -7, -5)); scene->addItem(laberito.back());

    laberito.push_back(new pared(20, 310, 70, 60)); scene->addItem(laberito.back());
    laberito.push_back(new pared(20, 150, 150, 260)); scene->addItem(laberito.back());
    laberito.push_back(new pared(30, 30, 110, 260)); scene->addItem(laberito.back());
    laberito.push_back(new pared(65, 65, 230, 260)); scene->addItem(laberito.back());
    laberito.push_back(new pared(65, 65, 350, 300)); scene->addItem(laberito.back());
    laberito.push_back(new pared(20, 110, 150, 30)); scene->addItem(laberito.back());
    laberito.push_back(new pared(20, 110, 230, 30)); scene->addItem(laberito.back());

    laberito.push_back(new pared(310, 30, 150, 180)); scene->addItem(laberito.back());
    laberito.push_back(new pared(160, 30, 260, 110)); scene->addItem(laberito.back());
    laberito.push_back(new pared(30, 30, 310, 30)); scene->addItem(laberito.back());
    laberito.push_back(new pared(30, 30, 390, 60)); scene->addItem(laberito.back());


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
               acomulado=30;
               scene->removeItem(monedas.at(i));
               monedas.removeAt(i);
               puntajes++;
               ui->puntos->setText("Puntaje: " + QString::number(puntajes));

           }
       }


        if(puntajes>=68&&contador==0){ //68 puntos
            mapa2();
            contador=1;
        }

        if(puntajes>=137&&contador==1){ //69 puntos
            mapa3();
            contador=2;
        }

        if (puntajes>=205&&contador==2){
            ui->puntos->setText("Puntaje: " + QString::number(puntajes));
            QMessageBox::about (this,":v" , "\nWIN");
            mapa1();
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
                acomulado=30;
                scene->removeItem(monedas.at(i));
                monedas.removeAt(i);
                puntajes++;
                ui->puntos->setText("Puntaje: " + QString::number(puntajes));

            }
        }

        if(puntajes>=68&&contador==0){ //68 puntos
            mapa2();
            contador=1;
        }

        if(puntajes>=137&&contador==1){ //69 puntos
            mapa3();
            contador=2;
        }

        if (puntajes>=205&&contador==2){
            ui->puntos->setText("Puntaje: " + QString::number(puntajes));
            QMessageBox::about (this,":v" , "\nWIN");
            mapa1();
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
                  acomulado=30;
                  scene->removeItem(monedas.at(i));
                  monedas.removeAt(i);
                  puntajes++;
                  ui->puntos->setText("Puntaje: " + QString::number(puntajes));
              }
          }


        if(puntajes>=68&&contador==0){ //68 puntos
            mapa2();
            contador=1;
        }

        if(puntajes>=137&&contador==1){ //69 puntos
            mapa3();
            contador=2;
        }

        if (puntajes>=205&&contador==2){
            ui->puntos->setText("Puntaje: " + QString::number(puntajes));
            QMessageBox::about (this,":v" , "\nWIN");
            mapa1();
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

                   acomulado=30;
                   scene->removeItem(monedas.at(i));
                   monedas.removeAt(i);
                   puntajes++;
                   ui->puntos->setText("Puntaje: " + QString::number(puntajes));
               }
           }

        if(puntajes>=68&&contador==0){ //68 puntos
            mapa2();
            contador=1;
        }

        if(puntajes>=137&&contador==1){ //69 puntos
            mapa3();
            contador=2;
        }

        if (puntajes>=205&&contador==2){
            ui->puntos->setText("Puntaje: " + QString::number(puntajes));
            QMessageBox::about (this,":v" , "\nWIN");
            mapa1();
        }

    }
}




