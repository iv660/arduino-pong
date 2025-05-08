#include "ScoreSprite.h"

char * ScoreSprite::getScoreString()
{
    return "00 00";
}

void ScoreSprite::drawOn(ScreenInterface* screen, Position position)
{
    screen->stroke(200, 200, 200);
    screen->fill(200, 200, 200);
    screen->textSize(fontSize);
    screen->text(getScoreString(), position.x, position.y);
}

void ScoreSprite::eraseFrom(ScreenInterface* screen, Position position)
{
    screen->stroke(0, 0, 0);
    screen->fill(0, 0, 0);
    screen->textSize(fontSize);
    screen->text(getScoreString(), position.x, position.y);
}

int ScoreSprite::getWidth()
{
    return width;
}

int ScoreSprite::getHeight()
{
    return height;
}