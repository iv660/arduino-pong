#include "PongGame.h"

PongGame game;

void setup() {
    game.init();
}

void loop() {
    game.tick();
}