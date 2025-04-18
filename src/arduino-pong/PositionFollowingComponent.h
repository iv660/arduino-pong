#pragma once

struct Entity;

struct PositionFollowingComponent 
{
    Entity* entity;
    Entity* trackedEntity;
};

