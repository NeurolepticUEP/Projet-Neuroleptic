#ifndef MESH
#define MESH

#include <string>

#include "../../gl_include.h"
#include "bindable.h"


/***************************************************************************************
 * Classe definissant les maillage d'objet 3D                                          *
 *------------------------------------------------------------------------------------*/
class Mesh : protected QOpenGLFunctions_3_3_Core, public Bindable {
public:
    //Constructeur se basant sur des buffers deja creer
    Mesh(
            std::string &id,
            GLuint vao,         //buffer contenant le VAO
            GLuint vbo,         //buffer contenant le VBO
            GLuint ebo          //buffer contenant l'EBO
            );

    //Constructeur creant de lui même les buffers
    Mesh(
            std::string &id,
            GLfloat *vertices,  //Tableau contenant les points déja entrelacer selon le modele: Position, Normale, Couleur
            GLuint *indices,    //Tableau contenant les indices des points regroupé pour former les faces
            int vert_length,    //La taille du tableau vertices
            int ind_length      //La taille du tableau indices
            );
    virtual ~Mesh();

    //Accesseur
    GLuint getVAO();
    GLuint getVBO();
    GLuint getEBO();

    int getNbIndices() { return this->nb_indices_; }

    //Fonction permettant de lier le maillage a la carte graphique (necessaire pour afficher ce dernier)
    //Voir Bindable pour plus de detail.
    virtual void bind(Shader&);

private:
    GLuint vao_;
    GLuint vbo_;
    GLuint ebo_;

    int nb_indices_;
};
/**************************************************************************************
* Auteur: ROVES Matthias                                                              *
***************************************************************************************/

#endif // MESH

