#include "GoalDetectionSystem.h"

bool GoalDetectionSystem::hits(Entity *ball, GoalComponent *goalComponent)
{
    if (movesRight(ball) && hitsFromLeft(ball, goalComponent->entity) && areOnSameHeight(ball, goalComponent->entity)) {
        return true;
    }

    if (movesLeft(ball) && hitsFromRight(ball, goalComponent->entity) && areOnSameHeight(ball, goalComponent->entity)) {
        return true;
    }

    return false;
}

void GoalDetectionSystem::handle(Entity *ball, Vector<GoalComponent *> goalComponents)
{
    for (auto goalComponent: goalComponents) {
        if (hits(ball, goalComponent)) {
            goalComponent->entity->counterComponent.value++;
            goalComponent->score->renderComponent.redrawIsRequested = true;
            goalComponent->service->serviceComponent->isRequested = true;
        }
    }
}

bool GoalDetectionSystem::movesRight(Entity *entity) {
    return entity->movementComponent.xMovement.velocity > 0;
}

bool GoalDetectionSystem::movesLeft(Entity *entity) {
    return entity->movementComponent.xMovement.velocity < 0;
}

bool GoalDetectionSystem::hitsFromLeft(Entity *entity1, Entity *entity2) {
    return entity1->positionComponent.position.x + entity1->bouncingBoxComponent.width == entity2->positionComponent.position.x;
}

bool GoalDetectionSystem::hitsFromRight(Entity *entity1, Entity *entity2) {
    return entity1->positionComponent.position.x == entity2->positionComponent.position.x + entity2->bouncingBoxComponent.width;
}

bool GoalDetectionSystem::areOnSameHeight(Entity *entity1, Entity *entity2) {
    int entity1Top = entity1->positionComponent.position.y;
    int entity1Bottom = entity1Top + entity1->goalComponent->height;
    int entity2Top = entity2->positionComponent.position.y;
    int entity2Bottom = entity2Top + entity2->goalComponent->height;

    return (entity2Top <= entity1Top && entity1Top <= entity2Bottom) || 
           (entity1Top <= entity2Top && entity2Top <= entity1Bottom) || 
           (entity1Top <= entity2Bottom && entity2Bottom <= entity1Bottom) || 
           (entity2Top <= entity1Bottom && entity1Bottom <= entity2Bottom);
}

