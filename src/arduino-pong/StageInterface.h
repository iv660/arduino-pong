#pragma once

class StageInterface {
public:
    virtual void init() = 0;
    virtual void tick() = 0;
};
