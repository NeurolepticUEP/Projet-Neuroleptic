#ifndef ENGINE_INTERACTION_H
#define ENGINE_INTERACTION_H

#include <QKeyEvent>
#include <QCursor>
#include <vector>

#include "engine_abstract.h"

#include "vrpn_Tracker.h"

/***************************************************************************************
 * Classe definnissant les fonctionnalité du moteur d'interaction avec VRPN            *
 *------------------------------------------------------------------------------------*/
class Engine_Interaction : public Engine_Abstract {
public:
    Engine_Interaction(World* world);
    ~Engine_Interaction();

    //Fonction gerant les evenements clavier
    void keyboardEventHandler(QKeyEvent *e);

    //Accesseur pour les elements de l'historique de position et d'angle
    glm::vec3 getHistPos(int pos, int state) { return this->hist_modif_pos_[pos][state]; }
    void setHistPos(int pos, int state, glm::vec3 pos_vec) { this->hist_modif_pos_[pos][state] = pos_vec; }

    glm::vec4 getHistQuad(int pos, int state) { return this->hist_modif_qua_[pos][state]; }
    void setHistQuad(int pos, int state, glm::vec4 qua_vec) { this->hist_modif_qua_[pos][state] = qua_vec; }


    //Initialisation de VRPN
    virtual void initialize();

    //Mise a jour des donnée (les donnée seront modifiée
    virtual void update(World_Data* data);

private:
    vrpn_Tracker_Remote* vrpnTracker;

    glm::vec3 hist_modif_pos_[24][3];
    glm::vec4 hist_modif_qua_[24][3];
};
/**************************************************************************************
* Auteur: ROVES Matthias                                                              *
***************************************************************************************/

#endif // ENGINE_INTERACTION_H
