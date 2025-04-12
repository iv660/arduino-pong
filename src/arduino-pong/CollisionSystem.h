#pragma once

#include <Vector.h>
#include "BouncingBoxComponent.h"
#include "Entity.h"

class CollisionSystem
{
    public:
        void update(Vector<BouncingBoxComponent> bouncingBoxComponents);
};
