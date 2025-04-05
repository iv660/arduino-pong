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

using XC::Hardware::Appliance;
using XC::SlimPad::ApplianceFactory;

class CollisionSystem {};

ApplianceFactory applianceFactory;
Appliance appliance;

Vector<Entity> entities;

RenderSystem renderSystem(&appliance);
MovementSystem movementSystem;

Entity leftPaddle;
Entity rightPaddle;
Entity ball;

BallSprite ballSprite;

Vector<RenderComponent> renderComponents;

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
}

void loop() {
    movementSystem.update(&ball);
    renderSystem.redraw(&ball);
}