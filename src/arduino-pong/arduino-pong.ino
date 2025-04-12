#include <Vector.h>
#include <ApplianceFactory.h>
#include <Appliance.h>

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

Vector<Entity> entities;

RenderSystem renderSystem(&appliance);
MovementSystem movementSystem;
CollisionSystem collisionSystem;

Entity leftPaddle;
Entity rightPaddle;
Entity ball;

BallSprite ballSprite;
PaddleSprite paddleSprite;

Vector<RenderComponent> renderComponents;
Vector<BouncingBoxComponent*> bouncingBoxComponents;

void setup() {
    applianceFactory.useJoystick().asAnalogJoystick();
    appliance = applianceFactory.createAppliance();

    entities.push_back(leftPaddle);
    entities.push_back(rightPaddle);
    entities.push_back(ball);

    renderSystem.begin();

    ball.renderComponent.sprite = &ballSprite;
    ball.positionComponent.position = {45, 60};
    ball.movementComponent.velocity = {3, -1};
    ball.bouncingBoxComponent.width = ballSprite.getWidth();
    ball.bouncingBoxComponent.height = ballSprite.getHeight();
    ball.bouncingBoxComponent.entity = &ball;
    bouncingBoxComponents.push_back(&ball.bouncingBoxComponent);

    rightPaddle.renderComponent.sprite = &paddleSprite;
    rightPaddle.positionComponent.position = {152, 0};
    rightPaddle.bouncingBoxComponent.width = paddleSprite.getWidth();
    rightPaddle.bouncingBoxComponent.height = paddleSprite.getHeight();
    rightPaddle.bouncingBoxComponent.entity = &rightPaddle;
    bouncingBoxComponents.push_back(&rightPaddle.bouncingBoxComponent);
}

void loop() {
    collisionSystem.update(bouncingBoxComponents);

    movementSystem.update(&ball);

    renderSystem.redraw(&ball);
    renderSystem.redraw(&rightPaddle);
}