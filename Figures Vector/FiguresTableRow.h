#pragma once
#include <vector>
#include "Figure.h"

class FiguresTableRow
{
public:
    std::vector<Figure*> Columns;

    FiguresTableRow(int size)
    {
        for (int i = 0; i < size; i++)
        {
            Columns.push_back(new Figure(' '));
        }
    }
    
};
