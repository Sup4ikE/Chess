#pragma once

#include "Figure.h"
#include "Point.h"

class Pawn : public Figure
{
public:
    Pawn(char symbol, bool isWhite, int row, int column) : Figure(symbol, isWhite, row, column) {}

    std::vector<Point> GetPossibleSteps() override;
};
