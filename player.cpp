#include "player.h"
#include <vector>
#include <tuple>
#include <iostream>

Player::Player(){}

void Player::setValue(char Value_Player){
    value = Value_Player;
}

std::tuple<char, int> Player::request_pos(){
    std::tuple<char, int> position ;

    char row_s;
    int col_i;

    std::cout<<"Where would you like your token to go? (row, column): ";
    std::cin>>row_s>>col_i;
    std::cout<<std::endl;

    position = std::make_tuple(row_s, col_i);

    return position;

}

std::vector<int> Player::userMove(std::vector<int> curr_tokens, int vec_pos){
    curr_tokens.at(vec_pos) = 1;
    return curr_tokens;
}

computer::computer(){}

std::vector<int> computer::computerMove(std::vector<int> curr_tokens){

    int vec_pos = rand()%9;

    if (curr_tokens.at(vec_pos) == 10) curr_tokens.at(vec_pos) = 0;

    else{
        return computerMove(curr_tokens);
    }

    std::cout<<"Computer move: \n";
    return curr_tokens;
}