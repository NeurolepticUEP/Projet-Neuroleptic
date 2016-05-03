#ifndef DATA_MAKER_H
#define DATA_MAKER_H

#include <string>
#include <iostream>

#include "gl_include.h"
#include "data_class/graphic/mesh.h"


/***************************************************************************************
 * Classe definnissant des fonctions creant des maillage simple                        *
 *------------------------------------------------------------------------------------*/
class Data_Maker {
public:
    //Fonction creant le maillage d'un cube
    static Mesh* createCubeMesh();
};
/**************************************************************************************
* Auteur: ROVES Matthias                                                              *
***************************************************************************************/

#endif // DATA_MAKER_H
