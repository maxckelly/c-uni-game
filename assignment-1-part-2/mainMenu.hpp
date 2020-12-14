//
//  mainMenu.hpp
//  assignment-1-part-2
//
//  Created by Max Kelly on 1/12/20.
//

#ifndef mainMenu_hpp
#define mainMenu_hpp

#include <stdio.h>

class CMainMenu {
    public:
        char showMenu();
        char showInstructions();
        char getUserInput();
        void setUserInput(char cUserInput);
    private:
        char cUserInput = 'm';
};

#endif /* mainMenu_hpp */
