#ifndef CAMERA_H
#define CAMERA_H

#include "../../gl_include.h"

enum Camera_Mode {
    MODE_FPS, MODE_TRACKBALL_H, MODE_TRACKBALL_3D
};


/***************************************************************************************
 *  Camera contient toute les donnees et methodes necessaires a l'utilisation d'une    *
 * camera dans le moteur 3D.                                                           *
 *------------------------------------------------------------------------------------*/
class Camera {
public:
    Camera(
           Camera_Mode mode,
           glm::vec3 position,
           glm::vec3 direction,
           float fov,
           float heigth,
           float width
           );
    ~Camera() {  }

    //Accesseur de la classe
    void setMode(Camera_Mode mode) { this->mode_ = mode; }
    glm::mat4& getViewMatrix() { return this->view_; }
    glm::mat4& getProjectionMatrix() { return this->projection_; }
    glm::vec3& getPosition() { return this->position_; }

    //Cette fonction permet de translater la position de la camera.
    void translateLocal(glm::vec3 vec);

    //Cette fonction permet d'operer une rotation de la camera selon un axe dirigée vers le haut.
    void rotateAroundUp(float angle);

    //Cette fonction permet d'operer une rotation selon un axe dirigée vers la droite.
    void rotateAroundRight(float angle);

private:

    //Fonction permettant de creer la matrice Monde vers Vue.
    void createViewMatrix();

    Camera_Mode mode_;

    glm::mat4 view_;
    glm::mat4 projection_;

    glm::vec3 position_;
    glm::vec3 direction_;
    glm::vec3 right_;
    glm::vec3 up_;
};
/**************************************************************************************
* Auteur: ROVES Matthias                                                              *
***************************************************************************************/

#endif // CAMERA_H
