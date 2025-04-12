#include "BallSprite.h"

void BallSprite::drawOn(ScreenInterface *screen, Position position)
{
    screen->stroke(255, 255, 255);
    screen->fill(255, 255, 255);
    screen->rect(position.x, position.y, size, size);
}

void BallSprite::eraseFrom(ScreenInterface *screen, Position position)
{
    screen->stroke(0, 0, 0);
    screen->fill(0, 0, 0);
    screen->rect(position.x, position.y, size, size);
}

int BallSprite::getWidth()
{
    return size;
}

int BallSprite::getHeight()
{
    return size;
}
