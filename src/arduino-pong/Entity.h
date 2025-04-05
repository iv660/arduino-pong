#pragma once

#include "RenderComponent.h"
#include "PositionComponent.h"
#include "MovementComponent.h"

struct Entity {
    PositionComponent positionComponent;
    RenderComponent renderComponent;
    MovementComponent movementComponent;
};