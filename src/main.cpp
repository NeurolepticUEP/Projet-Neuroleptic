#include "gl_include.h"

#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>

#include <QApplication>
#include <QGLFormat>

#include "window.h"

int main(int argc, char *argv[]) {
    QApplication application(argc, argv);

    Window window;
    window.show();


    return application.exec();
}
