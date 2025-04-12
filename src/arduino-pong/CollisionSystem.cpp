#include "CollisionSystem.h"

bool CollisionSystem::movesLeft(Entity * entity)
{
    return false;
}

bool CollisionSystem::movesRight(Entity * entity)
{
    return entity->movementComponent.xMovement.velocity > 0;
}

bool CollisionSystem::movesUp(Entity * entity)
{
    return false;
}

bool CollisionSystem::movesDown(Entity * entity)
{
    return false;
}

bool CollisionSystem::hitsFromLeft(Entity * entity1, Entity * entity2)
{
    return entity1->positionComponent.position.x + entity1->bouncingBoxComponent.width >= entity2->positionComponent.position.x - 1;
}

bool CollisionSystem::hitsFromRight(Entity * entity1, Entity * entity2)
{
    return false;
}

bool CollisionSystem::hitsFromTop(Entity * entity1, Entity * entity2)
{
    return false;
}

bool CollisionSystem::hitsFromBottom(Entity * entity1, Entity * entity2)
{
    return false;
}

void CollisionSystem::bounceVertically(Entity *entity)
{
    entity->movementComponent.yMovement.velocity *= -1;
}

void CollisionSystem::bounceHorizontally(Entity *entity)
{
    entity->movementComponent.xMovement.velocity *= -1;
}

void CollisionSystem::update(Vector<BouncingBoxComponent> bouncingBoxComponents)
{
    for (int i = 0; i < bouncingBoxComponents.size(); i++) {
        for (int j = i + 1; j < bouncingBoxComponents.size(); j++) {
            Entity *bouncable1 = bouncingBoxComponents[i].entity;
            Entity *bouncable2 = bouncingBoxComponents[j].entity;

            if (movesRight(bouncable1) && hitsFromLeft(bouncable1, bouncable2)) {
                bounceHorizontally(bouncable1);
                bounceHorizontally(bouncable2);
            }
        }
    }
}
