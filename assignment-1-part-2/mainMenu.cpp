//
//  mainMenu.cpp
//  assignment-1-part-2
//
//  Created by Max Kelly on 1/12/20.
//

#include "mainMenu.hpp"
#include "gameScreen.hpp"
#include <iostream>
#include <ncurses.h>

/*
 Notes:
 The \n adds a line break.
 addstr is a better way to print text to terminal with ncurses
*/

char CMainMenu::showMenu() {
    
    // Welcome text
    addstr("======================");
    addstr("|    MR QUICKIE      |");
    addstr("======================\n");
    refresh();
    
    // User action options
    addstr("Press p: Start game\n");
    addstr("Press i: How to play\n");
    addstr("Press q: Quiet game\n");
    addstr("Please select one of the below options: ");
    refresh();
    
    
    return getch();
};

void CMainMenu::setUserInput(char userInput) {
    cUserInput = userInput;
};

char CMainMenu::getUserInput() {
    return cUserInput;
};

char CMainMenu::showInstructions() {
    // Welcome text
    addstr("==================");
    addstr("|    INSTRUCTIONS |");
    addstr("==================\n");
    refresh();
    
    // User action options
    addstr("Once the game has started press the space bar to drop your character \n");
    addstr("Then continue to press the spacebar to move your character forward \n");
    addstr("The aim is to jump over the barriers \n");
    addstr("When your score reaches 12 you win the game \n");
    refresh();
    
    // User action options
    addstr("Press p: Start game \n");
    addstr("Press m: To return to main menu \n");
    addstr("Press q: Quiet game \n");
    addstr("Please select one of the below options: ");
    refresh();
    
    return getch();
};
