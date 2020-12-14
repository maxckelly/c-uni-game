//
//  gameScreen.hpp
//  assignment-1-part-2
//
//  Created by Max Kelly on 8/12/20.
//

#ifndef gameScreen_hpp
#define gameScreen_hpp

#include <stdio.h>

class CGame {
    public:
        void moveCharacter(int jump = 0);
        void createGameScreen();
        void drawBarrier();
        void displayResults();
        void resetGame();
        bool getGameStatus();
        int getBarrierX();
        void setBarrierX(int num);
    private:
        bool bGameOver = false;
        int iGameSpeed = 40;
        int iScore = 0;
        int iCharacterY;
        bool bHasHitBarrier = false;
        bool bRestartGame = false;
        char cUserInput;
        int iBarrierX = 0;
};


#endif /* gameScreen_hpp */
