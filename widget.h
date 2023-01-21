#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include "subwidget.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    //自定义槽函数
    void myslot();
    void switchWindow();
    void switchWindow2(int a,QString str);

private:
    Ui::Widget *ui;
    QPushButton b1;

    QPushButton *b2;
    //QWidget w1;
    SubWidget w1;
    //SubWidget w3;
    int ia=1;
};
#endif // WIDGET_H
