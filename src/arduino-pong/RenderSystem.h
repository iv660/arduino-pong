#pragma once

#include <Appliance.h>

#include "RenderComponent.h"
#include "Entity.h"

using XC::Hardware::Appliance;

class RenderSystem
{
    private:
        Appliance* appliance;
        inline bool hasMoved(Entity* entity);
    public:
        RenderSystem(Appliance* appliance) : appliance(appliance) {};

        void begin();
        void redraw(Entity* entity);
};