#pragma once

struct Position
{
    int x;  
    int y;
    
    bool operator == (Position const& other) const { 
        return x == other.x && y == other.y; 
    }

    bool operator != (Position const& other) const { 
        return x != other.x || y != other.y; 
    }
};