#pragma once

#include <ScreenInterface.h>

#include "Position.h"
#include "SpriteInterface.h"
#include "CounterComponent.h"

class ScoreSprite: public SpriteInterface
{
    private: 
        int const width = 30;
        int const height = 10;
        int const fontSize = 1;

        char* getScoreString();
        
    public:
        CounterComponent* leftCounterComponent;
        CounterComponent* rightCounterComponent;

        void drawOn(ScreenInterface* screen, Position position) override;
        void eraseFrom(ScreenInterface* screen, Position position) override;

        int getWidth() override;
        int getHeight() override;
};
