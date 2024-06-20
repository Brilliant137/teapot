// glwidget.h
#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>    //用于显示OpenGL内容的Qt窗口小部件
#include <QOpenGLFunctions>     //提供了一组跨平台的OpenGL函数

//定义了一个名为 GLWidget 的类，继承自 QOpenGLWidget 和 QOpenGLFunctions。
class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    //Q_OBJECT 宏是所有使用Qt元对象系统的类所需的宏，它支持信号和槽机制、属性系统等。
    Q_OBJECT

    public:
        //构造函数 GLWidget 接受一个指向 QWidget 的指针作为父窗口，默认值为 nullptr
        explicit GLWidget(QWidget* parent = nullptr);
        //析构函数 ~GLWidget 用于清理资源
        ~GLWidget();

    protected:
        //在OpenGL上下文创建并初始化后调用，用于初始化OpenGL状态
        void initializeGL() override;
        //在窗口大小改变时调用，用于设置视口或投影矩阵
        void resizeGL(int w, int h) override;
        //在需要重绘窗口内容时调用，用于绘制OpenGL场景
        void paintGL() override;
};

#endif // GLWIDGET_H
