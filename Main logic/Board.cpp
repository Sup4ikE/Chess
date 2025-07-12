#include "Board.h"

//Розтановка фігур
Board::Board()
{
    BoardInfo = new FiguresTable(ROWS, COLUMNS);

    for (int i = 0; i < COLUMNS; i++)
    {
        //Пішак
        BoardInfo->Rows[1]->Columns[i] = new Pawn('p', true, 1, i);
        BoardInfo->Rows[ROWS - 2]->Columns[i] = new Pawn('P', false, ROWS - 2, i);
    }

    //Тура
    BoardInfo->Rows[0]->Columns[0] = new Tour('t', true, 0, 0);
    BoardInfo->Rows[0]->Columns[7] = new Tour('t', true, 0, 7);
    BoardInfo->Rows[7]->Columns[0] = new Tour('T', false, 7, 0);
    BoardInfo->Rows[7]->Columns[7] = new Tour('T', false, 7, 7);

    //Кінь
    BoardInfo->Rows[0]->Columns[1] = new Horse('h', true, 0, 1);
    BoardInfo->Rows[0]->Columns[6] = new Horse('h', true, 0, 6);
    BoardInfo->Rows[7]->Columns[1] = new Horse('H', false, 7, 1);
    BoardInfo->Rows[7]->Columns[6] = new Horse('H', false, 7, 6);

    //Слон
    BoardInfo->Rows[0]->Columns[2] = new Elephant('e', true, 0, 2);
    BoardInfo->Rows[0]->Columns[5] = new Elephant('e', true, 0, 5);
    BoardInfo->Rows[7]->Columns[2] = new Elephant('E', false, 7, 2);
    BoardInfo->Rows[7]->Columns[5] = new Elephant('E', false, 7, 5);

    //Королева
    BoardInfo->Rows[0]->Columns[3] = new Queen('q', true, 0, 3);
    BoardInfo->Rows[7]->Columns[3] = new Queen('Q', false, 7, 3);
    
    //Король
    BoardInfo->Rows[0]->Columns[4] = new King('k', true, 0, 4);
    BoardInfo->Rows[7]->Columns[4] = new King('K', false, 7, 4);

}


