#pragma once

#include <Appliance.h>
#include <Vector.h>

#include "PositionControlComponent.h"
#include "Entity.h"

using XC::Hardware::Appliance;

class ManualPositionControlSystem 
{
    private:
        Appliance* appliance;
    public:
        ManualPositionControlSystem(Appliance* appliance): appliance(appliance) {};

        void update(Entity* entity);
};
