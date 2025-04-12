#include "CollisionSystem.h"

void CollisionSystem::update(Vector<BouncingBoxComponent> bouncingBoxComponents)
{
    for (int i = 0; i < bouncingBoxComponents.size(); i++) {
        for (int j = i + 1; j < bouncingBoxComponents.size(); j++) {
            BouncingBoxComponent bouncable = bouncingBoxComponents[i];
            BouncingBoxComponent surface = bouncingBoxComponents[j];

            if (bouncable.entity->movementComponent.xMovement.velocity > 0
                && bouncable.entity->positionComponent.position.x + bouncable.width >= surface.entity->positionComponent.position.x - 1
            ) {
                bouncable.entity->movementComponent.xMovement.velocity *= -1;
            }
        }
    }
}
