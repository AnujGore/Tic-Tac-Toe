#include <iostream>
#include "player.h"
#include "board.h"
#include "other_functions.h"
#include <tuple>

Player intro();
int vectorPosition(std::tuple<char, int> this_tuple);
bool checkWin(std::vector<int> token_list);

bool Gameplay(std::vector<int> token_list, board this_board, Player main_player, computer second_player);

int main(){
    Player main_player = intro();

    computer comp;

    if (main_player.value == 'x')
    {
        comp.setValue('o');
    }else{
        comp.setValue('x');
    }

    board this_board;
    std::vector<int> ini_token (9, 10);
    this_board.printBoard(ini_token, main_player, comp);

    auto status = Gameplay(ini_token, this_board, main_player, comp);

    return 0;
}


bool Gameplay(std::vector<int> token_list, board this_board, Player main_player, computer second_player){

    bool win = false;

    while(win == false){
        auto position = main_player.request_pos();
        token_list = main_player.userMove(token_list, vectorPosition(position));
        win = checkWin(token_list);
        this_board.printBoard(token_list, main_player, second_player);
        if (win)
        {   
            std::cout<<std::endl;
            std::cout<<"You win!\n";
            break;
        }
        std::cout<<std::endl;

        token_list = second_player.computerMove(token_list);
        win = checkWin(token_list);
        this_board.printBoard(token_list, main_player, second_player);
        if (win)
        {   
            std::cout<<std::endl;
            std::cout<<"The computer wins \n";
            break;
        }
        std::cout<<std::endl;
    }

    return true;
}