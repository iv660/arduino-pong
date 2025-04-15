#pragma once

#include <Vector.h>

#include "Entity.h"
#include "ServiceComponent.h"

class ServiceSystem {
    private:
        const long waitMillis = 750;

        bool isRequestedFor(ServiceComponent* serviceComponent);
        bool isTimeToServe(ServiceComponent* serviceComponent);

        void prepareForService(ServiceComponent* serviceComponent, Entity* ball);
        void serve(ServiceComponent* serviceComponent, Entity* ball);

        int getRandomYVelocity();
    public:
        void handle(Vector<ServiceComponent*> serviceComponents, Entity *ball);
};

