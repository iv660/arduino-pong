#include "PositionFollowingSystem.h"

#include <Arduino.h>

int PositionFollowingSystem::calculatePositionY(Entity *entity)
{
    const Entity* trackedEntity = entity->positionFollowingComponent->trackedEntity;

    int trackedEntityPositionY = trackedEntity->positionComponent.position.y;
    int trackedEntityCenterPositionY = trackedEntityPositionY + (trackedEntity->renderComponent.sprite->getHeight() / 2);
    int desiredControlledEntityPositionY  = trackedEntityCenterPositionY - (entity->renderComponent.sprite->getHeight() / 2);

    if (desiredControlledEntityPositionY < entity->positionControlComponent->range.from) {
        return entity->positionControlComponent->range.from;
    }

    if (desiredControlledEntityPositionY > entity->positionControlComponent->range.to) {
        return entity->positionControlComponent->range.to;
    }

    return desiredControlledEntityPositionY;
}

void PositionFollowingSystem::update(Entity *entity)
{
    if (!entity->positionFollowingComponent->isFollowing) {
        return;
    }

    if (entity->bouncingBoxComponent.hitsCount >= entity->positionFollowingComponent->hitsCountBeforeFailure) {
        
        entity->positionFollowingComponent->isFollowing = false;
    }

    entity->positionComponent.position.y = calculatePositionY(entity);
}