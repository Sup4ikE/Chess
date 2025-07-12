#include "Tour.h"
#include <iostream>

std::vector<Point> Tour::GetPossibleSteps()
{
    std::vector<Point> possibleSteps;

    for (int i = Row - 1; i >= 0; i--)
    {
        possibleSteps.push_back(Point(i, Column));
    }

    for (int i = Row + 1; i < 8; i++)
    {
        possibleSteps.push_back(Point(i, Column));
    }

    for (int i = Column - 1; i >= 0; i--)
    {
        possibleSteps.push_back(Point(Row, i));
    }

    for (int i = Column + 1; i < 8; i++)
    {
        possibleSteps.push_back(Point(Row, i));
    }

    return possibleSteps;
}
