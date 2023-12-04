#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>
#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;

class GameMechs
{
    // Sample members included; more will be added to complete the design

private:
    char input;         // Stores user input
    bool exitFlag;      // Flag indicating whether the game should exit
    bool loseFlag;      // Flag indicating whether the game is lost
    int score;          // Current score of the game
    int gameLevel;      // Current level of the game
    int boardSizeX;     // Size of the game board in the X direction
    int boardSizeY;     // Size of the game board in the Y direction

public:
    // Constructors
    GameMechs();                            // Default constructor
    GameMechs(int boardX, int boardY);      // Parameterized constructor

    // Getters and Setters for various game parameters and flags
    bool getExitFlagStatus();       // Get the status of the exit flag
    void setExitTrue();             // Set the exit flag to true

    bool getLoseFlagStatus();       // Get the status of the lose flag
    void setLoseFlag();             // Set the lose flag to true

    int getScore();                 // Get the current game score
    void incrementScore();          // Increment the game score

    int getGameLevel();            // Get the current game level
    void incrementGame();          // Increment the game level

    char getInput();                // Get user input
    void setInput(char this_input); // Set user input
    void clearInput();              // Clear user input

    int getBoardSizeX();            // Get the board size in the X direction
    int getBoardSizeY();            // Get the board size in the Y direction
};

#endif // GAMEMECHS_H
