#include "CollisionSystem.h"

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
    return entity1->positionComponent.position.x + entity1->bouncingBoxComponent.width == entity2->positionComponent.position.x - 1;
}
bool CollisionSystem::hitsFromRight(Entity * entity1, Entity * entity2)
{
    return entity1->positionComponent.position.x == entity2->positionComponent.position.x + entity2->bouncingBoxComponent.width + 1;
}

bool CollisionSystem::hitsFromTop(Entity * entity1, Entity * entity2)
{
    return entity1->positionComponent.position.y + entity1->bouncingBoxComponent.height == entity2->positionComponent.position.y - 1;
}

bool CollisionSystem::hitsFromBottom(Entity * entity1, Entity * entity2)
{
    return entity1->positionComponent.position.y == entity2->positionComponent.position.y + entity2->bouncingBoxComponent.height + 1;
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

            if (movesLeft(bouncable1) && hitsFromRight(bouncable1, bouncable2)) {
                bounceHorizontally(bouncable1);
                bounceHorizontally(bouncable2);
            }

            if (movesDown(bouncable1) && hitsFromTop(bouncable1, bouncable2)) {
                bounceVertically(bouncable1);
                bounceVertically(bouncable2);
            }

            if (movesUp(bouncable1) && hitsFromBottom(bouncable1, bouncable2)) {
                bounceVertically(bouncable1);
                bounceVertically(bouncable2);
            }
        }
    }
}
