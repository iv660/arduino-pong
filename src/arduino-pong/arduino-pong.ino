#include <Vector.h>
#include <ApplianceFactory.h>
#include <Appliance.h>
#include <Arduino.h>

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

using XC::Hardware::Appliance;
using XC::SlimPad::ApplianceFactory;

ApplianceFactory applianceFactory;
Appliance appliance;

Entity entitiesStorage[3];
Vector<Entity> entities = Vector<Entity>(entitiesStorage);

RenderSystem renderSystem(&appliance);
MovementSystem movementSystem;
CollisionSystem collisionSystem;

Entity leftPaddle;
Entity rightPaddle;
Entity ball;

BallSprite ballSprite;
PaddleSprite paddleSprite;

RenderComponent renderComponentsStorage[3];
Vector<RenderComponent> renderComponents = 
    Vector<RenderComponent>(renderComponentsStorage);

BouncingBoxComponent bouncingBoxComponentsStorage[2];
Vector<BouncingBoxComponent> bouncingBoxComponents = 
    Vector<BouncingBoxComponent>(bouncingBoxComponentsStorage);

void setup() {
    applianceFactory.useJoystick().asAnalogJoystick();
    appliance = applianceFactory.createAppliance();

    renderSystem.begin();

    ball.renderComponent.sprite = &ballSprite;
    ball.positionComponent.position = {45, 60};
    ball.movementComponent.xMovement.velocity = 3;
    ball.movementComponent.yMovement.velocity = -1;
    ball.bouncingBoxComponent.width = ballSprite.getWidth();
    ball.bouncingBoxComponent.height = ballSprite.getHeight();
    ball.bouncingBoxComponent.entity = &ball;

    rightPaddle.renderComponent.sprite = &paddleSprite;
    rightPaddle.positionComponent.position = {156, 80};
    rightPaddle.bouncingBoxComponent.width = paddleSprite.getWidth();
    rightPaddle.bouncingBoxComponent.height = paddleSprite.getHeight();
    rightPaddle.bouncingBoxComponent.entity = &rightPaddle;

    entities.push_back(leftPaddle);
    entities.push_back(rightPaddle);
    entities.push_back(ball);

    bouncingBoxComponents.push_back(ball.bouncingBoxComponent);
    bouncingBoxComponents.push_back(rightPaddle.bouncingBoxComponent);
}

void loop() {
    collisionSystem.update(bouncingBoxComponents);

    movementSystem.update(&ball);

    renderSystem.redraw(&ball);
    renderSystem.redraw(&rightPaddle);
}