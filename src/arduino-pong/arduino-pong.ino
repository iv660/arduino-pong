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

using XC::Hardware::Appliance;
using XC::SlimPad::ApplianceFactory;

ApplianceFactory applianceFactory;
Appliance appliance;

Entity entitiesStorage[3];
Vector<Entity> entities = Vector<Entity>(entitiesStorage);

RenderSystem renderSystem(&appliance);
MovementSystem movementSystem;
CollisionSystem collisionSystem;
ServiceSystem serviceSystem;
GoalDetectionSystem goalDetectionSystem;

Entity *leftPaddle;
Entity *rightPaddle;
Entity *ball;
Entity *topBorder;
Entity *bottomBorder;
Entity *leftPlayerService;

BallSprite ballSprite;
PaddleSprite paddleSprite;
HorizontalBorderSprite horizontalBorderSprite;

Vector<RenderComponent> renderComponents;
Vector<BouncingBoxComponent> bouncingBoxComponents;
Vector<ServiceComponent*> serviceComponents;
Vector<GoalComponent*> goalComponents;

PongECSFactory ecsFactory;

void setup() 
{
    applianceFactory.useJoystick().asAnalogJoystick();
    appliance = applianceFactory.createAppliance();  

    ecsFactory.begin(&appliance);  
    
    renderSystem.begin();

    entities = ecsFactory.getEntities();
    renderComponents = ecsFactory.getRenderComponents();
    bouncingBoxComponents = ecsFactory.getBouncingBoxComponents();
    serviceComponents = ecsFactory.getServiceComponents();
    goalComponents = ecsFactory.getGoalComponents();

    ball = ecsFactory.getBallEntity();
    rightPaddle = ecsFactory.getRightPaddleEntity();
    leftPaddle = ecsFactory.getLeftPaddleEntity();
    topBorder = ecsFactory.getTopBorderEntity();
    bottomBorder = ecsFactory.getBottomBorderEntity();
    leftPlayerService = ecsFactory.getLeftPlayerServiceEntity();

    leftPlayerService->serviceComponent.isRequested = true;
}

void loop() 
{
    goalDetectionSystem.handle(ball, goalComponents);
    serviceSystem.handle(serviceComponents, ball);
    movementSystem.update(ball);
    collisionSystem.update(bouncingBoxComponents);

    renderSystem.redraw(ball);
    renderSystem.redraw(rightPaddle);
    renderSystem.redraw(leftPaddle);
    renderSystem.redraw(topBorder);
    renderSystem.redraw(bottomBorder);
}