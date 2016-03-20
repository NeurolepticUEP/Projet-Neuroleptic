#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include <QWidget>

#include "engine_abstract.h"
#include "../data_class/world_data.h"

class World {
public:
    World(QWidget* window);

    void initialize();
    void update();

    inline QWidget* getWindow() { return this->window_; }
    inline World_Data* getData() { return this->data_; }

private:
    QWidget *window_;

    World_Data* data_;
    std::vector<Engine_Abstract*> engines_;
};

#endif // WORLD_H
