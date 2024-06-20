// glwidget.cpp
#include "glwidget.h"
#include <GL/glut.h>

//接受一个指向 QWidget 的指针作为父窗口，并传递给 QOpenGLWidget 的构造函数
GLWidget::GLWidget(QWidget* parent) : QOpenGLWidget(parent)
{
    //Initialize GlUT(noly once)
    static bool glutInitialized = false;
    if(!glutInitialized){
        int argc = 1;
        char *argv[1] = {(char*)"something"};
        glutInit(&argc,argv);
        glutInitialized = true;
    }
}

GLWidget::~GLWidget()
{
}

//初始化OpenGL状态
void GLWidget::initializeGL()
{
    initializeOpenGLFunctions();
    //设置清除颜色为黑色
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
}

//用于在窗口大小改变时调整视口和投影矩阵
void GLWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)w / h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

//用于绘制OpenGL场景
void GLWidget::paintGL()
{
    //清除颜色缓冲区和深度缓冲区
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //重置当前矩阵
    glLoadIdentity();
    //置观察矩阵，定义相机的位置和方向
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    //设置绘制颜色为粉红色
    glColor3f(1.0f, 0.5f, 0.5f);
    //平移当前矩阵，使物体向屏幕内移动5个单位
    glTranslatef(0.0f, 0.0f, -5.0f);
    //绘制一个实心茶壶，尺寸为2个单位
    glutSolidTeapot(2.0);
}
