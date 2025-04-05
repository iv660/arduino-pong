#include "MovementSystem.h"

void MovementSystem::update(Entity *entity)
{
    entity->positionComponent.position.x 
        += entity->movementComponent.velocity.x;
    entity->positionComponent.position.y 
        += entity->movementComponent.velocity.y;
}