#include "RenderSystem.h"

void RenderSystem::begin()
{
    appliance->screen->begin();
    appliance->screen->background(0, 0, 0);
}

void RenderSystem::update(RenderComponent* renderComponent)
{
    renderComponent->sprite->drawOn(appliance->screen, {45, 60});
}