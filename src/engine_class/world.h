#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include <QWidget>

#include "engine_abstract.h"
#include "../data_class/world_data.h"


/***************************************************************************************
 * Classe regrouppant les moteur et les donnée                                         *
 *------------------------------------------------------------------------------------*/
class World {
public:
    World(QWidget* window);
    ~World();

    //Initialise tout les moteurs
    void initialize();

    //met a jour tout les moteurs
    void update();

    //Accesseur
    inline QWidget* getWindow() { return this->window_; }
    inline World_Data* getData() { return this->data_; }

private:
    QWidget *window_;

    World_Data* data_;
    std::vector<Engine_Abstract*> engines_;
};
/**************************************************************************************
* Auteur: ROVES Matthias                                                              *
***************************************************************************************/

#endif // WORLD_H
