#include "MovementSystem.h"

#include <Arduino.h>

void MovementSystem::updateX(Entity *entity)
{
    if (false == isTimeToUpdateX(entity)) {
        return;
    }

    entity->positionComponent.position.x += copysign(entity->movementComponent.velocity.x);
    entity->movementComponent.xUpdatedAtMillis = millis();
}

void MovementSystem::updateY(Entity *entity)
{
    if (false == isTimeToUpdateY(entity)) {
        return;
    }

    entity->positionComponent.position.y += copysign(entity->movementComponent.velocity.y);
    entity->movementComponent.yUpdatedAtMillis = millis();
}

bool MovementSystem::isTimeToUpdateX(Entity *entity)
{
    if (timeSinceLastUpdateX(entity) > updateIntervalX(entity)) {
        return true;
    }

    return false;
}

bool MovementSystem::isTimeToUpdateY(Entity *entity)
{
    if (timeSinceLastUpdateY(entity) > updateIntervalY(entity)) {
        return true;
    }

    return false;
}

long MovementSystem::timeSinceLastUpdateX(Entity *entity)
{
    return millis() - entity->movementComponent.xUpdatedAtMillis;
}

long MovementSystem::timeSinceLastUpdateY(Entity *entity)
{
    return millis() - entity->movementComponent.yUpdatedAtMillis;
}

long MovementSystem::updateIntervalX(Entity *entity)
{
    return entity->movementComponent.updateIntervalBase / abs(entity->movementComponent.velocity.x);
}

long MovementSystem::updateIntervalY(Entity *entity)
{
    return entity->movementComponent.updateIntervalBase / abs(entity->movementComponent.velocity.y);
}

int MovementSystem::copysign(long x)
{
    if (x > 0) {
        return 1;
    }

    if (x < 0) {
        return -1;
    }

    return 0;
}

void MovementSystem::update(Entity *entity)
{
    updateX(entity);
    updateY(entity);
}