#pragma once

struct Entity;

struct BouncingBoxComponent
{
    int width;
    int height;
    Entity * entity;

    int hitsCount = 0;
};