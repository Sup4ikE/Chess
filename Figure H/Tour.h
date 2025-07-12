#pragma once

#include "Figure.h"

class Tour : public Figure
{
public:
    Tour(char symbol, bool isWhite, int row, int column) : Figure(symbol, isWhite, row, column) {}

    std::vector<Point> GetPossibleSteps() override;
};

