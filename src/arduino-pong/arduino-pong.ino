#include <Vector.h>
#include <ApplianceFactory.h>
#include <Appliance.h>

using XC::Hardware::Appliance;
using XC::SlimPad::ApplianceFactory;

class Entity {};
class PositionComponent {};
class VelocityComponent {};
class MovementSystem {};
class RenderSystem {};
class CollisionSystem {};

ApplianceFactory applianceFactory;
Appliance appliance;

Vector<Entity> entities;

Entity leftPaddle;
Entity rightPaddle;
Entity ball;

void setup() {
    applianceFactory.useJoystick().asAnalogJoystick();
    appliance = applianceFactory.createAppliance();

    entities.push_back(leftPaddle);
    entities.push_back(rightPaddle);
    entities.push_back(ball);
}

void loop() {
    
}