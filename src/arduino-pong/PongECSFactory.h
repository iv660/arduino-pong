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

using XC::Hardware::Appliance;

class PongECSFactory 
{
    private:
        Appliance *appliance;
        BallSprite ballSprite;
        PaddleSprite paddleSprite;
        HorizontalBorderSprite horizontalBorderSprite;

        Entity entitiesStorage[3];
        Vector<Entity> entities;

        RenderComponent renderComponentsStorage[3];
        Vector<RenderComponent> renderComponents;

        BouncingBoxComponent bouncingBoxComponentsStorage[5];
        Vector<BouncingBoxComponent> bouncingBoxComponents;

        Entity ball;
        Entity rightPaddle;
        Entity leftPaddle;
        Entity topBorder;
        Entity bottomBorder;

    public:
        begin(Appliance *appliance);
        Vector<Entity> getEntities();
        Vector<RenderComponent> getRenderComponents();
        Vector<BouncingBoxComponent> getBouncingBoxComponents();
        Entity *getBallEntity();
        Entity *getRightPaddleEntity();
        Entity *getLeftPaddleEntity();
        Entity *getTopBorderEntity();
        Entity *getBottomBorderEntity();
};