//Розтановка доларів(можливих ходів)
void Board::DisplayPossibleSteps(int row, int column, bool IsWhite)
{
    std::vector<Point> steps = BoardInfo->Rows[row]->Columns[column]->GetPossibleSteps();
    
    //Видалення своїх фігур з вектора короля
    if(BoardInfo->Rows[row]->Columns[column]->Symbol == 'K' || BoardInfo->Rows[row]->Columns[column]->Symbol == 'k')
    {
        for (int s = 0; s < steps.size(); s++) //Проходимся по steps
        {
            
            if(BoardInfo->Rows[steps[s].x]->Columns[steps[s].y]->IsWhite == IsWhite)
            {
                steps.erase(steps.begin() + s); // Видаляєм його з steps
                s--; // зменшуєм на 1 ,щоб не пропустити наступний елемент
            }
            
        }
        
        DelKDol(row, column, steps, BoardInfo->Rows[row]->Columns[column]->IsWhite);
        
        //Перевірка на перемогу
        if(steps.size() == 0)
        {
            if(IsWhite == true)
            {
                std::cout << "Black team win!" << std::endl;
            }
            else if(IsWhite == false)
            {
                std::cout << "White team win!" << std::endl;
            }
            
            exit(0);
        }

    }
    
    for (Point step : steps)
    {
        
        if(BoardInfo->Rows[step.x]->Columns[step.y]->Symbol == ' ')
        {
            BoardInfo->Rows[step.x]->Columns[step.y]->Symbol = '$';
        }
    
    }
    
    if (BoardInfo->Rows[row]->Columns[column]->Symbol == 'P') // Білий пішак
        {
            if (row - 1 >= 0)
            {
                if (column + 1 < BoardInfo->Rows[row]->Columns.size() &&
                    BoardInfo->Rows[row - 1]->Columns[column + 1]->Symbol == '$')
                {
                    BoardInfo->Rows[row - 1]->Columns[column + 1]->Symbol = ' ';
                }
                if (column - 1 >= 0 &&
                    BoardInfo->Rows[row - 1]->Columns[column - 1]->Symbol == '$')
                {
                    BoardInfo->Rows[row - 1]->Columns[column - 1]->Symbol = ' ';
                }
            }
        }
        else if (BoardInfo->Rows[row]->Columns[column]->Symbol == 'p') // Чорний пішак
        {
            if (row + 1 < BoardInfo->Rows.size())
            {
                if (column + 1 < BoardInfo->Rows[row]->Columns.size() &&
                    BoardInfo->Rows[row + 1]->Columns[column + 1]->Symbol == '$')
                {
                    BoardInfo->Rows[row + 1]->Columns[column + 1]->Symbol = ' ';
                }
                if (column - 1 >= 0 &&
                    BoardInfo->Rows[row + 1]->Columns[column - 1]->Symbol == '$')
                {
                    BoardInfo->Rows[row + 1]->Columns[column - 1]->Symbol = ' ';
                }
            }
        }
        
    if(BoardInfo->Rows[row]->Columns[column]->Symbol != 'H' && BoardInfo->Rows[row]->Columns[column]->Symbol != 'h' )
    {
        
        bool isDo = true;
        
        //Вверх долари
        for(int i = row - 1; i >= 0; i--)
        {
            if(BoardInfo->Rows[i]->Columns[column]->Symbol != '$')
            {
                isDo = false;
                continue;
            }
            if(isDo == false)
            {
                BoardInfo->Rows[i]->Columns[column]->Symbol = ' ';
            }
        }
        isDo = true;
        
        //Вниз
        for (int i = row + 1; i < 8; i++)
        {
            if(BoardInfo->Rows[i]->Columns[column]->Symbol != '$')
            {
                isDo = false;
                continue;
            }
            if(isDo == false)
            {
                BoardInfo->Rows[i]->Columns[column]->Symbol = ' ';
            }
        }
        isDo = true;
        
        //Вліво
        for (int i = column - 1; i >= 0; i--)
        {
            if(BoardInfo->Rows[row]->Columns[i]->Symbol != '$')
            {
                isDo = false;
                continue;
            }
            if(isDo == false)
            {
                BoardInfo->Rows[row]->Columns[i]->Symbol = ' ';
            }
        }
        isDo = true;
        
        //Вправо
        for (int i = column + 1; i < 8; i++)
        {
            if(BoardInfo->Rows[row]->Columns[i]->Symbol != '$')
            {
                isDo = false;
                continue;
            }
            if(isDo == false)
            {
                BoardInfo->Rows[row]->Columns[i]->Symbol = ' ';
            }
        }
        isDo = true;
        
        //Вправо-вверх
        int j = column;
        for(int i = row - 1; i >= 0; i--)
        {
            if(j < 7)
            {
                j++;
            }
            
            if(BoardInfo->Rows[i]->Columns[j]->Symbol != '$')
            {
                isDo = false;
                continue;
            }
            if(isDo == false)
            {
                BoardInfo->Rows[i]->Columns[j]->Symbol = ' ';
            }
            
        }
        isDo = true;
        
        //Вправо-вниз
        j = column;
        for(int i = row + 1; i < 8; i++)
        {
            if(j < 7)
            {
                j++;
            }
            
            if(BoardInfo->Rows[i]->Columns[j]->Symbol != '$')
            {
                isDo = false;
                continue;
            }
            if(isDo == false)
            {
                BoardInfo->Rows[i]->Columns[j]->Symbol = ' ';
            }
            
        }
        isDo = true;
        
        //Вліво-вверх
        j = column;
        for(int i = row - 1; i >= 0; i--)
        {
            if(j > 0)
            {
                j--;
            }
            
            if(BoardInfo->Rows[i]->Columns[j]->Symbol != '$')
            {
                isDo = false;
                continue;
            }
            if(isDo == false)
            {
                BoardInfo->Rows[i]->Columns[j]->Symbol = ' ';
            }
            
        }
        isDo = true;
        
        //Вліво-вниз
        j = column;
        for(int i = row + 1; i < 8; i++)
        {
            if(j > 0)
            {
                j--;
            }
            
            if(BoardInfo->Rows[i]->Columns[j]->Symbol != '$')
            {
                isDo = false;
                continue;
            }
            if(isDo == false)
            {
                BoardInfo->Rows[i]->Columns[j]->Symbol = ' ';
            }
            
        }
        isDo = true;
        
    }
    
    output_board();
}


