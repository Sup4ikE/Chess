#include "Pawn.h"

std::vector<Point> Pawn::GetPossibleSteps()
{
    std::vector<Point> possibleSteps;

    int direction = 1;

    if (!IsWhite)
    {
        direction = -1;
    }

    possibleSteps.push_back(Point(Row + direction, Column));

    if (Row == 1 || Row == 6)
    {
        possibleSteps.push_back(Point(Row + direction * 2, Column));
    }

    possibleSteps.push_back(Point(Row + direction, Column + 1));
    possibleSteps.push_back(Point(Row + direction, Column - 1));
    
    return possibleSteps;
}
