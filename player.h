#pragma once
#include <vector>

class Player
{
public:
Player();
char value;
void setValue(char Value_Player);
std::vector<int> userMove(std::vector<int> curr_tokens, int vec_pos);
std::tuple<char, int> request_pos();
 
};

class computer: public Player{
    public:
    computer();
    std::vector<int> computerMove(std::vector<int> curr_tokens);
};

