//
//  helpers.cpp
//  assignment-1-part-2
//
//  Created by Max Kelly on 18/12/20.
//

#include "helpers.hpp"
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <string>
#include <ncurses.h>


// Saves the score to file
void saveScoreToFile(int score, std::string fileName) {
    std::ofstream file;
    file.open(fileName);
    
    if (file.is_open()) {
        std::time_t result = std::time(nullptr);
    
        std::cout << std::ctime(&result);
        file << ctime(&result) << score;
        file.close();
    }
};

// Reads file from system
void readScoreFromFile(std::string fileName) {
    std::string line;
    std::ifstream file;
    file.open(fileName);
    
    if (file.is_open()) {
        while (file.good()) {
            getline(file, line);
            std::cout << line << " : ";
        }
        file.close();
    }
};
