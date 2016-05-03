#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "shader.h"


/***************************************************************************************
 * Classe virtuelle pur servant a interfacer les objet pouvant etre affiché a l'ecran  *
 *------------------------------------------------------------------------------------*/
class Drawable {
public:
    virtual void draw(Shader &shader) = 0;
};
/**************************************************************************************
* Auteur: ROVES Matthias                                                              *
***************************************************************************************/

#endif // DRAWABLE_H