//Крок
void Board::Step(int row, int column, int newRow, int newColumn)
{
    
    std::vector<Point> steps = BoardInfo->Rows[row]->Columns[column]->GetPossibleSteps();
    
    //Шах
    if(Shah(row, column, BoardInfo->Rows[row]->Columns[column]->IsWhite))
    {
        std::cout << "Your king is in check!" << std::endl;
    }
    
    //Биття для пєшки
    if(BoardInfo->Rows[newRow]->Columns[newColumn]->Symbol != ' ' && BoardInfo->Rows[newRow]->Columns[newColumn]->Symbol != '$')
    {
        
        if(BoardInfo->Rows[row]->Columns[column]->Symbol == 'P')
        {
            if(BoardInfo->Rows[newRow]->Columns[newColumn] == BoardInfo->Rows[row - 1]->Columns[column] || BoardInfo->Rows[newRow]->Columns[newColumn] == BoardInfo->Rows[row - 2]->Columns[column])
            {
                return;
            }
        }
        else if(BoardInfo->Rows[row]->Columns[column]->Symbol == 'p')
        {
            if(BoardInfo->Rows[newRow]->Columns[newColumn] == BoardInfo->Rows[row + 1]->Columns[column] || BoardInfo->Rows[newRow]->Columns[newColumn] == BoardInfo->Rows[row + 2]->Columns[column])
            {
                return;
            }
        }
        
        //Биття звичайне
        Beat(row, column, newRow, newColumn, steps);
        
    }//Звичайний хід
    else if(BoardInfo->Rows[newRow]->Columns[newColumn]->Symbol == '$')
    {
        
        //Переміщення фігури з позиції (row, column) на позицію (newRow, newColumn)
        BoardInfo->Rows[newRow]->Columns[newColumn] = BoardInfo->Rows[row]->Columns[column];
        //Оновлення координат фігури, щоб вона знала, де зараз знаходиться
        BoardInfo->Rows[newRow]->Columns[newColumn]->Row = newRow;
        BoardInfo->Rows[newRow]->Columns[newColumn]->Column = newColumn;
        //Очищення старої позиції, встановлюючи її як порожню клітинку
        BoardInfo->Rows[row]->Columns[column] = new Figure(' ');
        
    }
    
}


//Биття
void Board::Beat(int row, int column, int newRow, int newColumn, std::vector<Point> steps)
{
    
    if(BoardInfo->Rows[row]->Columns[column]->IsWhite == BoardInfo->Rows[newRow]->Columns[newColumn]->IsWhite)
    {
        return;
    }
    else if(BoardInfo->Rows[newRow]->Columns[newColumn]->Symbol == 'K' || BoardInfo->Rows[newRow]->Columns[newColumn]->Symbol == 'k')
    {
        return;
    }
    else if(std::find(steps.begin(), steps.end(), Point(newRow, newColumn))!= steps.end())
    {
        
        if (IsPathClear(row, column, newRow, newColumn))
        {
            // Видалення побитої фігури, щоб уникнути витоків пам'яті
            delete BoardInfo->Rows[newRow]->Columns[newColumn];
            // Переміщення фігури, яка б'є, на нову позицію
            BoardInfo->Rows[newRow]->Columns[newColumn] = BoardInfo->Rows[row]->Columns[column];
            // Оновлення координат фігури, щоб вона знала, де зараз знаходиться
            BoardInfo->Rows[newRow]->Columns[newColumn]->Row = newRow;
            BoardInfo->Rows[newRow]->Columns[newColumn]->Column = newColumn;
            // Очищення старої позиції
            BoardInfo->Rows[row]->Columns[column] = new Figure(' ');
        }
    
    }
    
}


//Виявлення шаху
bool Board::Shah(int rown, int columnn, bool IsWhite)
{
    int rowK = 0;
    int colK = 0;
    
    bool kingFound = false;

    // Знайти короля
    for (int row = 0; row < ROWS && !kingFound; ++row)
    {
        for (int col = 0; col < COLUMNS; ++col)
        {
            Figure* piece = BoardInfo->Rows[row]->Columns[col];
            if ((piece->Symbol == 'K' || piece->Symbol == 'k') && piece->IsWhite == IsWhite)
            {
                rowK = row;
                colK = col;
                kingFound = true;
                break;
            }
        }
    }

    if(!kingFound)
    {
        return false;
    }
    
    // Ітеруємося по всіх клітинках дошки
        for (int row = 0; row < ROWS; ++row)
        {
            for (int col = 0; col < COLUMNS; ++col) 
            {
                Figure* piece = BoardInfo->Rows[row]->Columns[col];
                
                // Перевіряємо, чи фігура належить противнику
                if (piece->IsWhite != IsWhite)
                {
                    std::vector<Point> possibleMoves = piece->GetPossibleSteps();
                    
                    // Перевіряємо, чи знаходиться король під атакою
                    for (const Point& move : possibleMoves)
                    {
                        if (move.x == rowK && move.y == colK)
                        {
                            return true;
                        }
                    }
                }
            }
        }
    
        return false;
}


