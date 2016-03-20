#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

#include "shader.h"

Shader::Shader(std::string vertexshader, std::string fragmentshader) {
    this->initializeOpenGLFunctions();
    this->loadShader(vertexshader, fragmentshader);
}

Shader::~Shader() {

}

GLboolean Shader::loadShader(std::string vertexPath, std::string fragmentPath) {
    GLuint vertexshader, fragmentshader;
    std::ifstream vertexFile, fragmentFile;
    std::string vertexCode, fragmentCode;
    GLint success;

    vertexFile.exceptions(std::ifstream::badbit);
    fragmentFile.exceptions(std::ifstream::badbit);

    try {
        vertexFile.open(vertexPath.c_str());
        fragmentFile.open(fragmentPath.c_str());

        std::stringstream vertexStream;
        std::stringstream fragmentStream;

        vertexStream << vertexFile.rdbuf();
        fragmentStream << fragmentFile.rdbuf();

        vertexFile.close();
        fragmentFile.close();

        vertexCode = vertexStream.str();
        fragmentCode = fragmentStream.str();
    }
    catch (std::ifstream::failure e) {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    }


    const GLchar* vShaderCode = vertexCode.c_str();
    const GLchar* fShaderCode = fragmentCode.c_str();

    //Vertexshader compilation
    vertexshader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexshader, 1, &vShaderCode, NULL);
    glCompileShader(vertexshader);

    glGetShaderiv(vertexshader, GL_COMPILE_STATUS, &success);
    success = this->showError(vertexshader,
                              GL_COMPILE_STATUS,
                              "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
                              );
    if (!success) {
        glDeleteShader(vertexshader);
        return success;
    }

    //Fragmentshader compilation
    fragmentshader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentshader, 1, &fShaderCode, NULL);
    glCompileShader(fragmentshader);

    glGetShaderiv(fragmentshader, GL_COMPILE_STATUS, &success);

    success = this->showError(fragmentshader,
                              GL_COMPILE_STATUS,
                              "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n"
                              );
    if (!success) {
        glDeleteShader(vertexshader);
        glDeleteShader(fragmentshader);
        return success;
    }

    //Shader compilation
    this->program_ = glCreateProgram();
    glAttachShader(this->program_, vertexshader);
    glAttachShader(this->program_, fragmentshader);
    glLinkProgram(this->program_);

    glDeleteShader(fragmentshader);
    glDeleteShader(vertexshader);

    success = this->showError(this->program_,
                              GL_LINK_STATUS,
                              "ERROR::SHADER::PROGRAM::LINKING_FAILED\n"
                              );

    return success;
}

GLboolean Shader::showError(GLuint shader, GLint op, std::string errorMsg) {
    GLint success;

    glGetProgramiv(shader, op, &success);
    if (success == GL_FALSE) {
        GLint maxLength = 0;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

        //The maxLength includes the NULL character
        std::vector<GLchar> infoLog(maxLength);
        glGetShaderInfoLog(shader, maxLength, &maxLength, &infoLog[0]);
        std::cout << errorMsg << &infoLog[0] << std::endl;


        return GL_FALSE;
    }

        return GL_TRUE;
}

void Shader::setUniformLocation(const char *name, int value) {
    glUniform1i(glGetUniformLocation(this->program_, name), value);
}

void Shader::setUniformLocation(const char *name, float value) {
    glUniform1f(glGetUniformLocation(this->program_, name), value);
}

void Shader::setUniformLocation(const char *name, glm::vec3 &value) {
    glUniform3fv(glGetUniformLocation(this->program_, name), 1, glm::value_ptr(value));
}

void Shader::setUniformLocation(const char *name, glm::vec4 &value) {
    glUniform4fv(glGetUniformLocation(this->program_, name), 1,  glm::value_ptr(value));
}

void Shader::setUniformLocationT(const char* name, int texUnit){
    glUniform1i(glGetUniformLocation(this->program_, name), texUnit);
}

void Shader::setUniformLocationM(const char* name, glm::mat4 &mat){
    glUniformMatrix4fv(glGetUniformLocation(this->program_, name), 1, GL_FALSE, glm::value_ptr(mat));
}

void Shader::bind() {
    glUseProgram(this->program_);
}
