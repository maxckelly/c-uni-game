//
//  main.cpp
//  assignment-1-part-2
//
//  Created by Max Kelly on 1/12/20.
//

#include <iostream>
#include <ncurses.h>
#include "mainMenu.hpp"
#include "gameScreen.hpp"

#define WORLD_WIDTH 100
#define WORLD_HEIGHT 50

WINDOW *mr_quickie;

int main(int argc, const char * argv[]) {
    
    initscr();
    int offsetx, offsety;
    refresh();
    
    offsetx = (COLS - WORLD_WIDTH) / 2;
    offsety = (LINES - WORLD_HEIGHT) / 2;
    
    mr_quickie = newwin(WORLD_HEIGHT, WORLD_WIDTH, offsety, offsetx);
    
    CMainMenu newMenu;

    while (newMenu.getUserInput() != 'q') {
        if (newMenu.getUserInput() == 'p') {
            clear();
            refresh();
            CGame newGame;
            char ch;
            int i;
            newGame.createGameScreen();
            
            while (true) {
                ch = getch();
                if (newGame.getGameStatus() == 1) {
                    clear();
                    refresh();
                    newGame.displayResults();
                    newMenu.setUserInput(newMenu.showMenu());
                    newGame = CGame();
                    break;
                };
                 
                if (ch == ' ') {
                    i = 0;
                    
                    while (i < 12) {
                        newGame.moveCharacter(1);
                        newGame.drawBarrier();
                        i++;
                    }
                    
                    while (i > 0) {
                        newGame.moveCharacter(2);
                        newGame.drawBarrier();
                        i--;
                    }
                } else if (newMenu.getUserInput() == 'p' || newMenu.getUserInput() == 'P') {
                    getch();
                } else if (ch == 'q') {
                    break;
                }
            }
        } else if (newMenu.getUserInput() == 'i') {
            clear();
            refresh();
            newMenu.setUserInput(newMenu.showInstructions());
        } else if (newMenu.getUserInput() == 'm') {
            clear();
            refresh();
            newMenu.setUserInput(newMenu.showMenu());
        }
    }

    return 0;
};
