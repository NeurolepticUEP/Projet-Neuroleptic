#ifndef WINDOW_H
#define WINDOW_H


#include <QKeyEvent>
#include <QTimer>

#include "engine_class/world.h"

#include <QtOpenGL/QGLWidget>

/***************************************************************************************
 * Classe definissant la fenetre                                                       *
 *------------------------------------------------------------------------------------*/
class Window : public QGLWidget {
    Q_OBJECT
public:
    Window();
    virtual ~Window();

    //Initialisation d'openGL (utilisé en interne)
    virtual void initializeGL();

    //Fonction pour mettre a jour la taille de la fenetre de rendu (non fonctionnel)
    virtual void resizeGL(int w, int h);

    //Affichage de la scene
    virtual void paintGL();

    //Evenement de clavier (non fonctionnel)
    void keyPressEvent(QKeyEvent *e);

private:
    QTimer *timer_;

    World* world_;
};
/**************************************************************************************
* Auteur: ROVES Matthias                                                              *
***************************************************************************************/

#endif // WINDOW_H
