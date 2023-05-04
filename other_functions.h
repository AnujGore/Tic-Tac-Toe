#include <tuple>
#include "player.h"
#include <iostream>
#include <numeric>
#pragma once

int vectorPosition(std::tuple<char, int> this_tuple);
Player intro();
bool checkWin(std::vector<int> token_list);