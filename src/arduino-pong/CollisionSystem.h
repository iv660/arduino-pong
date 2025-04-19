#pragma once

#include <Vector.h>
#include "BouncingBoxComponent.h"
#include "ServiceComponent.h"
#include "PositionFollowingComponent.h"
#include "Entity.h"

class CollisionSystem
{
    private:
        bool movesLeft(Entity *entity);
        bool movesRight(Entity *entity);
        bool movesUp(Entity *entity);
        bool movesDown(Entity *entity);

        bool hitsFromLeft(Entity * entity1, Entity * entity2);
        bool hitsFromRight(Entity * entity1, Entity * entity2);
        bool hitsFromTop(Entity * entity1, Entity * entity2);
        bool hitsFromBottom(Entity * entity1, Entity * entity2);

        bool areOnSameHeight(Entity * entity1, Entity * entity2);
        bool areOnSameWidth(Entity * entity1, Entity * entity2);
        
        void bounceVertically(Entity *entity);
        void bounceHorizontally(Entity *entity);

        bool serviceIsRequestedForAnyOf(Vector<ServiceComponent*> serviceComponents);

        void resetHitsCounters(Vector<BouncingBoxComponent*> bouncingBoxComponents);
        void unfreezePositionFollowing(Vector<PositionFollowingComponent*> positionFollowingComponents);
    public:
        void update(Vector<BouncingBoxComponent*> bouncingBoxComponents);
        void afterServiceRequest(Vector<BouncingBoxComponent*> bouncingBoxComponents, Vector<ServiceComponent*> serviceComponents, Vector<PositionFollowingComponent*> positionFollowingComponents);
};
