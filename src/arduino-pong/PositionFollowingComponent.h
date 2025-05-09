#pragma once

struct Entity;

struct PositionFollowingComponent 
{
    Entity* entity;
    Entity* trackedEntity;

    bool isFollowing = true;
    // int hitsCountBeforeFailure = 7;
};

