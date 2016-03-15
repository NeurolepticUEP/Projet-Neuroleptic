#ifndef CAMERA_H
#define CAMERA_H

#include "gl_include.h"

enum Camera_Mode {
    MODE_FPS, MODE_TRACKBALL_H, MODE_TRACKBALL_3D
};

class Camera {
public:
    Camera(Camera_Mode mode,
           glm::vec3 position, glm::vec3 direction,
           float fov, float heigth, float width);
    ~Camera() { }

    void setMode(Camera_Mode mode) { this->mode_ = mode; }

    glm::mat4& getViewMatrix() { return this->view_; }
    glm::mat4& getProjectionMatrix() { return this->projection_; }
    glm::vec3& getPosition() { return this->position_; }

    void translateLocal(glm::vec3 vec);
    void rotateAroundUp(float angle);
    void rotateAroundRight(float angle);

private:
    void createViewMatric();

    Camera_Mode mode_;

    glm::mat4 view_;
    glm::mat4 projection_;

    glm::vec3 position_;
    glm::vec3 direction_;
    glm::vec3 right_;
    glm::vec3 up_;
};

#endif // CAMERA_H
