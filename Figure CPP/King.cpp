#include "King.h"
#include <iostream>

std::vector<Point> King::GetPossibleSteps()
{

    std::vector<Point> possibleSteps;

    if (Row < 7) { possibleSteps.push_back(Point(Row + 1, Column)); }
    if (Row > 0) { possibleSteps.push_back(Point(Row - 1, Column)); }
    
    if (Column < 7) { possibleSteps.push_back(Point(Row, Column + 1)); }
    if (Column > 0) { possibleSteps.push_back(Point(Row, Column - 1)); }

    if (Row > 0 && Column > 0) { possibleSteps.push_back(Point(Row - 1, Column - 1)); }
    if (Row < 7 && Column > 0) { possibleSteps.push_back(Point(Row + 1, Column - 1)); }

    if (Row > 0 && Column < 7) { possibleSteps.push_back(Point(Row - 1, Column + 1)); }
    if (Row < 7 && Column < 7) { possibleSteps.push_back(Point(Row + 1, Column + 1)); }

    return possibleSteps;

}
