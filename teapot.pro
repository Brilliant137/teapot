#使用模块
QT       += core gui
QT       += widgets opengl
QT       += core gui widgets
#外部链接库OpenGL\GLU\GLUT
LIBS      += -lGL -lGLU -lglut

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
#使用C++11标准
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#项目文件位置
SOURCES += \
    src/glwidget.cpp \
    src/main.cpp \
    src/mainwindow.cpp

HEADERS += \
    src/glwidget.h \
    src/mainwindow.h \
    src/ui_mainwindow.h

# Default rules for deployment.
target.path = /usr/bin

desktop.path = /usr/share/applications/
desktop.files = $$PWD/src/install/teapot.desktop    #$$PWD是一个内置变量，表示当前文件所在目录路径

icon.path = /usr/share/icons
icon.files= $$PWD/src/icons/teapot.png

#添加安装规则
!isEmpty(target.path): INSTALLS += target desktop icon


