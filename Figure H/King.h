#pragma once

#include "Figure.h"

class King : public Figure
{
public:
    King(char symbol, bool isWhite, int row, int column) : Figure(symbol, isWhite, row, column) {}

    std::vector<Point> GetPossibleSteps() override;
};
