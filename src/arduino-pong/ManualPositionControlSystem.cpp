#include "ManualPositionControlSystem.h"

#include "Entity.h"

void ManualPositionControlSystem::update(Vector<PositionControlComponent*> components)
{
    for (PositionControlComponent* component : components) {
        component->entity->positionComponent.position.y = 
            map(appliance->analogJoystick->getY(), 0, 1023,     
                component->range.from, component->range.to);
        Serial.print("Joystick position: "); Serial.println(appliance->analogJoystick->getY());
    }
}