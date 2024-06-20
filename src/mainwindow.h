// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>      //用于创建主窗口的Qt类
#include "glwidget.h"

//UI命名空间的定义
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow(QWidget* parent = nullptr);
        ~MainWindow();

    private:
        Ui::MainWindow* ui;     //指向由Qt的UI工具生成的用户界面对象
        GLWidget* glWidget;     //指向我们之前定义的 GLWidget 对象，用于在主窗口中显示OpenGL内容
};

#endif // MAINWINDOW_H
