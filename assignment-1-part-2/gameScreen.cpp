//
//  gameScreen.cpp
//  assignment-1-part-2
//
//  Created by Max Kelly on 8/12/20.
//

#include "gameScreen.hpp"
#include <curses.h>
#include <iostream>
#include <string>
#include <unistd.h>

#define characterPos 2
#define barrierPos 75

void CGame::moveCharacter(int jump) {
    static int foot = 0;
    
    if (jump == 0) {
        iCharacterY = 0;
    } else if (jump == 2) {
        iCharacterY--;
    } else {
        iCharacterY++;
    }
    
    mvaddstr(15 - iCharacterY, characterPos, "         ");
    mvaddstr(16 - iCharacterY, characterPos, "    O    ");
    mvaddstr(17 - iCharacterY, characterPos, "    |    ");
    mvaddstr(18 - iCharacterY, characterPos, "    |    ");
    mvaddstr(19 - iCharacterY, characterPos, "~~~~|~~~~");
    mvaddstr(20 - iCharacterY, characterPos, "    |    ");
    mvaddstr(21 - iCharacterY, characterPos, "    |    ");
    mvaddstr(22 - iCharacterY, characterPos, "   / \\  ");
    mvaddstr(23 - iCharacterY, characterPos, "  /   \\ ");
    move(25 - iCharacterY, characterPos);
    refresh();
    usleep(iGameSpeed);
};

void CGame::drawBarrier() {
    if (getBarrierX() == 56 && iCharacterY < 4) {
        bGameOver = true;
        return;
    };

    mvaddstr(20, barrierPos - iBarrierX,  "| |");
    mvaddstr(21, barrierPos - iBarrierX,  "| |");
    mvaddstr(22, barrierPos - iBarrierX,  "|_|");
    mvaddstr(23, barrierPos - iBarrierX,  " | ");
    mvaddstr(24, barrierPos - iBarrierX,  " | ");
    refresh();
    
    setBarrierX(getBarrierX() +1);
    
    if (getBarrierX() == 73) {
        setBarrierX(0);
        iScore++;
        mvaddstr(2, 11, "     ");
        move(2, 11); // Moves up to put score down
        refresh();
        std::cout << iScore;
        
        if (iGameSpeed > 20) {
            iGameSpeed--;
        }
    }
};

void CGame::createGameScreen() {
    clear();
    mvaddstr(2, 3, "SCORE: ");
    refresh();
    for (int i = 0; i < 79; i++) {
        mvaddstr(1, 1 + i, "-");
        refresh();
    };
};

bool CGame::getGameStatus() {
    return bGameOver;
};

void CGame::displayResults() {
    mvaddstr(8, 36, "GAME OVER");
    move(9, 36);
    refresh();
    std::cout << "Score: " << iScore << std::endl;
};

void CGame::setBarrierX(int num) {
    iBarrierX = num;
};

int CGame::getBarrierX() {
    return iBarrierX;
};
