#pragma once

struct Point
{
    int x;
    int y;

    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    
    bool operator==(const Point& other) const
    {
        return x == other.x && y == other.y;
    }
};

