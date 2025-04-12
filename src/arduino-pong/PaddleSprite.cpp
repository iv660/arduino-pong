#include "PaddleSprite.h"

void PaddleSprite::drawOn(ScreenInterface *screen, Position position)
{
    screen->stroke(255, 255, 255);
    screen->fill(255, 255, 255);
    screen->rect(position.x, position.y, width, height);
}

void PaddleSprite::eraseFrom(ScreenInterface *screen, Position position)
{
    screen->stroke(0, 0, 0);
    screen->fill(0, 0, 0);
    screen->rect(position.x, position.y, width, height);
}

int PaddleSprite::getWidth()
{
    return width;
}

int PaddleSprite::getHeight()
{
    return height;
}
