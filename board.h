#include <vector>
#include <iostream>
#include "player.h"

char token_return(int this_token, Player this_player, Player computer){
    if (this_token == 2) return ' ';
    if (this_token == 1) return this_player.value;
    if (this_token == 0) return computer.value;

    return ' ';
}


class board
{
private:
    std::vector<std::vector<int>> playing_board; 
    bool Status = false;
public:
    board();
    void printBoard(Player main_player, Player computer);
};

board::board(){
    std::vector<int> board_row{2, 2, 2};
    for (int i = 0; i < 3; i++)
    {
        playing_board.push_back(board_row);
    }
    
} 

void board::printBoard(Player main_player, Player computer){
    std::cout<<"here\ns";
    for (int i = 0; i < playing_board.size(); i++)
    {
        std::cout<<token_return(playing_board.at(i).at(0), main_player, computer)
            <<" | "<< token_return(playing_board.at(i).at(1), main_player, computer)
                <<" | "<< token_return(playing_board.at(i).at(2), main_player, computer)
                    << std::endl;
        if (i != playing_board.size())
        {
            std::cout<<"_ _ _ _ _ _"<< std::endl;
        }
            
    }

}