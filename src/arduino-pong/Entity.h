#pragma once

#include "RenderComponent.h"
#include "PositionComponent.h"
#include "MovementComponent.h"
#include "BouncingBoxComponent.h"
#include "ServiceComponent.h"
#include "GoalComponent.h"
#include "PositionControlComponent.h"
#include "PositionFollowingComponent.h"
#include "CounterComponent.h"

struct Entity {
    PositionComponent positionComponent;
    RenderComponent renderComponent;
    MovementComponent movementComponent;
    BouncingBoxComponent bouncingBoxComponent;
    ServiceComponent serviceComponent;
    GoalComponent goalComponent;
    PositionControlComponent positionControlComponent;
    PositionFollowingComponent positionFollowingComponent;
    CounterComponent counterComponent;
};
