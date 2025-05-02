#pragma once

#include <ScreenInterface.h>

#include "Position.h"
#include "SpriteInterface.h"

class ScoreSprite: public SpriteInterface
{
    private: 
        int const width = 40;
        int const height = 12;
    public:
        void drawOn(ScreenInterface* screen, Position position): override;
        void eraseFrom(ScreenInterface* screen, Position position) override;

        int getWidth() override;
        int getHeight() override;
};
