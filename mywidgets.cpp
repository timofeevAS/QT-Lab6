#include "mywidgets.h"


MyWidgets::MyWidgets(QWidget *parent){
    //setFixedSize(500, 500);
    setWindowTitle("Connect Widgets");



    //QPushButton *btn1 = new QPushButton("Create Spinbox");
    //QPushButton *btn2 = new QPushButton("Create Scrollbar");
    //QPushButton *btn4 = new QPushButton("Create Slider");
    //QPushButton *btn5 = new QPushButton("Create Label");
    //QPushButton *btn3 = new QPushButton("Connect");

    btn_spinbox=new QPushButton("Create Spinbox");
    btn_scrollbar=new QPushButton("Create Scrollbar");
    btn_slider=new QPushButton("Create Slider");
    btn_label=new QPushButton("Create Label");
    btn_connect=new QPushButton("Connect");

    widget = new QWidget(this);
    mainLayout = new QGridLayout(this);
    mainLayout->setColumnMinimumWidth(1,400);
    //mainLayout->setRowStretch(1,100);

    mainLayout->addWidget(btn_spinbox,0,0);
    mainLayout->addWidget(btn_scrollbar,1,0);
    mainLayout->addWidget(btn_slider,2,0);
    mainLayout->addWidget(btn_label,3,0);
    mainLayout->addWidget(btn_connect,4,0);



    connect(btn_spinbox,SIGNAL(clicked()),this, SLOT(push_newSpinbox()));
    connect(btn_scrollbar,SIGNAL(clicked()),this, SLOT(push_newScrollbar()));
    connect(btn_slider,SIGNAL(clicked()),this, SLOT(push_newSlider()));
    connect(btn_label,SIGNAL(clicked()),this, SLOT(push_newLabel()));
    connect(btn_connect,SIGNAL(clicked()),this, SLOT(connect_Widgets()));


}


void MyWidgets::remove_widget_by_type(QString s){
    for(int i = 0;i < vec_widgets.size();i++){
        if(vec_widgets[i]->metaObject()->className()==s){
            delete vec_widgets[i];
            vec_widgets.erase(vec_widgets.begin()+i);
        }
    }
}

void MyWidgets::push_newSpinbox(){
    if(spinbox_count){
        QSpinBox *a = new QSpinBox;
        remove_widget_by_type(a->metaObject()->className());
        delete a;
        spinbox_count = 0;
        btn_spinbox->setText("Create Spinbox");
        return;
    }
    vec_widgets.push_back(new QSpinBox);
    QHBoxLayout *tmp = new QHBoxLayout; // ВИДИМО ОН НЕ УДАЛЯЕТ!????????
    tmp->addWidget(vec_widgets.back());
    mainLayout->addLayout(tmp,0,++spinbox_count);
    btn_spinbox->setText("Remove Spinbox");
}

void MyWidgets::push_newScrollbar(){
    if(scrollbar_count){
        QScrollBar *a = new QScrollBar;
        remove_widget_by_type(a->metaObject()->className());
        delete a;
        scrollbar_count = 0;
         btn_scrollbar->setText("Create Scrollbar");
        return;
    }
    vec_widgets.push_back(new QScrollBar(Qt::Horizontal));
    QHBoxLayout *tmp = new QHBoxLayout;
    tmp->addWidget(vec_widgets.back());
    mainLayout->addLayout(tmp,1,++scrollbar_count);
    btn_scrollbar->setText("Remove Scrollbar");
}

void MyWidgets::push_newSlider(){
    if(slider_count){
        QSlider *a = new QSlider;
        remove_widget_by_type(a->metaObject()->className());
        delete a;
        slider_count = 0;
        btn_slider->setText("Create Slider");
        return;
    }
    vec_widgets.push_back(new QSlider(Qt::Horizontal));
    QHBoxLayout *tmp = new QHBoxLayout;
    tmp->addWidget(vec_widgets.back());
    mainLayout->addLayout(tmp,2,++slider_count);
    btn_slider->setText("Remove Slider");
}

void MyWidgets::push_newLabel(){
    if(label_count){
        QLabel *a = new QLabel();
        remove_widget_by_type(a->metaObject()->className());
        delete a;
        label_count = 0;
        btn_label->setText("Create Label");
        return;
    }

    vec_widgets.push_back(new QLabel("0"));
    QHBoxLayout *tmp = new QHBoxLayout;
    tmp->addWidget(vec_widgets.back());
    mainLayout->addLayout(tmp,3,++label_count);
    btn_label->setText("Remove Label");
}



void MyWidgets::connect_Widgets(){
    /*for(int i = 0;i<this->vec_widgets.size()-1;i++){
        if(vec_widgets[i]->metaObject()->className()==QString("QLabel")){
            connect(vec_widgets.back(),SIGNAL(valueChanged(int)),vec_widgets[i],SLOT(setNum(int)));
        }
        else if(vec_widgets.back()->metaObject()->className()==QString("QLabel")){
            connect(vec_widgets[i],SIGNAL(valueChanged(int)),vec_widgets.back(),SLOT(setNum(int)));
        }
        else{

         connect(vec_widgets[i],SIGNAL(valueChanged(int)),vec_widgets.back(),SLOT(setValue(int)));
         connect(vec_widgets.back(),SIGNAL(valueChanged(int)),vec_widgets[i],SLOT(setValue(int)));
        }
    }
    */

    if(vec_widgets.size()<=1){
        QMessageBox *msgBox = new QMessageBox(QMessageBox::Warning,QString("WARNING!"),QString("You didn't match one more widgets!"));
        msgBox->show();
        return;
    }


    for(int i = 0; i<vec_widgets.size()-1;i++){
        for(int j = i+1;j<vec_widgets.size();j++){
            if(vec_widgets[i]->metaObject()->className()==QString("QLabel")){
                connect(vec_widgets[j],SIGNAL(valueChanged(int)),vec_widgets[i],SLOT(setNum(int)));

            }
            else if(vec_widgets[j]->metaObject()->className()==QString("QLabel")){
                connect(vec_widgets[i],SIGNAL(valueChanged(int)),vec_widgets[j],SLOT(setNum(int)));
            }
            else{
                connect(vec_widgets[i],SIGNAL(valueChanged(int)),vec_widgets[j],SLOT(setValue(int)));
                connect(vec_widgets[j],SIGNAL(valueChanged(int)),vec_widgets[i],SLOT(setValue(int)));
            }
        }
    }

}

QWidget* MyWidgets::get_topWidget(){
    return (this->vec_widgets.back());
}
