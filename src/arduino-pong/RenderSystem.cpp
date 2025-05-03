#include "RenderSystem.h"

#include <Arduino.h>

bool RenderSystem::hasMoved(Entity *entity)
{
    return entity->positionComponent.position != entity->renderComponent.previousPosition;
}

void RenderSystem::begin()
{
    appliance->screen->begin();
    appliance->screen->background(0, 0, 0);
}

void RenderSystem::redraw(Vector<RenderComponent*> components)
{
    for (auto component: components) {
        if (component->entity == nullptr) {
            continue;
        }
        
        redraw(component->entity);
    }
}

void RenderSystem::redraw(Entity* entity)
{
    if (!hasMoved(entity)) {
        return;
    }

    if (
        entity->renderComponent.previousPosition.x != -1 
        && entity->renderComponent.previousPosition.y != -1
    ) {
        entity->renderComponent.sprite
            ->eraseFrom(appliance->screen, entity->renderComponent.previousPosition);
    }
    
    entity->renderComponent.sprite
        ->drawOn(appliance->screen, entity->positionComponent.position);
    entity->renderComponent.previousPosition = 
        entity->positionComponent.position;
}