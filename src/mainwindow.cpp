// mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //设置用户界面，根据 ui_mainwindow.h 中定义的UI布局来配置窗口的小部件和布局
    ui->setupUi(this);
    //创建一个新的 GLWidget 对象，并将 this 传递给它作为父窗口
    glWidget = new GLWidget(this);
    //将 glWidget 设置为主窗口的中央小部件
    setCentralWidget(glWidget);
}

MainWindow::~MainWindow()
{
    //删除 ui 指针所指向的对象，释放其占用的内存
    delete ui;
}
