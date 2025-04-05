#include "BallSprite.h"

void BallSprite::drawOn(ScreenInterface *screen, Position position)
{
    screen->stroke(255, 255, 255);
    screen->rect(position.x, position.y, size, size);
}

void BallSprite::eraseFrom(ScreenInterface *screen, Position position)
{
    screen->stroke(0, 0, 0);
    screen->rect(position.x, position.y, size, size);
}
