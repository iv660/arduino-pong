#pragma once

#include "Entity.h"

class PositionFollowingSystem {
    private:
        int calculatePositionY(Entity* entity);
    public:
        virtual void update(Entity* entity);
};
