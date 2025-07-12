#pragma once

#include "Figure.h"

class Horse : public Figure
{
public:
    Horse(char symbol, bool isWhite, int row, int column) : Figure(symbol, isWhite, row, column) {}

    std::vector<Point> GetPossibleSteps() override;
};
