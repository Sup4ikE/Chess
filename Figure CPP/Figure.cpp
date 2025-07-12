#include "Figure.h"

Figure::Figure(wchar_t symbol)
{
    this->Symbol = symbol;
}

Figure::Figure(wchar_t symbol, bool isWhite, int row, int column) : Figure(symbol)
{
    this->IsWhite = isWhite;
    this->Row = row;
    this->Column = column;
}

bool Figure::IsAvailableToStep(int newRow, int newColumn)
{
    std::vector<Point> possibleSteps = GetPossibleSteps();

    for (Point step : possibleSteps)
    {
        if (step.x == newRow && step.y == newColumn)
        {
            return true;
        }
    }

    return false;
}
