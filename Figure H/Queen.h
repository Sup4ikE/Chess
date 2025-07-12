#pragma once

#include "Figure.h"

class Queen : public Figure
{
public:
    Queen(char symbol, bool isWhite, int row, int column) : Figure(symbol, isWhite, row, column) {}

    std::vector<Point> GetPossibleSteps() override;
};

