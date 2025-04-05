#pragma once

#include "Entity.h"

class MovementSystem
{
    private:
        unsigned long nextUpdateTime = 0;
        unsigned long const updatePeriod = 20;

        bool isTimeToUpdate();
    public:
        void update(Entity* entity);
};
