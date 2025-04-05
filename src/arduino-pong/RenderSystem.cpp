#include "RenderSystem.h"

void RenderSystem::begin()
{
    appliance->screen->begin();
    appliance->screen->background(0, 0, 0);
}

void RenderSystem::redraw(Entity* entity)
{
    entity->renderComponent.sprite
        ->drawOn(appliance->screen, entity->positionComponent.position);
}