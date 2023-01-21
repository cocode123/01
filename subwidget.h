#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QWidget>
#include <QPushButton>




class SubWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SubWidget(QWidget *parent = nullptr);
    ~SubWidget();
    void switchWindow1 ();//切换窗口
    void sendSignal();
    //QWidget* m_parent; //得到父窗口指针
int isub=4;
signals:
    void mySignal();//信号只需声明，无需定义
    void mySignal1(int, QString);
private:
    QPushButton bb;




};

#endif // SUBWIDGET_H
