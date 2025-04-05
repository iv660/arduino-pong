#include "MovementSystem.h"

#include <Arduino.h>

bool MovementSystem::isTimeToUpdate()
{
    if (millis() > nextUpdateTime) {
        return true;
    }

    return false;
}

void MovementSystem::update(Entity *entity)
{
    if (!isTimeToUpdate()) {
        return;
    }

    nextUpdateTime = millis() + updatePeriod;
    entity->positionComponent.position.x 
        += entity->movementComponent.velocity.x;
    entity->positionComponent.position.y 
        += entity->movementComponent.velocity.y;
}