#pragma once

#include <ScreenInterface.h>

#include "SpriteInterface.h"
#include "Position.h"

using XC::Hardware::ScreenInterface;

class HorizontalBorderSprite: public SpriteInterface 
{
    private:
        ScreenInterface* screen;

        int const height = 2;
    public:
        void drawOn(ScreenInterface* screen, Position position) override;
        void eraseFrom(ScreenInterface* screen, Position position) override;
        int getWidth() override;
        int getHeight() override;

        void setScreen(ScreenInterface* screen);
};

