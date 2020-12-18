//
//  gameScreen.cpp
//  assignment-1-part-2
//
//  Created by Max Kelly on 8/12/20.
//

#include "gameScreen.hpp"
#include <ncurses.h>
#include <iostream>
#include <string>
#include <unistd.h>

// Global to define the character starting pos and barrier starting pos
#define characterPos 2
#define barrierPos 75

// The below function moves the character forward, up and down
void CGame::moveCharacter(int jump) {
    // Controls the jumping of character
    if (jump == 0) {
        iCharacterY = 0;
    } else if (jump == 2) {
        iCharacterY--;
    } else {
        iCharacterY++;
    };
    
    // The below moves string and draws character
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
    refresh(); // refresh screen to load
    usleep(iGameSpeed);
};

// Below function draws barriers as character moves forward
void CGame::drawBarrier() {
    // If user reaches the end and hits barrier set game over to true
    if (getBarrierX() == 56 && iCharacterY < 4) {
        bGameOver = true;
        return;
    };

    // Moves string and draws barrier
    mvaddstr(20, barrierPos - iBarrierX,  "| |");
    mvaddstr(21, barrierPos - iBarrierX,  "| |");
    mvaddstr(22, barrierPos - iBarrierX,  "|_|");
    mvaddstr(23, barrierPos - iBarrierX,  " | ");
    mvaddstr(24, barrierPos - iBarrierX,  " | ");
    refresh();
    
    // Increases barrier x pos
    setBarrierX(getBarrierX() +1);
    
    // The below increases the score when they pass a barrier
    if (getBarrierX() == 73) {
        setBarrierX(0);
        iScore++; // Increase score
        move(2, 11); // Moves up to put score down
        refresh();
        std::cout << iScore;
    }
};

// The below creates the game screen with the barrier at the top and the score
void CGame::createGameScreen() {
    clear();
    mvaddstr(2, 3, "SCORE: ");
    refresh();
    for (int i = 0; i < 79; i++) {
        mvaddstr(1, 1 + i, "-");
        refresh();
    };
};

// Returns game status
bool CGame::getGameStatus() {
    return bGameOver;
};

// Displays result on screen when user hits barrier
void CGame::displayResults() {
    mvaddstr(8, 36, "GAME OVER");
    move(9, 36);
    refresh();
    std::cout << "Score: " << iScore << std::endl;
};

// Increases barrier X as character moves across screen
void CGame::setBarrierX(int num) {
    iBarrierX = num;
};

// Gets barrier X int
int CGame::getBarrierX() {
    return iBarrierX;
};

// Gets user input when playing game
char CGame::getUserInput() {
    return cUserInput;
};

// Each time user presses a key we set user input
void CGame::setUserInput() {
    cUserInput = getch();
};

// Returns just the game score
int CGame::getGameScore() {
    return iScore;
};
