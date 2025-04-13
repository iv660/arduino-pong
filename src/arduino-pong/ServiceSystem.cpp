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

    Serial.println("Service is prepared");
}

void ServiceSystem::serve(ServiceComponent *serviceComponent, Entity *ball)
{
    ball->movementComponent.xMovement.velocity = serviceComponent->serviceXVelocity;
    ball->movementComponent.yMovement.velocity = -1;
    
    serviceComponent->serveAtMillis = 0;
}

void ServiceSystem::handle(Vector<ServiceComponent*> serviceComponents, Entity* ball)
{
    for (auto serviceComponent: serviceComponents) {
        if (isRequestedFor(serviceComponent)) {
            Serial.println("Service is requested");
            prepareForService(serviceComponent, ball);
            Serial.println("Service is prepared");
        }

        if (isTimeToServe(serviceComponent)) {
            Serial.println("It's time to serve");
            serve(serviceComponent, ball); 
            Serial.println("Ball is served");
        } 
    }
}
