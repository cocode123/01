#include "subwidget.h"


SubWidget::SubWidget(QWidget *parent) : QWidget(parent)
{
        //setAttribute(Qt::WA_QuitOnClose,false);
    bb.setParent(this);
    bb.setText("切换到主窗口");

    //connect(&bb,&QPushButton::pressed,this,&SubWidget::switchWindow1);
    //发送信号
    connect(&bb,&QPushButton::clicked,this,&SubWidget::sendSignal);//按钮事件触发了发送信号的槽函数
    resize(400,300);
}
void SubWidget::sendSignal(){
    //emit mySignal();
    emit mySignal1(250,"这里是子窗口");
}
//void SubWidget::switchWindow1(){
    //子窗口隐藏
  //   this->hide();
    //MAIN窗口显示  信号和槽
    //this->m_parent->show();


//}
SubWidget::~SubWidget(){

}
