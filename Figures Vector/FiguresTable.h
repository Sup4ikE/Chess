#pragma once
#include <vector>
#include "FiguresTableRow.h"

class FiguresTable
{
public:
    std::vector<FiguresTableRow*> Rows;

    FiguresTable(int rows, int columns)
    {
        for (int i = 0; i < rows; i++)
        {
            Rows.push_back(new FiguresTableRow(columns));
        }
    }
    
};
