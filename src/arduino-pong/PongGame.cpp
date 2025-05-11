#include "PongGame.h"

void PongGame::init() {
    applianceFactory.useJoystick().asAnalogJoystick();
    appliance = applianceFactory.createAppliance();  

    ecsFactory.begin(&appliance);  
    
    renderSystem.begin();

    ecsFactory.getLeftPlayerServiceEntity()
        ->serviceComponent->isRequested = true;
}

void PongGame::tick() {
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
