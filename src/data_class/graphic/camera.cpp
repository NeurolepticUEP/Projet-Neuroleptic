#include "camera.h"

Camera::Camera(Camera_Mode mode, glm::vec3 position, glm::vec3 direction,
               float fov, float width, float heigth) {
    this->mode_ = mode;

    this->projection_ = glm::perspective(fov, width/heigth, 0.1f, 100.0f);

    this->position_ = position;
    this->direction_ = glm::normalize(direction);
    this->right_ = glm::normalize(glm::cross(glm::vec3(0.0, 1.0, 0.0), direction));
    this->up_ = glm::cross(this->direction_, this->right_);

    createViewMatric();
}

void Camera::createViewMatric() {
    this->view_ = glm::lookAt(this->position_, this->position_ + this->direction_, this->up_);
}

void Camera::translateLocal(glm::vec3 vec) {
    switch (this->mode_) {
        case MODE_FPS:
            this->position_ -= vec[0] * this->right_ + vec[1] * this->up_ + vec[2] * this->direction_;
            createViewMatric();
            break;

        case MODE_TRACKBALL_H:
        case MODE_TRACKBALL_3D:
            //La translation est interdite en mode TrackBall
            break;
    }
}

void Camera::rotateAroundUp(float angle) {
    switch (this->mode_) {
        case MODE_FPS:
            this->direction_ = glm::rotate(this->direction_, angle, this->up_);
            this->right_ = glm::rotate(this->right_, angle, this->up_);
            createViewMatric();
            break;

        case MODE_TRACKBALL_H:
        case MODE_TRACKBALL_3D:
            this->direction_ = glm::rotate(this->direction_, angle, this->up_);
            this->right_ = glm::rotate(this->right_, angle, this->up_);
            this->position_ = glm::rotate(this->position_, angle, this->up_);
            createViewMatric();
            break;
    }
}

void Camera::rotateAroundRight(float angle) {
    switch (this->mode_) {
        case MODE_FPS:
            this->direction_ = glm::rotate(this->direction_, angle, this->right_);
            //this->up_ = glm::rotate(this->up_, angle, this->right_);
            createViewMatric();
            break;
         case MODE_TRACKBALL_H:
            //Pas de mouvement vertical en trackball horizontal
            break;

        case MODE_TRACKBALL_3D:
            this->direction_ = glm::rotate(this->direction_, angle, this->right_);
            this->position_ = glm::rotate(this->position_, angle, this->right_);
            createViewMatric();
            break;
    }
}
