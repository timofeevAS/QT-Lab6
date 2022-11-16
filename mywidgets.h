#ifndef MYWIDGETS_H
#define MYWIDGETS_H
#include <QWidget>
#include <QSpinBox>
#include <QScrollBar>
#include <QSlider>
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>
#include <QHBoxLayout>
#include <QMessageBox>
#include <vector>

class MyWidgets: public QWidget{
    Q_OBJECT
private:
    int spinbox_count=0,scrollbar_count=0,slider_count=0,label_count=0;

    QPushButton *btn_spinbox,*btn_scrollbar,*btn_slider,*btn_label,*btn_connect;

    QGridLayout *mainLayout;
    QWidget *widget;
    std::vector<QWidget*>vec_widgets;

    void remove_widget_by_type(QString s);

private slots:
    void push_newSpinbox();
    void push_newScrollbar();
    void push_newSlider();
    void push_newLabel();
    void connect_Widgets();

public:
    MyWidgets(QWidget *parent = 0);
    QWidget* get_topWidget();

    //void push_newWidget(QWidget& wdg);
};

#endif // MYWIDGETS_H
