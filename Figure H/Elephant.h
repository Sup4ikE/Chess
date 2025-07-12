#pragma once

#include "Figure.h"

class Elephant : public Figure
{
public:
    Elephant(char symbol, bool isWhite, int row, int column) : Figure(symbol, isWhite, row, column) {}

    std::vector<Point> GetPossibleSteps() override;
};

