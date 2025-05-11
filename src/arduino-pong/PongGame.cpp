#include "PongGame.h"
#include "PlayGameStage.h"

void PongGame::init() {
    stage = new PlayGameStage();
    stage->init();
}

void PongGame::tick() {
    stage->tick();
}
