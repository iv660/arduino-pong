#include "PongECSFactory.h"

using XC::Hardware::Appliance;
 
void PongECSFactory::initializeEntitiesPool()
{
    entities = Vector<Entity>(entitiesStorage);
}

void PongECSFactory::initializeSprites()
{  
    horizontalBorderSprite.setScreen(appliance->screen);
}

void PongECSFactory::initializeScoreEntity() 
{
    score.renderComponent.sprite = &scoreSprite;

    score.positionComponent.position = {appliance->screen->width() / 2 - scoreSprite.getWidth() / 2, 10};

    score.renderComponent.entity = &score;
}

void PongECSFactory::initializeBallEntity()
{
    ball.renderComponent.sprite = &ballSprite;

    ball.positionComponent.position = {45, 60};
    ball.movementComponent.xMovement.velocity = 0;
    ball.movementComponent.yMovement.velocity = 0;
    ball.bouncingBoxComponent.width = ballSprite.getWidth();
    ball.bouncingBoxComponent.height = ballSprite.getHeight();

    ball.bouncingBoxComponent.entity = &ball;
    ball.renderComponent.entity = &ball;
}

void PongECSFactory::initializeBordersEntities()
{
    topBorder.renderComponent.sprite = &horizontalBorderSprite;

    topBorder.positionComponent.position = {0, 0};
    topBorder.bouncingBoxComponent.width = horizontalBorderSprite.getWidth();
    topBorder.bouncingBoxComponent.height = horizontalBorderSprite.getHeight();

    topBorder.bouncingBoxComponent.entity = &topBorder;
    topBorder.renderComponent.entity = &topBorder;

    bottomBorder.renderComponent.sprite = &horizontalBorderSprite;

    bottomBorder.positionComponent.position = {0, appliance->screen->height() - horizontalBorderSprite.getHeight()};
    bottomBorder.bouncingBoxComponent.width = horizontalBorderSprite.getWidth();
    bottomBorder.bouncingBoxComponent.height = horizontalBorderSprite.getHeight();

    bottomBorder.bouncingBoxComponent.entity = &bottomBorder;
    bottomBorder.renderComponent.entity = &bottomBorder;
}

void PongECSFactory::initializePaddlesEntities()
{
    leftPaddle.renderComponent.sprite = &paddleSprite;

    leftPaddle.positionComponent.position = {0, horizontalBorderSprite.getHeight() + 1};
    leftPaddle.bouncingBoxComponent.width = paddleSprite.getWidth();
    leftPaddle.bouncingBoxComponent.height = paddleSprite.getHeight();
    
    rightPaddle.renderComponent.sprite = &paddleSprite;
    
    rightPaddle.positionComponent.position = {156, 3};
    rightPaddle.bouncingBoxComponent.width = paddleSprite.getWidth();
    rightPaddle.bouncingBoxComponent.height = paddleSprite.getHeight();
    
    
    // This code requires the components' sprite to be initialized first
    // Don't move the code above the initialization of paddles components
    leftPaddle.positionControlComponent.range = {
        topBorder.positionComponent.position.y + topBorder.renderComponent.sprite->getHeight() + 1,
        appliance->screen->height() - leftPaddle.renderComponent.sprite->getHeight() - (bottomBorder.renderComponent.sprite->getHeight() + 1)
    };
    rightPaddle.positionControlComponent.range = {
        topBorder.positionComponent.position.y + topBorder.renderComponent.sprite->getHeight() + 1,
        appliance->screen->height() - rightPaddle.renderComponent.sprite->getHeight() - (bottomBorder.renderComponent.sprite->getHeight() + 1)
    };
    
    leftPaddle.positionFollowingComponent.entity = &leftPaddle;
    leftPaddle.positionFollowingComponent.trackedEntity = &ball;
    leftPaddle.positionFollowingComponent.isFollowing = true;
    
    leftPaddle.bouncingBoxComponent.entity = &leftPaddle;
    leftPaddle.positionControlComponent.entity = &leftPaddle;
    rightPaddle.bouncingBoxComponent.entity = &rightPaddle;
    rightPaddle.positionControlComponent.entity = &rightPaddle;
    rightPaddle.renderComponent.entity = &rightPaddle;
    leftPaddle.renderComponent.entity = &leftPaddle;
}

void PongECSFactory::initializeServiceEntities()
{
    leftPlayerService.positionComponent.position = {
        45, 
        appliance->screen->height() / 2 - ball.renderComponent.sprite->getHeight() / 2
    };
    leftPlayerService.serviceComponent.serviceXVelocity = 30;
    leftPlayerService.serviceComponent.entity = &leftPlayerService;

    rightPlayerService.positionComponent.position = {
        appliance->screen->width() - 45, 
        appliance->screen->height() / 2 - ball.renderComponent.sprite->getHeight() / 2
    };
    rightPlayerService.serviceComponent.serviceXVelocity = -30;
    rightPlayerService.serviceComponent.entity = &rightPlayerService;
}

