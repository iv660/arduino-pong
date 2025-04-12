#pragma once

#include "Entity.h"

class MovementSystem
{
    private:
        void updateX(Entity* entity);
        void updateY(Entity* entity);
    public:
        void update(Entity* entity);
};
