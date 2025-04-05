#pragma once

#include "RenderComponent.h"
#include "PositionComponent.h"

struct Entity {
    PositionComponent positionComponent;
    RenderComponent renderComponent;
};