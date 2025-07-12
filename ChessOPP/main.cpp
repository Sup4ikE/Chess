#include <iostream>
#include "Pawn.h"
#include "Board.h"

int main()
{
    Board* board = new Board();
    int iter = 1;
    
    while (true)
    {
        board->output_board();
        
        int row, column, newRow, newColumn = 0;
        
        std::cout << "Enter row: ";
        std::cin >> row;
        
        std::cout << "Enter column: ";
        std::cin >> column;
        
        if(iter % 2 != 0 && board->BoardInfo->Rows[row]->Columns[column]->IsWhite)
        {
            board->DisplayPossibleSteps(row, column, board->BoardInfo->Rows[row]->Columns[column]->IsWhite);
            
            std::cout << "Enter new row: ";
            std::cin >> newRow;
            
            std::cout << "Enter new column: ";
            std::cin >> newColumn;
            
            board->Step(row, column, newRow, newColumn);
            board->delete_paths();
            
            iter++;
        }
        else if(iter % 2 == 0 && !board->BoardInfo->Rows[row]->Columns[column]->IsWhite)
        {
            board->DisplayPossibleSteps(row, column, board->BoardInfo->Rows[row]->Columns[column]->IsWhite);
            
            std::cout << "Enter new row: ";
            std::cin >> newRow;
            
            std::cout << "Enter new column: ";
            std::cin >> newColumn;
            
            board->Step(row, column, newRow, newColumn);
            board->delete_paths();
            
            iter++;
        }
        else
        {
            std::cout << "Not your turn!" << std::endl;
            continue;
        }
    }
}


