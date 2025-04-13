#pragma once

#include <Vector.h>
#include "Entity.h"
#include "GoalComponent.h"

class GoalDetectionSystem 
{
    private: 
        bool hits(Entity* ball, GoalComponent* goalComponent);
    public:
        void handle(Entity* ball, Vector<GoalComponent*> goalComponents);
};