//Перевірка щоб не бити через фігуру
bool Board::IsPathClear(int row, int column, int newRow, int newColumn)
{
    //Обчислення різниці в рядках і стовпцях
    int dRow = newRow - row;
    int dCol = newColumn - column;
    
    //Визначаєм куда ми рухаємся
    int stepRow = (dRow != 0) ? dRow / abs(dRow) : 0;
    int stepCol = (dCol != 0) ? dCol / abs(dCol) : 0;

    //Початкові значення
    int currentRow = row + stepRow;
    int currentCol = column + stepCol;

    //Перевірка шляху, цикл while виконується доти, поки ми не досягнемо нової позиції
    while (currentRow != newRow || currentCol != newColumn)
    {
        if (BoardInfo->Rows[currentRow]->Columns[currentCol]->Symbol != ' ' &&
            BoardInfo->Rows[currentRow]->Columns[currentCol]->Symbol != '$')
        {
            return false;
        }
        currentRow += stepRow;
        currentCol += stepCol;
    }

    return true;
}


//Видалення доларів для короля якшо вони стоять на шаху
void Board::DelKDol(int row, int column, std::vector<Point> &steps, bool IsWhite)
{
    
    for(int i = 0; i <= 7; i++)
    {
        for(int j = 0; j <= 7; j++)
        {
            if(BoardInfo->Rows[i]->Columns[j]->Symbol != ' ' && BoardInfo->Rows[i]->Columns[j]->Symbol != '$' &&
               BoardInfo->Rows[i]->Columns[j]->IsWhite != IsWhite)
            {
                std::vector<Point> bsteps = BoardInfo->Rows[i]->Columns[j]->GetPossibleSteps();
                
                for (int s = 0; s < steps.size(); s++) //Проходимся по steps
                {
                    for(Point ver : bsteps) //Проходимся по bsteps
                    {
                        if(steps[s].x == ver.x && steps[s].y == ver.y) // Якщо елемент співпав
                        {
                            steps.erase(steps.begin() + s); // Видаляєм його з steps
                            s--; // зменшуєм на 1 ,щоб не пропустити наступний елемент
                            break;
                        }
                    }
                }
            }
        }
    }
}


//Видалення доларів
void Board::delete_paths()
{
    for(int i = 0; i <= 7; i++)
    {
        for(int j = 0; j <= 7; j++)
        {
            if(BoardInfo->Rows[i]->Columns[j]->Symbol == '$')
            {
                BoardInfo->Rows[i]->Columns[j]->Symbol = ' ';
            }
        }
    }
}


//Всі фунції для виводу дошки
void Board::output_board()
{
    output_board_border(true);

    for (int i = 0; i < ROWS; i++)
    {
        for (int l = 0; l < 3; l++)
        {
            output_row_number(i, l);

            for (int y = 0; y < COLUMNS; y++)
            {
                for (int k = 0; k < 3; k++)
                {
                    if (BoardInfo->Rows[i]->Columns[y]->Symbol != ' ' && l == 1 && k == 1)
                    {
                        std::wcout << BoardInfo->Rows[i]->Columns[y]->Symbol << " ";
                    }
                    else
                    {
                        if ((i + y) % 2 == 0)
                        {
                            std::cout << "  ";
                        }
                        else
                        {
                            std::cout << "* ";
                        }
                    }
                }
            }

            output_row_number(i, l);
            std::cout << std::endl;
        }
    }

    output_board_border(false);
    std::wcout << std::endl;
}

void Board::output_outer_border() {
    std::cout << " ";

    for (int i = 0; i < COLUMNS * 3 * 2 + 8; i++) {
        std::cout << "-";
    }

    std::cout << std::endl;
}

void Board::output_letters() {
    std::cout << "|    ";

    for (int i = 0; i < COLUMNS; i++) {
        std::cout << "  " << (char)(i + 65) << "   ";
    }

    std::cout << "    |" << std::endl;
}

void Board::output_inner_border() {
    std::cout << "|    ";

    for (int i = 0; i < COLUMNS; i++) {
        std::cout << "------";
    }

    std::cout << "    |" << std::endl;
}

void Board::output_row_number(int i, int l) {
    std::cout << "|";

    if (l == 1) {
        std::cout << " " << ROWS - i << " |";
    }
    else {
        std::cout << "   |";
    }
}

void Board::output_board_border(bool isOnTop) {
    isOnTop ? output_outer_border() : output_inner_border();
    output_letters();
    isOnTop ? output_inner_border() : output_outer_border();
}


