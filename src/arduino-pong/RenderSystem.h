#pragma once

#include <Appliance.h>

#include "RenderComponent.h"

using XC::Hardware::Appliance;

class RenderSystem
{
    private:
        Appliance* appliance;
    public:
        RenderSystem(Appliance* appliance) : appliance(appliance) {};

        void begin();
        void update(RenderComponent* renderComponent);
};