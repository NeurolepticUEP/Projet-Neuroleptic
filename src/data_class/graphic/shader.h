#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <vector>

#include "../../gl_include.h"

/**************************************************************************************
* Classe definissant les shaders                                                      *
* ------------------------------------------------------------------------------------*
* Note: Pourquoi ne pas en faire un Bindable ?                                        *
*------------------------------------------------------------------------------------*/
class Shader : protected QOpenGLFunctions_3_3_Core {
public:
    Shader(
            std::string vertexshader,       //Chemin vers le fichiers representant le vertex shader
            std::string fragmentshader      //Chemin vers le fichiers representant le fragment shader
            );
    virtual ~Shader();

    //Fonction pour lier une valeur uniforme sur le shader
    void setUniformLocation(const char* name, int value);
    void setUniformLocation(const char* name, float value);
    void setUniformLocation(const char* name, glm::vec3 &value);
    void setUniformLocation(const char* name, glm::vec4 &value);

    //Fonction pour lier des matrices sur le shader en uniforme
    void setUniformLocationM(const char* name, glm::mat4 &mat);
    void setUniformLocationM(const char* name, glm::mat3 &mat);

    //Fonction initialisant le shader a partir des chemin vers les fichiers de shader
    GLboolean loadShader(std::string vertexPath, std::string fragmentPath);

    //Fonction liant le shader a la carte graphique
    virtual void bind();
private:

    //Affichage des erreurs
    GLboolean showError(GLuint shader, GLint op, std::string errorMsg);

    GLuint program_;
};
/**************************************************************************************
* Auteur: ROVES Matthias                                                              *
***************************************************************************************/

#endif // SHADER_H
