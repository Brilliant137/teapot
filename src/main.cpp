#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //创建与显示窗口
    MainWindow w;
    w.show();
    return a.exec();
}
