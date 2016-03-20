#include "window.h"

#include <QGLFormat>
#include <iostream>
#include <string>

Window::Window() {
    QGLFormat glFormat;
    glFormat.setVersion(3, 3);
    glFormat.setProfile(QGLFormat::CompatibilityProfile);
    glFormat.setSampleBuffers(true);
    this->setFormat(glFormat);

    this->resize(800, 600);

    this->timer_ = new QTimer(this);
    this->connect(this->timer_, SIGNAL(timeout()), this, SLOT(update()));
    this->timer_->start(20);

    this->world_ = new World(this);


}

Window::~Window() {  }

void Window::initializeGL() {
    this->world_->initialize();
}

void Window::resizeGL(int w, int h) {
}

void Window::paintGL() {
    this->world_->update();
}

void Window::keyPressEvent(QKeyEvent *e) {
}
