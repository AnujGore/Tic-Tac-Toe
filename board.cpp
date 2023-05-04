#include "board.h"

void printLines(int columns)
{
    std::cout << "   ";
    for(int i = 0; i < columns; i++)
    {
        std::cout << " ---";
    }
    std::cout << std::endl;
}

void printNumbers(int columns)
{
    std::cout << "   ";
    for(int i = 0; i < columns; i++)
    {
        std::cout << "  " << i+1 << " ";
    }
    std::cout << std::endl;
}

char token_return(int this_token, Player this_player, Player computer){
    if (this_token == 10) return ' ';
    if (this_token == 1) return this_player.value;
    if (this_token == 0) return computer.value;

    return ' ';
}

board::board(){
    std::vector<int> board_row{10, 10, 10};
    for (int i = 0; i < 3; i++)
    {
        playing_board.push_back(board_row);
    }
    
} 

void board::printBoard(std::vector<int> tokens, Player main_player, Player computer){

    printNumbers(3);
    printLines(3);

    int rows = 3;
    int columns = 3;
    int vec_counter = 0;

    for(int i = 0; i < rows; i++)
    {
        std::cout << " " <<char('A'+i);
        for(int j = 0; j < columns; j++)
        {
            char token = token_return(tokens.at(vec_counter), main_player, computer);
            std::cout << " | ";
            std::cout<<token;
            vec_counter++;

        }
        std::cout << " | " << char('A'+i) << std::endl;
        printLines(columns);
    }
    printNumbers(columns);
}
