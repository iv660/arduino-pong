#include "ScoreSprite.h"

#include <stdio.h>

char* ScoreSprite::getScoreString()
{
    static char scoreString[6];
    snprintf(scoreString, sizeof(scoreString), "%02d %02d", leftCounterComponent->value, rightCounterComponent->value);
    return scoreString;
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
