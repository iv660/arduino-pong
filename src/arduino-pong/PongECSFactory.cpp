#include "PongECSFactory.h"

using XC::Hardware::Appliance;

PongECSFactory::begin(Appliance *appliance) {
    renderComponents = Vector<RenderComponent>(renderComponentsStorage);
    bouncingBoxComponents = Vector<BouncingBoxComponent>(bouncingBoxComponentsStorage);
    entities = Vector<Entity>(entitiesStorage);

    this->appliance = appliance;
    horizontalBorderSprite.setScreen(appliance->screen);

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
    bottomBorder.positionComponent.position = {0, appliance->screen->height() - horizontalBorderSprite.getHeight()};
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

Vector<Entity> PongECSFactory::getEntities() {
    return entities;
}

Vector<RenderComponent> PongECSFactory::getRenderComponents() {
    return renderComponents;
}

Vector<BouncingBoxComponent> PongECSFactory::getBouncingBoxComponents() {
    return bouncingBoxComponents;
}

Entity *PongECSFactory::getBallEntity() {
    return &ball;
}

Entity *PongECSFactory::getRightPaddleEntity() {
    return &rightPaddle;
}

Entity *PongECSFactory::getLeftPaddleEntity() {
    return &leftPaddle;
}

Entity *PongECSFactory::getTopBorderEntity() {
    return &topBorder;
}

Entity *PongECSFactory::getBottomBorderEntity() {
    return &bottomBorder;
}
