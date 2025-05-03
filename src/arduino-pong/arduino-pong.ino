#include <Vector.h>
#include <ApplianceFactory.h>
#include <Appliance.h>
#include <Arduino.h>

#include "PongECSFactory.h"
#include "BallSprite.h"
#include "Position.h"
#include "RenderComponent.h"
#include "RenderSystem.h"
#include "MovementSystem.h"
#include "MovementComponent.h"
#include "Entity.h"
#include "PaddleSprite.h"
#include "BouncingBoxComponent.h"
#include "CollisionSystem.h"
#include "HorizontalBorderSprite.h"
#include "ServiceComponent.h"
#include "ServiceSystem.h"
#include "GoalDetectionSystem.h"
#include "PositionControlComponent.h"
#include "ManualPositionControlSystem.h"
#include "PositionFollowingSystem.h"
#include "PositionFollowingComponent.h"

using XC::Hardware::Appliance;
using XC::SlimPad::ApplianceFactory;

static ApplianceFactory applianceFactory;
static Appliance appliance;

static RenderSystem renderSystem(&appliance);
static MovementSystem movementSystem;
static CollisionSystem collisionSystem;
static ServiceSystem serviceSystem;
static GoalDetectionSystem goalDetectionSystem;
static ManualPositionControlSystem playerControlSystem(&appliance);
static PositionFollowingSystem aiControlSystem;

static PongECSFactory ecsFactory;

void setup() 
{
    applianceFactory.useJoystick().asAnalogJoystick();
    appliance = applianceFactory.createAppliance();  

    ecsFactory.begin(&appliance);  
    
    renderSystem.begin();

    ecsFactory.getLeftPlayerServiceEntity()
        ->serviceComponent.isRequested = true;
}

void loop() 
{
    playerControlSystem.update(
        ecsFactory.getRightPaddleEntity());
    aiControlSystem.update(
        ecsFactory.getLeftPaddleEntity());
    goalDetectionSystem.handle(
        ecsFactory.getBallEntity(), 
        ecsFactory.getGoalComponents());
    collisionSystem.afterServiceRequest(
        ecsFactory.getBouncingBoxComponents(), 
        ecsFactory.getServiceComponents(), 
        ecsFactory.getPositionFollowingComponents());
    serviceSystem.handle(
        ecsFactory.getServiceComponents(), 
        ecsFactory.getBallEntity());
    movementSystem.update(
        ecsFactory.getBallEntity());
    collisionSystem.update(
        ecsFactory.getBouncingBoxComponents());
    renderSystem.redraw(
        ecsFactory.getRenderComponents());
}