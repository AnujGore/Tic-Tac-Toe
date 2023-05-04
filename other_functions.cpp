#include "other_functions.h"

int vectorPosition(std::tuple<char, int> this_tuple){
    int row_i;
    if (std::get<0>(this_tuple) == 'A') row_i = 0;
    if (std::get<0>(this_tuple) == 'a') row_i = 0;
    if (std::get<0>(this_tuple) == 'B') row_i = 3;
    if (std::get<0>(this_tuple) == 'b') row_i = 3;
    if (std::get<0>(this_tuple) == 'C') row_i = 6;
    if (std::get<0>(this_tuple) == 'c') row_i = 6;

    return (row_i + std::get<1>(this_tuple))-1;
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

bool checkWin(std::vector<int> token_list){
    std::vector<std::vector<int>> board_vec;
    int vec_counter = 0;

    for (int i = 0; i < 3; i++)
    {
        std::vector<int> row_vec;
        for (int j = 0; j < 3; j++)
        {
            row_vec.push_back(token_list.at(vec_counter));
            vec_counter++;
        }

        board_vec.push_back(row_vec);       

    }

    int parity;

    //row checking
    for (int k = 0; k < 3; k++)
    {
        int result;
        for (int i = 0; i < 3; i++)
        {
            result += board_vec.at(k).at(i);
        }
        
        if ((result == 0) || (result == 3))
        {
            return true;
        }
        
    }

    //column checking
    for (int l = 0; l < 3; l++)
    {
        int result = 0;
        for (int i = 0; i < 3; i++)
        {
            result += board_vec.at(i).at(l);
        }
        if ((result == 0) || (result == 3))
        {
            return true;
        }
       
    }

    //diagonal checking
    int result_diag_Minus  = 0;
    for (int i = 0; i < 3; i++) result_diag_Minus += board_vec.at(i).at(i);
    if ((result_diag_Minus == 0) || (result_diag_Minus == 3)) return true;

    int result_diag_plus  = 0;
    for (int i = 0; i < 3; i++) result_diag_plus += board_vec.at(i).at(2-i);
    if ((result_diag_plus == 0) || (result_diag_plus == 3)) return true;

    return false;

}