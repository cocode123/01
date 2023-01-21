#include "widget.h"
#include "ui_widget.h"
#include <QDebug>


Widget::Widget(QWidget *parent):QWidget(parent),ui(new Ui::Widget)
{//Widget这个类的构造函数，接着是初始化列表给数据成员赋初值


    ui->setupUi(this);
    //QPushButton b1;//这里创建的对象不显示 要在头文件中创建，构造函数生命周期短暂
    b1.setParent(this);
    b1.setText("切换到子窗口");
    b1.show();

    b2=new QPushButton(this);
    b2->setText(" = =");
    b2->move(200,200);

    b2->show();
   // connect(&b1,&QPushButton::pressed,this,&Widget::close);//b1信号发出端，本类的构造函数的对象this是接收端
               //信号的发出者指针类型   &发出者类名：：信号的名字（信号处理函数）     &接收者类名：：执行的动作（槽函数）
    //自定义槽
    //connect(b2,&QPushButton::released,this,&Widget::myslot);//myslot()可以是类成员函数，普通函数，静态函数

    //connect(&b1,&QPushButton::released,&b1,&QPushButton::hide);

    //两个独立窗口
    //connect(&b1,&QPushButton::released,&w1,&Widget::show);//数据成员有个Widget对象，这个对象有自己的成员函数show（）
    //两个独立窗口
    //w1.m_parent=this;
    connect(&b1,&QPushButton::released,this,&Widget::switchWindow);

    //接收到信号，触发槽函数显示主窗口，隐藏子窗口
    void (SubWidget::*Signal)(int,QString)=&SubWidget::mySignal1;//函数指针，信号函数重载时可以用来区分
    connect(&w1,Signal,this,&Widget::switchWindow2);
    resize(400,300);

    //langda表达式
    int ival1=5;
    int& ival=ival1;
    connect(b2,&QPushButton::clicked,
            [=](bool cli) //信号传参clicked(bool check=false)
            mutable //局部变量的值可改变
            { // = 表示外部所有局部变量   类的数据成员都可以在函数体以值传递访问
                    // this  类的数据成员都可以在函数体值传递访问
                    // & 引用  把外部所有局部变量以引用的方式传进来
                b2->setText("123");
                qDebug()<<"111111111"<<endl;

                qDebug()<<ia++<<ival++<<cli;

    }
            );
}


void Widget::myslot(){
     b2->setText("caohanshu");
}
void Widget::switchWindow(){
    //本窗口隐藏
    hide();
    //子窗口显示
    w1.show();

}
void Widget::switchWindow2(int a,QString str){
   //this->show();
   // w1.hide();
    qDebug()<<a<<str.toUtf8().data();
}
Widget::~Widget()
{
    delete ui;
}

