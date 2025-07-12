#pragma once

#include "FiguresTable.h"
#include "Pawn.h"
#include "Tour.h"
#include "Horse.h"
#include "Elephant.h"
#include "Queen.h"
#include "King.h"

#include <iostream>

class Board {
public:
    static const int ROWS = 8;
    static const int COLUMNS = 8;

    FiguresTable* BoardInfo;

    Board();

    void output_board();

    void Step(int row, int column, int newRow, int newColumn);

    void DisplayPossibleSteps(int row, int column, bool IsWhite);
    
    void delete_paths();
    
    void Beat(int row, int column, int newRow, int newColumn, std::vector<Point> steps);
    
    bool Shah(int rown, int columnn, bool IsWhite);
    
    void DelKDol(int row, int column, std::vector<Point> &steps, bool IsWhite);
    
    bool IsPathClear(int row, int column, int newRow, int newColumn);
private:

    void output_outer_border();

    void output_letters();

    void output_inner_border();

    void output_row_number(int i, int l);

    void output_board_border(bool isOnTop);
};

