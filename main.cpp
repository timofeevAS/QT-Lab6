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
    my_wdgts.show();

    return a.exec();
}
