#pragma once

#include <Vector.h>
#include <ApplianceFactory.h>
#include <Appliance.h>
#include <Arduino.h>

#include "BallSprite.h"
#include "RenderComponent.h"
#include "Entity.h"
#include "PaddleSprite.h"
#include "BouncingBoxComponent.h"
#include "HorizontalBorderSprite.h"
#include "ServiceComponent.h"
#include "GoalComponent.h"
#include "PositionControlComponent.h"

using XC::Hardware::Appliance;

class PongECSFactory 
{
    private:
        Appliance *appliance;

        BallSprite ballSprite;
        PaddleSprite paddleSprite;
        HorizontalBorderSprite horizontalBorderSprite;

        Entity entitiesStorage[6];
        Vector<Entity> entities;

        RenderComponent renderComponentsStorage[3];
        Vector<RenderComponent> renderComponents;

        BouncingBoxComponent* bouncingBoxComponentsStorage[5];
        Vector<BouncingBoxComponent*> bouncingBoxComponents;

        ServiceComponent* serviceComponentsStorage[2];
        Vector<ServiceComponent*> serviceComponents;

        GoalComponent* goalComponentsStorage[2];
        Vector<GoalComponent*> goalComponents;

        PositionControlComponent* positionControlComponentsStorage[2];
        Vector<PositionControlComponent*> positionControlComponents;

        PositionFollowingComponent* positionFollowingComponentsStorage[1];
        Vector<PositionFollowingComponent*> positionFollowingComponents;

        Entity ball;
        Entity rightPaddle;
        Entity leftPaddle;
        Entity topBorder;
        Entity bottomBorder;
        Entity leftPlayerService;
        Entity rightPlayerService;
        Entity leftPlayerGoal;
        Entity rightPlayerGoal;

        void initializeComponentPools();
        void initializeEntitiesPool();
        void initializeSprites();

        void initializeBallEntity();
        void initializeBordersEntities();
        void initializePaddlesEntities();
        void initializeServiceEntities();
        void initializeGoalEntities();

        void populateEntitiesPool();
        void populateBouncingBoxComponentsPool();
        void populateServiceComponentsPool();
        void populateGoalComponentsPool();
        void populatePositionControlComponentsPool();
        void populatePositionFollowingComponentsPool();

    public:
        begin(Appliance *appliance);
        Vector<Entity> getEntities();

        Vector<RenderComponent> getRenderComponents();
        Vector<BouncingBoxComponent*> getBouncingBoxComponents();
        Vector<ServiceComponent*> getServiceComponents();
        Vector<GoalComponent*> getGoalComponents();
        Vector<PositionControlComponent*> getPositionControlComponents();
        Vector<PositionFollowingComponent*> getPositionFollowingComponents();
        
        Entity *getBallEntity();
        Entity *getRightPaddleEntity();
        Entity *getLeftPaddleEntity();
        Entity *getTopBorderEntity();
        Entity *getBottomBorderEntity();
        Entity *getLeftPlayerServiceEntity();
};

