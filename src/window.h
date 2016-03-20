#ifndef WINDOW_H
#define WINDOW_H


#include <QKeyEvent>
#include <QTimer>

#include "engine_class/world.h"

#include <QtOpenGL/QGLWidget>

class Engine_Graphic;
class Engine_Interaction;

class Window : public QGLWidget {
    Q_OBJECT
public:
    Window();
    virtual ~Window();

    virtual void initializeGL();
    virtual void resizeGL(int w, int h);
    virtual void paintGL();

    void keyPressEvent(QKeyEvent *e);

private:
    QTimer *timer_;

    World* world_;
};

#endif // WINDOW_H
