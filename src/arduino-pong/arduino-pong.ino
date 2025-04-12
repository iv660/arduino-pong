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
#include "HorizontalBorderSprite.h"

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
Entity topBorder;
Entity bottomBorder;

BallSprite ballSprite;
PaddleSprite paddleSprite;
HorizontalBorderSprite horizontalBorderSprite;

RenderComponent renderComponentsStorage[3];
Vector<RenderComponent> renderComponents = 
    Vector<RenderComponent>(renderComponentsStorage);

BouncingBoxComponent bouncingBoxComponentsStorage[5];
Vector<BouncingBoxComponent> bouncingBoxComponents = 
    Vector<BouncingBoxComponent>(bouncingBoxComponentsStorage);


void setup() {
    applianceFactory.useJoystick().asAnalogJoystick();
    appliance = applianceFactory.createAppliance();

    horizontalBorderSprite.setScreen(appliance.screen);

    renderSystem.begin();

    ball.renderComponent.sprite = &ballSprite;
    ball.positionComponent.position = {45, 60};
    ball.movementComponent.xMovement.velocity = 3;
    ball.movementComponent.yMovement.velocity = -1;
    ball.bouncingBoxComponent.width = ballSprite.getWidth();
    ball.bouncingBoxComponent.height = ballSprite.getHeight();
    ball.bouncingBoxComponent.entity = &ball;

    rightPaddle.renderComponent.sprite = &paddleSprite;
    rightPaddle.positionComponent.position = {156, 3};
    rightPaddle.bouncingBoxComponent.width = paddleSprite.getWidth();
    rightPaddle.bouncingBoxComponent.height = paddleSprite.getHeight();
    rightPaddle.bouncingBoxComponent.entity = &rightPaddle;

    leftPaddle.renderComponent.sprite = &paddleSprite;
    leftPaddle.positionComponent.position = {0, horizontalBorderSprite.getHeight() + 1};
    leftPaddle.bouncingBoxComponent.width = paddleSprite.getWidth();
    leftPaddle.bouncingBoxComponent.height = paddleSprite.getHeight();
    leftPaddle.bouncingBoxComponent.entity = &leftPaddle;

    topBorder.renderComponent.sprite = &horizontalBorderSprite;
    topBorder.positionComponent.position = {0, 0};
    topBorder.bouncingBoxComponent.width = horizontalBorderSprite.getWidth();
    topBorder.bouncingBoxComponent.height = horizontalBorderSprite.getHeight();
    topBorder.bouncingBoxComponent.entity = &topBorder;

    bottomBorder.renderComponent.sprite = &horizontalBorderSprite;
    bottomBorder.positionComponent.position = {0, appliance.screen->height() - horizontalBorderSprite.getHeight()};
    bottomBorder.bouncingBoxComponent.width = horizontalBorderSprite.getWidth();
    bottomBorder.bouncingBoxComponent.height = horizontalBorderSprite.getHeight();
    bottomBorder.bouncingBoxComponent.entity = &bottomBorder;

    entities.push_back(leftPaddle);
    entities.push_back(rightPaddle);
    entities.push_back(ball);
    entities.push_back(topBorder);
    entities.push_back(bottomBorder);

    bouncingBoxComponents.push_back(ball.bouncingBoxComponent);
    bouncingBoxComponents.push_back(rightPaddle.bouncingBoxComponent);
    bouncingBoxComponents.push_back(leftPaddle.bouncingBoxComponent);
    bouncingBoxComponents.push_back(topBorder.bouncingBoxComponent);
    bouncingBoxComponents.push_back(bottomBorder.bouncingBoxComponent);
}

void loop() {
    collisionSystem.update(bouncingBoxComponents);

    movementSystem.update(&ball);

    renderSystem.redraw(&ball);
    renderSystem.redraw(&rightPaddle);
    renderSystem.redraw(&leftPaddle);
    renderSystem.redraw(&topBorder);
    renderSystem.redraw(&bottomBorder);
}