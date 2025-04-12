#pragma once

#include <Vector.h>
#include "BouncingBoxComponent.h"

class CollisionSystem
{
    private:
    public:
        void update(Vector<BouncingBoxComponent*> bouncingBoxComponents);
};
