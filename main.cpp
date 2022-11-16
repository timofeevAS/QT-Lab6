#include <QWidget>
#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpinBox>
#include <QSlider>

#include <iostream>
#include <mywidgets.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QLabel *label  = new QLabel();

    MyWidgets my_wdgts;

    //QPushButton *btn1 = new QPushButton("Create Spinbox");
    //QPushButton *btn2 = new QPushButton("Create Scrollbar");
    //QPushButton *btn4 = new QPushButton("Create Slider");
    //QPushButton *btn5 = new QPushButton("Create Label");
    //QPushButton *btn3 = new QPushButton("Connect");


    //QVBoxLayout *vlay = new QVBoxLayout();
    //QHBoxLayout *hlay = new QHBoxLayout(label);
    //vlay->addWidget(btn1);
    //vlay->addWidget(btn2);
    //|vlay->addWidget(btn4);
    //vlay->addWidget(btn5);
   //vlay->addWidget(btn3);
    //hlay->addLayout(vlay);
    //MyWidgets::connect(btn1,SIGNAL(clicked()),&my_wdgts,SLOT(push_newSpinbox()));
    //MyWidgets::connect(btn2,SIGNAL(clicked()),&my_wdgts,SLOT(push_newScrollbar()));
    //MyWidgets::connect(btn4,SIGNAL(clicked()),&my_wdgts,SLOT(push_newSlider()));
    //MyWidgets::connect(btn5,SIGNAL(clicked()),&my_wdgts,SLOT(push_newLabel()));
    //MyWidgets::connect(btn3,SIGNAL(clicked()),&my_wdgts,SLOT(connect_Widgets()));


    //label->show();

    my_wdgts.show();

    return a.exec();
}
