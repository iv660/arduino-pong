#include "PositionFollowingSystem.h"

int PositionFollowingSystem::calculatePositionY(Entity *entity)
{
    const Entity* trackedEntity = entity->positionFollowingComponent.trackedEntity;

    int trackedEntityPositionY = trackedEntity->positionComponent.position.y;
    int trackedEntityCenterPositionY = trackedEntityPositionY + (trackedEntity->renderComponent.sprite->getHeight() / 2);
    int desiredControlledEntityPositionY  = trackedEntityCenterPositionY - (entity->renderComponent.sprite->getHeight() / 2);

    if (desiredControlledEntityPositionY < entity->positionControlComponent.range.from) {
        return entity->positionControlComponent.range.from;
    }

    if (desiredControlledEntityPositionY > entity->positionControlComponent.range.to) {
        return entity->positionControlComponent.range.to;
    }

    return desiredControlledEntityPositionY;
}

void PositionFollowingSystem::update(Entity *entity)
{
    entity->positionComponent.position.y = calculatePositionY(entity);
}