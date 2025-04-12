#pragma once

#include "Entity.h"

class MovementSystem
{
    private:
        void updateX(Entity* entity);
        void updateY(Entity* entity);
        bool isTimeToUpdateX(Entity* entity);
        bool isTimeToUpdateY(Entity* entity);
        long timeSinceLastUpdateX(Entity* entity);
        long timeSinceLastUpdateY(Entity* entity);
        long updateIntervalX(Entity* entity);
        long updateIntervalY(Entity* entity);

        int copysign(long x);
    public:
        void update(Entity* entity);
};
