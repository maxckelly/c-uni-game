//
//  main.cpp
//  assignment-1-part-2
//
//  Created by Max Kelly on 1/12/20.
//

#include <iostream>
#include <fstream>
#include <ncurses.h>
#include "mainMenu.hpp"
#include "gameScreen.hpp"
#include "./helpers/helpers.hpp"

// Defines the lenght of the screen. Note this is from ncurses
#define WORLD_WIDTH 100
#define WORLD_HEIGHT 50

// Creates a new window over the console using ncurses to allow drawing
WINDOW *mr_quickie;

int main() {
    initscr();
    int offsetx, offsety;
    refresh();
    
    offsetx = (COLS - WORLD_WIDTH) / 2; // draws the width of the screen
    offsety = (LINES - WORLD_HEIGHT) / 2; // draws the height of the screen
    
    mr_quickie = newwin(WORLD_HEIGHT, WORLD_WIDTH, offsety, offsetx);
    
    CMainMenu newMenu; // Creates a new menu class

    // While the user hasn't pressed q keep looping through below
    while (newMenu.getUserInput() != 'q') {
        // If user presses 'p' start game
        if (newMenu.getUserInput() == 'p') {
            clear(); // Clears screen
            refresh();
            CGame newGame; // Creates new game class
            int i;
            newGame.createGameScreen(); // Draws game screenw
            
            // While true loop through game
            while (true) {
                newGame.setUserInput();
                // If gameOver = true then stop game
                if (newGame.getGameStatus() == 1) {
                    clear(); // clear screen
                    refresh();
                    
                    saveScoreToFile(newGame.getGameScore(), "scores.txt");
                    
                    newGame.displayResults(); // Display results on screen
                    move(10, 0);
                    refresh();
                    newMenu.setUserInput(newMenu.showMenu()); // Show option menu to user
                    newGame = CGame(); // reset game to original state
                    break;
                };
                 
                if (newGame.getUserInput() == ' ') {
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
                } else if (newGame.getUserInput() == 'q') {
                    break;
                }
            }
        // If user presses 'i' then show instruction screen
        } else if (newMenu.getUserInput() == 'i') {
            clear();
            refresh();
            newMenu.setUserInput(newMenu.showInstructions());
        // If user presses 'm' return back to main menu
        } else if (newMenu.getUserInput() == 'm') {
            clear();
            refresh();
            newMenu.setUserInput(newMenu.showMenu());
        } else if (newMenu.getUserInput() == 'r') {
            clear();
            refresh();
            newMenu.setUserInput(newMenu.showPastResults());
        } else {
            clear();
            refresh();
            newMenu.setUserInput(newMenu.showMenu());
        }
    };
    
    return 0;
};
