/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QLabel *puntos;
    QLabel *vida;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *tiempo;
    QLCDNumber *lcdNumber;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(522, 500);
        QFont font;
        font.setFamily(QStringLiteral("Comic Sans MS"));
        MainWindow->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/imagenes/v.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 40, 502, 502));
        puntos = new QLabel(centralwidget);
        puntos->setObjectName(QStringLiteral("puntos"));
        puntos->setGeometry(QRect(210, 0, 131, 29));
        QFont font1;
        font1.setFamily(QStringLiteral("Comic Sans MS"));
        font1.setPointSize(16);
        font1.setBold(false);
        font1.setWeight(50);
        puntos->setFont(font1);
        vida = new QLabel(centralwidget);
        vida->setObjectName(QStringLiteral("vida"));
        vida->setGeometry(QRect(390, 0, 91, 29));
        vida->setFont(font1);
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 0, 147, 31));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        tiempo = new QLabel(widget);
        tiempo->setObjectName(QStringLiteral("tiempo"));
        tiempo->setFont(font1);

        horizontalLayout->addWidget(tiempo);

        lcdNumber = new QLCDNumber(widget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));

        horizontalLayout->addWidget(lcdNumber);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 522, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "PAC-MAN", Q_NULLPTR));
        puntos->setText(QApplication::translate("MainWindow", "Puntaje:", Q_NULLPTR));
        vida->setText(QApplication::translate("MainWindow", "Vidas:", Q_NULLPTR));
        tiempo->setText(QApplication::translate("MainWindow", "Tiempo:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
