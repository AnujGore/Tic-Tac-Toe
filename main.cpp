#include <iostream>
#include "player.h"
#include "board.h"

Player intro();

int main(){
    Player main_player = intro();

    Player computer;

    std::cout<<"here \n";

    if (main_player.value == 'x')
    {
        computer.setValue('o');
    }else{
        computer.setValue('x');
    }
    
    std::cout<<"here\n";

    board this_board;
    this_board.printBoard(main_player, computer);

    return 0;
}

Player intro(){
    
    char Player_token;

    std::vector<Player> return_vec;

    std::cout<<"Welcome to Tic Tac Toe! \n";
    std::cout<<"Please select your token (x or o): ";
    std::cin>>Player_token;

    Player mainPlayer;
    mainPlayer.setValue(Player_token);

    std::cout<<"You have selected: "<<mainPlayer.value<<std::endl;

    std::cout<<"Let's play! \n";

    return mainPlayer;
}