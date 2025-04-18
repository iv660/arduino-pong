#include "ManualPositionControlSystem.h"

#include "Entity.h"

void ManualPositionControlSystem::update(Entity *entity)
{
    entity->positionComponent.position.y = 
            map(appliance->analogJoystick->getY(), 0, 1023,     
                entity->positionControlComponent.range.from, entity->positionControlComponent.range.to);
}
