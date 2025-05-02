#include "ScoreSprite.h"

void ScoreSprite::drawOn(ScreenInterface* screen, Position position)
{
    screen->stroke(100, 100, 100);
    screen->fill(100, 100, 100);
    screen->rect(position.x, position.y, width, height);
}

void ScoreSprite::eraseFrom(ScreenInterface* screen, Position position)
{
    screen->stroke(0, 0, 0);
    screen->fill(0, 0, 0);
    screen->rect(position.x, position.y, width, height);
}

int ScoreSprite::getWidth()
{
    return width;
}

int ScoreSprite::getHeight()
{
    return height;
}