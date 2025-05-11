#pragma once

#include <ApplianceFactory.h>
#include <Appliance.h>

#include "PongECSFactory.h"
#include "RenderSystem.h"
#include "MovementSystem.h"
#include "CollisionSystem.h"
#include "ServiceSystem.h"
#include "GoalDetectionSystem.h"
#include "ManualPositionControlSystem.h"
#include "PositionFollowingSystem.h"

using XC::Hardware::Appliance;
using XC::SlimPad::ApplianceFactory;

class PongGame {
    private:
        ApplianceFactory applianceFactory;
        Appliance appliance;

        RenderSystem renderSystem{&appliance};
        MovementSystem movementSystem;
        CollisionSystem collisionSystem;
        ServiceSystem serviceSystem;
        GoalDetectionSystem goalDetectionSystem;
        ManualPositionControlSystem playerControlSystem{&appliance};
        PositionFollowingSystem aiControlSystem;

        PongECSFactory ecsFactory;

    public:
        void init();
        void tick();
};