void PongECSFactory::initializeGoalEntities()
{
    leftPlayerGoal.positionComponent.position = {0, 0};
    leftPlayerGoal.goalComponent.height = appliance->screen->height();
    leftPlayerGoal.goalComponent.service = &leftPlayerService;
    leftPlayerGoal.goalComponent.entity = &leftPlayerGoal;

    rightPlayerGoal.positionComponent.position = {appliance->screen->width(), 0};
    rightPlayerGoal.goalComponent.height = appliance->screen->height();
    rightPlayerGoal.goalComponent.service = &rightPlayerService;
    rightPlayerGoal.goalComponent.entity = &rightPlayerGoal;
}

void PongECSFactory::populateEntitiesPool()
{
    entities.push_back(leftPaddle);
    entities.push_back(rightPaddle);
    entities.push_back(ball);
    entities.push_back(topBorder);
    entities.push_back(bottomBorder);
    entities.push_back(leftPlayerService);
    entities.push_back(rightPlayerService);
    entities.push_back(leftPlayerGoal);
    entities.push_back(rightPlayerGoal);
    entities.push_back(score);
}

void PongECSFactory::populateBouncingBoxComponentsPool()
{
    bouncingBoxComponents.push_back(&ball.bouncingBoxComponent);
    bouncingBoxComponents.push_back(&rightPaddle.bouncingBoxComponent);
    bouncingBoxComponents.push_back(&leftPaddle.bouncingBoxComponent);
    bouncingBoxComponents.push_back(&topBorder.bouncingBoxComponent);
    bouncingBoxComponents.push_back(&bottomBorder.bouncingBoxComponent);
}

void PongECSFactory::populateServiceComponentsPool()
{
    serviceComponents.push_back(&leftPlayerService.serviceComponent);
    serviceComponents.push_back(&rightPlayerService.serviceComponent);
}

void PongECSFactory::populateGoalComponentsPool()
{
    goalComponents.push_back(&leftPlayerGoal.goalComponent);
    goalComponents.push_back(&rightPlayerGoal.goalComponent);
}

void PongECSFactory::populatePositionControlComponentsPool()
{
    positionControlComponents.push_back(&leftPaddle.positionControlComponent);
    positionControlComponents.push_back(&rightPaddle.positionControlComponent);
}

void PongECSFactory::populatePositionFollowingComponentsPool()
{
    positionFollowingComponents.push_back(&leftPaddle.positionFollowingComponent);
}

void PongECSFactory::initializeComponentPools()
{
    renderComponents = Vector<RenderComponent*>(renderComponentsStorage);
    bouncingBoxComponents = Vector<BouncingBoxComponent*>(bouncingBoxComponentsStorage);
    serviceComponents = Vector<ServiceComponent*>(serviceComponentsStorage);
    goalComponents = Vector<GoalComponent*>(goalComponentsStorage);
    positionControlComponents = Vector<PositionControlComponent*>(positionControlComponentsStorage);
    positionFollowingComponents = Vector<PositionFollowingComponent*>(positionFollowingComponentsStorage);
}

PongECSFactory::begin(Appliance *appliance) 
{
    this->appliance = appliance;

    initializeComponentPools();
    initializeEntitiesPool();
    initializeSprites();
    
    initializeBallEntity();
    initializeBordersEntities();
    initializePaddlesEntities();
    initializeServiceEntities();
    initializeGoalEntities();
    initializeScoreEntity();

    populateEntitiesPool();
    populateBouncingBoxComponentsPool();
    populateServiceComponentsPool();
    populateGoalComponentsPool();
    populatePositionControlComponentsPool();
    populatePositionFollowingComponentsPool();
}

Vector<Entity> PongECSFactory::getEntities() {
    return entities;
}

Vector<RenderComponent*> PongECSFactory::getRenderComponents() {
    return renderComponents;
}

Vector<BouncingBoxComponent*> PongECSFactory::getBouncingBoxComponents() {
    return bouncingBoxComponents;
}

Vector<ServiceComponent*> PongECSFactory::getServiceComponents()
{
    return serviceComponents;
}

Vector<GoalComponent*> PongECSFactory::getGoalComponents()
{
    return goalComponents;
}

Vector<PositionControlComponent*> PongECSFactory::getPositionControlComponents()
{
    return positionControlComponents;
}

Vector<PositionFollowingComponent*> PongECSFactory::getPositionFollowingComponents()
{
    return positionFollowingComponents;
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

Entity * PongECSFactory::getLeftPlayerServiceEntity()
{
    return &leftPlayerService;
}

Entity *PongECSFactory::getScoreEntity()
{
    return &score;
}