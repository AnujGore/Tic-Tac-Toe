#include <vector>
#include <iostream>
#include "player.h"

class board
{
private:
    std::vector<std::vector<int>> playing_board; 
    bool Status = false;
public:
    board();
    void printBoard(std::vector<int> tokens, Player main_player, Player computer);
};

