//
//  gameScreen.hpp
//  assignment-1-part-2
//
//  Created by Max Kelly on 8/12/20.
//

#ifndef gameScreen_hpp
#define gameScreen_hpp

#include <stdio.h>

// Below is the game class
class CGame {
    public:
        void moveCharacter(int jump = 0);
        void createGameScreen();
        void drawBarrier();
        void displayResults();
        void resetGame();
        void setUserInput();
        bool getGameStatus();
        char getUserInput();
        int getBarrierX();
        void setBarrierX(int num);
    private:
        bool bGameOver = false; // Controls if the user has lost or game is still running
        int iGameSpeed = 40; // Displays how fast the screen moves
        int iScore = 0; // Controls the user score
        int iCharacterY; // Controls user position
        bool bHasHitBarrier = false; // If user hits barrier this is set to true
        char cUserInput; // Gets user input like space bar press etc...
        int iBarrierX = 0; // Controls barrier positioning 
};


#endif /* gameScreen_hpp */
