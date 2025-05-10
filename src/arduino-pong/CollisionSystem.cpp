#include "CollisionSystem.h"

#include <Arduino.h>

bool CollisionSystem::movesLeft(Entity * entity)
{
    return entity->movementComponent.xMovement.velocity < 0;
}

bool CollisionSystem::movesRight(Entity * entity)
{
    return entity->movementComponent.xMovement.velocity > 0;
}

bool CollisionSystem::movesUp(Entity * entity)
{
    return entity->movementComponent.yMovement.velocity < 0;
}

bool CollisionSystem::movesDown(Entity * entity)
{
    return entity->movementComponent.yMovement.velocity > 0;
}

bool CollisionSystem::hitsFromLeft(Entity * entity1, Entity * entity2)
{
    return entity1->positionComponent.position.x + entity1->bouncingBoxComponent.width == entity2->positionComponent.position.x;
}
bool CollisionSystem::hitsFromRight(Entity * entity1, Entity * entity2)
{
    return entity1->positionComponent.position.x == entity2->positionComponent.position.x + entity2->bouncingBoxComponent.width;
}

bool CollisionSystem::hitsFromTop(Entity * entity1, Entity * entity2)
{
    return entity1->positionComponent.position.y + entity1->bouncingBoxComponent.height == entity2->positionComponent.position.y;
}

bool CollisionSystem::hitsFromBottom(Entity * entity1, Entity * entity2)
{
    return entity1->positionComponent.position.y == entity2->positionComponent.position.y + entity2->bouncingBoxComponent.height;
}

bool CollisionSystem::areOnSameHeight(Entity * entity1, Entity * entity2)
{
    int entity1Top = entity1->positionComponent.position.y;
    int entity1Bottom = entity1Top + entity1->bouncingBoxComponent.height;
    int entity2Top = entity2->positionComponent.position.y;
    int entity2Bottom = entity2Top + entity2->bouncingBoxComponent.height;

    if (entity2Top <= entity1Top && entity1Top <= entity2Bottom) {
        return true;
    }

    if (entity1Top <= entity2Top && entity2Top <= entity1Bottom) {
        return true;
    }

    if (entity1Top <= entity2Bottom && entity2Bottom <= entity1Bottom) {
        return true;
    }

    if (entity2Top <= entity1Bottom && entity1Bottom <= entity2Bottom) {
        return true;
    }

    return false;
}

bool CollisionSystem::areOnSameWidth(Entity * entity1, Entity * entity2)
{
    int entity1Left = entity1->positionComponent.position.x;
    int entity1Right = entity1Left + entity1->bouncingBoxComponent.width;
    int entity2Left = entity2->positionComponent.position.x;
    int entity2Right = entity2Left + entity2->bouncingBoxComponent.width;

    if (entity2Left <= entity1Left && entity1Left <= entity2Right) {
        return true;
    }

    if (entity1Left <= entity2Left && entity2Left <= entity1Right) {
        return true;
    }

    if (entity1Left <= entity2Right && entity2Right <= entity1Right) {
        return true;
    }   

    if (entity2Left <= entity1Right && entity1Right <= entity2Right) {
        return true;
    }

    return false;
}

void CollisionSystem::bounceVertically(Entity *entity)
{
    entity->movementComponent.yMovement.velocity *= -1;
    entity->bouncingBoxComponent.hitsCount++;
}

void CollisionSystem::bounceHorizontally(Entity *entity)
{
    entity->movementComponent.xMovement.velocity *= -1;
    entity->bouncingBoxComponent.hitsCount++;
}

bool CollisionSystem::serviceIsRequestedForAnyOf(Vector<ServiceComponent*> serviceComponents)
{
    for (auto serviceComponent: serviceComponents) {
        if (serviceComponent->isRequested) {
            return true;
        }
    }

    return false;
}

void CollisionSystem::resetHitsCounters(Vector<BouncingBoxComponent*> bouncingBoxComponents)
{
    for (auto bouncingBoxComponent: bouncingBoxComponents) {
        bouncingBoxComponent->hitsCount = 0;
    }
}

void CollisionSystem::adjustPositionFollowingSkill(Vector<PositionFollowingComponent *> positionFollowingComponents)
{
    for (auto positionFollowingComponent: positionFollowingComponents) {
        positionFollowingComponent->hitsCountBeforeFailure = 
            (positionFollowingComponent->hitsCountBeforeFailure + positionFollowingComponent->entity->bouncingBoxComponent.hitsCount) / 2 + random(0,  10);
    }
}

void CollisionSystem::unfreezePositionFollowing(Vector<PositionFollowingComponent*> positionFollowingComponents)
{
    for (auto positionFollowingComponent: positionFollowingComponents) {
        positionFollowingComponent->isFollowing = true;
    }
}

void CollisionSystem::update(Vector<BouncingBoxComponent*> bouncingBoxComponents)
{
    for (int i = 0; i < bouncingBoxComponents.size(); i++) {
        for (int j = i + 1; j < bouncingBoxComponents.size(); j++) {
            Entity *bouncable1 = bouncingBoxComponents[i]->entity;
            Entity *bouncable2 = bouncingBoxComponents[j]->entity;

            if (movesRight(bouncable1) && hitsFromLeft(bouncable1, bouncable2) && areOnSameHeight(bouncable1, bouncable2)) {
                bounceHorizontally(bouncable1);
                bounceHorizontally(bouncable2);
            }

            if (movesLeft(bouncable1) && hitsFromRight(bouncable1, bouncable2) && areOnSameHeight(bouncable1, bouncable2)) {
                bounceHorizontally(bouncable1);
                bounceHorizontally(bouncable2);
            }

            if (movesDown(bouncable1) && hitsFromTop(bouncable1, bouncable2) && areOnSameWidth(bouncable1, bouncable2)) {
                bounceVertically(bouncable1);
                bounceVertically(bouncable2);
            }

            if (movesUp(bouncable1) && hitsFromBottom(bouncable1, bouncable2) && areOnSameWidth(bouncable1, bouncable2)) {
                bounceVertically(bouncable1);
                bounceVertically(bouncable2);
            }
        }
    }
}

void CollisionSystem::afterServiceRequest(Vector<BouncingBoxComponent*> bouncingBoxComponents, Vector<ServiceComponent*> serviceComponents, Vector<PositionFollowingComponent*> positionFollowingComponents)
{
    if (serviceIsRequestedForAnyOf(serviceComponents)) {
        adjustPositionFollowingSkill(positionFollowingComponents);
        resetHitsCounters(bouncingBoxComponents);
        unfreezePositionFollowing(positionFollowingComponents);
    }
}
