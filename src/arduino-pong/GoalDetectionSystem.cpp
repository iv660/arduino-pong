#include "GoalDetectionSystem.h"

bool GoalDetectionSystem::hits(Entity *ball, GoalComponent *goalComponent)
{
    return false;
}

void GoalDetectionSystem::handle(Entity *ball, Vector<GoalComponent *> goalComponents)
{
    for (auto goalComponent: goalComponents) {
        if (hits(ball, goalComponent)) {
            goalComponent->service->serviceComponent.isRequested = true;
        }
    }
}
