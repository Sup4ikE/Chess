#pragma once

#include "Point.h"
#include <iostream>
#include <vector>

class Figure
{
public:
    wchar_t Symbol;

    bool IsWhite;

    int Row;
    int Column;

    Figure(wchar_t symbol);

    Figure(wchar_t symbol, bool isWhite, int row, int column);

    virtual std::vector<Point> GetPossibleSteps()
    {
        return {};
    }

    bool IsAvailableToStep(int newRow, int newColumn);
};

