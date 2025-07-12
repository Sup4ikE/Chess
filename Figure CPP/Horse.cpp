#include "Horse.h"
#include <iostream>

std::vector<Point> Horse::GetPossibleSteps()
{

    std::vector<Point> possibleSteps;

    if (Row - 2 >= 0 && Column + 1 < 8)
        possibleSteps.push_back(Point(Row - 2, Column + 1));
    if (Row - 2 >= 0 && Column - 1 >= 0)
        possibleSteps.push_back(Point(Row - 2, Column - 1));
    if (Row - 1 >= 0 && Column + 2 < 8)
        possibleSteps.push_back(Point(Row - 1, Column + 2));
    if (Row - 1 >= 0 && Column - 2 >= 0)
        possibleSteps.push_back(Point(Row - 1, Column - 2));
    if (Row + 2 < 8 && Column + 1 < 8)
        possibleSteps.push_back(Point(Row + 2, Column + 1));
    if (Row + 2 < 8 && Column - 1 >= 0)
        possibleSteps.push_back(Point(Row + 2, Column - 1));
    if (Row + 1 < 8 && Column + 2 < 8)
        possibleSteps.push_back(Point(Row + 1, Column + 2));
    if (Row + 1 < 8 && Column - 2 >= 0)
        possibleSteps.push_back(Point(Row + 1, Column - 2));

    return possibleSteps;

}
