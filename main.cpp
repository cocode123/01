#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    int ib=3;
    Widget w;
    w.show();
    Widget x;
    //����1 
    // 
    //x.show();
    return a.exec();
}
