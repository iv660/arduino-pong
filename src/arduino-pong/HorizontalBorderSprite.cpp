#include "HorizontalBorderSprite.h"

void HorizontalBorderSprite::drawOn(ScreenInterface *screen, Position position)
{
    screen->stroke(255, 255, 255);
    screen->fill(255, 255, 255);
    screen->rect(position.x, position.y, getWidth(), getHeight());
}

void HorizontalBorderSprite::eraseFrom(ScreenInterface *screen, Position position)
{
    screen->stroke(0, 0, 0);
    screen->fill(0, 0, 0);
    screen->rect(position.x, position.y, getWidth(), getHeight());
}

int HorizontalBorderSprite::getWidth()
{
    return screen->width();
}

int HorizontalBorderSprite::getHeight()
{
    return height;
}

void HorizontalBorderSprite::setScreen(ScreenInterface *screen)
{
    this->screen = screen;
}
