#pragma once

#include <Appliance.h>
#include <Vector.h>

#include "RenderComponent.h"
#include "Entity.h"

using XC::Hardware::Appliance;

class RenderSystem
{
    private:
        Appliance* appliance;
        inline bool hasMoved(Entity* entity);

        void redraw(Entity* entity, Vector<RenderComponent*> otherComponents);

        void redrawBackgroundComponents(Vector<RenderComponent*> components, RenderComponent* erasedCompnent);
        bool overlaps(RenderComponent* component1, RenderComponent* component2);
    public:
        RenderSystem(Appliance* appliance) : appliance(appliance) {};

        void begin();
        void redraw(Vector<RenderComponent*> components);
};