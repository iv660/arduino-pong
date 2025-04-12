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
    // appliance->screen->stroke(0, 0, 0);
    // appliance->screen->fill(0, 0, 0);
    // appliance->screen->rect(0, 0, appliance->screen->width(), appliance->screen->height());
}

void RenderSystem::redraw(Entity* entity)
{
    if (!hasMoved(entity)) {
        return;
    }

    entity->renderComponent.sprite
        ->eraseFrom(appliance->screen, entity->renderComponent.previousPosition);
    entity->renderComponent.sprite
        ->drawOn(appliance->screen, entity->positionComponent.position);
    entity->renderComponent.previousPosition = 
        entity->positionComponent.position;
}