#pragma once

struct Entity;

struct PositionControlComponent 
{
    struct PositionRange
    {
        int from;
        int to;
    };
    
    Entity *entity;
    PositionRange range = {0, 0};
};
