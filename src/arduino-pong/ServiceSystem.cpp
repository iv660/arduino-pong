#include "ServiceSystem.h"

bool ServiceSystem::isRequestedFor(ServiceComponent* serviceComponent)
{
    return serviceComponent->isRequested;
}

bool ServiceSystem::isTimeToServe(ServiceComponent* serviceComponent)
{
    if (serviceComponent->serveAtMillis == 0) {
        return false;
    }

    return millis() >= serviceComponent->serveAtMillis;
}

void ServiceSystem::prepareForService(ServiceComponent *serviceComponent, Entity *ball)
{
    ball->positionComponent.position = serviceComponent->entity->positionComponent.position;
    ball->movementComponent.xMovement.velocity = 0;
    ball->movementComponent.yMovement.velocity = 0;

    serviceComponent->serveAtMillis = millis() + waitMillis;
    serviceComponent->isRequested = false;
}

void ServiceSystem::serve(ServiceComponent *serviceComponent, Entity *ball)
{
    ball->movementComponent.xMovement.velocity = serviceComponent->serviceXVelocity;
    ball->movementComponent.yMovement.velocity = getRandomYVelocity();
    
    serviceComponent->serveAtMillis = 0;
}

int ServiceSystem::getRandomYVelocity()
{
    return random(-2, 2);
}

void ServiceSystem::handle(Vector<ServiceComponent*> serviceComponents, Entity* ball)
{
    for (auto serviceComponent: serviceComponents) {
        if (isRequestedFor(serviceComponent)) {
            prepareForService(serviceComponent, ball);
        }

        if (isTimeToServe(serviceComponent)) {
            serve(serviceComponent, ball); 
        } 
    }
}
