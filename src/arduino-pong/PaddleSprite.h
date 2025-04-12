#pragma once

#include <ScreenInterface.h>

#include "Position.h"
#include "SpriteInterface.h"

using XC::Hardware::ScreenInterface;

class PaddleSprite: public SpriteInterface
{
    private:
        int const width = 4;
        int const height = 24;
    public:
        void drawOn(ScreenInterface* screen, Position position) override;
        void eraseFrom(ScreenInterface* screen, Position position) override;

        int getWidth() override;
        int getHeight() override;
};