#pragma once

#include <Vector.h>
#include "Entity.h"
#include "GoalComponent.h"

class GoalDetectionSystem 
{
    private: 
        bool hits(Entity* ball, GoalComponent* goalComponent);
        bool movesRight(Entity* entity);
        bool movesLeft(Entity* entity);
        bool hitsFromLeft(Entity* entity1, Entity* entity2);
        bool hitsFromRight(Entity* entity1, Entity* entity2);
        bool areOnSameHeight(Entity* entity1, Entity* entity2);
    public:
        void handle(Entity* ball, Vector<GoalComponent*> goalComponents);
};
