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




       laberito.push_back(new pared(1500, 30, -5, -5)); scene->addItem(laberito.back());
       laberito.push_back(new pared(30, 1010, -7, -5)); scene->addItem(laberito.back());
       laberito.push_back(new pared(1500, 30, -5, 480)); scene->addItem(laberito.back());
       laberito.push_back(new pared(30, 1010, 480, -5)); scene->addItem(laberito.back());


        laberito.push_back(new pared(30, 150, 60, 60)); scene->addItem(laberito.back());
        laberito.push_back(new pared(30, 190, 60, 250)); scene->addItem(laberito.back());

        laberito.push_back(new pared(150, 30, 90, 60)); scene->addItem(laberito.back());
        laberito.push_back(new pared(180, 30, 300, 60)); scene->addItem(laberito.back());
        laberito.push_back(new pared(30, 190, 130, 130)); scene->addItem(laberito.back());

        laberito.push_back(new pared(150, 30, 160, 130)); scene->addItem(laberito.back());
        laberito.push_back(new pared(150, 30, 130, 360)); scene->addItem(laberito.back());

        laberito.push_back(new pared(150, 10, 130, 430)); scene->addItem(laberito.back());
        laberito.push_back(new pared(10,  50, 130, 430)); scene->addItem(laberito.back());

        laberito.push_back(new pared(100, 100, 210, 220)); scene->addItem(laberito.back());

        laberito.push_back(new pared(30, 120, 340, 360)); scene->addItem(laberito.back());
        laberito.push_back(new pared(10, 250, 420, 150)); scene->addItem(laberito.back());
        laberito.push_back(new pared(10, 220, 350, 90)); scene->addItem(laberito.back());





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

    }




    if(evento->key() == Qt::Key_D){
        Pacman->right();
        Pacman->orientacion(0);

        for (int i = 0;i < laberito.size();i++){
            if(Pacman->collidesWithItem(laberito.at(i))){
                Pacman->left();
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

    }






    if(evento->key() == Qt::Key_S){
        Pacman->down();
        Pacman->orientacion(1);

        for (int i = 0;i < laberito.size();i++){
            if(Pacman->collidesWithItem(laberito.at(i))){
                Pacman->up();
            }
        }

    }
}

