#include "MovementSystem.h"

#include <Arduino.h>

#include "AxisPositionUpdater.h"

void MovementSystem::updateX(Entity *entity)
{
    AxisPositionUpdater xUpdater(
        &entity->movementComponent.xMovement, 
        &entity->positionComponent.position.x, 
        entity->movementComponent.updateIntervalBase);

    xUpdater.updatePosition();

    return;
}

void MovementSystem::updateY(Entity *entity)
{
    AxisPositionUpdater yUpdater(
        &entity->movementComponent.yMovement, 
        &entity->positionComponent.position.y, 
        entity->movementComponent.updateIntervalBase);

    yUpdater.updatePosition();
}

void MovementSystem::update(Entity *entity)
{
    updateX(entity);
    updateY(entity);
}