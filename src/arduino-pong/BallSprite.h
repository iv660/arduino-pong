#pragma once

#include <ScreenInterface.h>

#include "Position.h"
#include "SpriteInterface.h"

using XC::Hardware::ScreenInterface;

class BallSprite: public SpriteInterface
{
    private:
        int const size = 8;
    public:
        void drawOn(ScreenInterface* screen, Position position);
};
