#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <vector>

#include "../../gl_include.h"

class Shader : protected QOpenGLFunctions_3_3_Core {
public:
    Shader(std::string vertexshader, std::string fragmentshader);
    virtual ~Shader();

    void setUniformLocation(const char* name, int value);
    void setUniformLocation(const char* name, float value);
    void setUniformLocation(const char* name, glm::vec3 &value);
    void setUniformLocation(const char* name, glm::vec4 &value);
    void setUniformLocationT(const char* name, int texUnit);
    void setUniformLocationM(const char* name, glm::mat4 &mat);

    GLboolean loadShader(std::string vertexPath, std::string fragmentPath);

    virtual void bind();
private:
    GLboolean showError(GLuint shader, GLint op, std::string errorMsg);

    GLuint program_;
};

#endif // SHADER_H
