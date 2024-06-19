// glwidget.cpp
#include "glwidget.h"
#include <GL/glut.h>

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

void GLWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
}

void GLWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)w / h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glColor3f(1.0f, 0.5f, 0.5f);
    glTranslatef(0.0f, 0.0f, -5.0f);
    glutSolidTeapot(2.0);
}
