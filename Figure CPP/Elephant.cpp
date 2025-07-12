#include "Elephant.h"
#include <iostream>

std::vector<Point> Elephant::GetPossibleSteps()
{
    std::vector<Point> possibleSteps;

    int iter = 0;

    for(int i = Row - 1; i >= 0; i--)
    {
        iter++;

        if(Column + iter >= 0 && Column + iter <= 7)
        {
            possibleSteps.push_back(Point(i, Column + iter));
        }
    }
    iter = 0;

    for (int i = Row - 1; i >= 0; i--)
    {
        iter++;

        if (Column - iter >= 0 && Column - iter < 7)
        {
            possibleSteps.push_back(Point(i, Column - iter));
        }
    }
    iter = 0;

    for (int i = Row + 1; i <= 7; i++)
    {
        iter++;

        if (Column + iter <= 7)
        {
            possibleSteps.push_back(Point(i, Column + iter));
        }
    }
    iter = 0;

    for (int i = Row + 1; i <= 7; i++)
    {
        iter++;

        if (Column - iter >= 0)
        {
            possibleSteps.push_back(Point(i, Column - iter));
        }
    }
    iter = 0;

    return possibleSteps;
}
