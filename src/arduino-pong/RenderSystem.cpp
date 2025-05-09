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
        
        redraw(component->entity, components);
    }
}

void RenderSystem::redraw(Entity* entity, Vector<RenderComponent*> otherComponents)
{
    if (!hasMoved(entity) && !entity->renderComponent.redrawIsRequested) {
        return;
    }

    if (
        (
            entity->renderComponent.previousPosition.x != -1 
            && entity->renderComponent.previousPosition.y != -1
        )
        || entity->renderComponent.redrawIsRequested
    ) {
        entity->renderComponent.sprite
            ->eraseFrom(appliance->screen, entity->renderComponent.previousPosition);
        redrawBackgroundComponents(otherComponents, &entity->renderComponent);
    }
    
    entity->renderComponent.sprite
        ->drawOn(appliance->screen, entity->positionComponent.position);
    entity->renderComponent.previousPosition = 
        entity->positionComponent.position;
    entity->renderComponent.redrawIsRequested = false;
}
void RenderSystem::redrawBackgroundComponents(Vector<RenderComponent *> components, RenderComponent* erasedComponent)
{
    for (auto component: components) {
        if (!component->isBackground) {
            continue;
        }

        if (component == erasedComponent) {
            continue;
        }

        if (!overlaps(component, erasedComponent)) {
            continue;
        }

        component->sprite->drawOn(
            appliance->screen, 
            component->entity->positionComponent.position);
    }
}

bool RenderSystem::overlaps(RenderComponent *component1, RenderComponent *component2)
{
    int component1Left = component1->entity->positionComponent.position.x;
    int component1Right = component1Left + component1->sprite->getWidth();
    int component1Top = component1->entity->positionComponent.position.y;
    int component1Bottom = component1Top + component1->sprite->getHeight();

    int component2Left = component2->entity->positionComponent.position.x;
    int component2Right = component2Left + component2->sprite->getWidth();
    int component2Top = component2->entity->positionComponent.position.y;
    int component2Bottom = component2Top + component2->sprite->getHeight();

    return !(component1Left > component2Right || component1Right < component2Left || component1Top > component2Bottom || component1Bottom < component2Top);
}

