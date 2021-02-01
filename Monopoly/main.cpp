#include "game.hpp"

int main(int argc, char const *argv[]){
    //create and initialize table
    std::vector<Field*> board;
    initialize_board(board);
        
    //create players
    auto names = welcomeNote();
    Player player1(names.first, 1, 1500, 0);
    Player player2(names.second, 2, 1500, 0);
    onTheMove=playesFirst();
    
    //setting who's on the move variable
    Player* currentPlayer=fCurrentPlayer(&player1,&player2);

    
    
    while(1){
        std::cout << currentPlayer->name() << "'s turn" << std::endl;
         
        if(!currentPlayer->movePlayer()){  //if false is returned, player has no right to play this move
            currentPlayer=fCurrentPlayer(&player1,&player2);
            std::cout << "_______________________________\n" << std::endl;
            continue;
        }
        
                
        int currentField = currentPlayer->position();
        
        std::cout << "You are curently on field " << board[currentField]->name() << "." << std::endl;

        //which action to make
        board[currentField]->action(*currentPlayer);         
       
        
        //switch a player for the next loop (only if currentPlayer didn't get doubles)
        if(!currentPlayer->countTurns())
            currentPlayer=fCurrentPlayer(&player1,&player2);

        std::cout << "_______________________________\n" << std::endl;
    }
     

    return 0;
}