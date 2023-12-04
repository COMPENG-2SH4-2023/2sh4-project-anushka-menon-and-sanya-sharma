#include "GameMechs.h" // Include the corresponding header file
#include "MacUILib.h" // Include necessary libraries for MacUILib

// Default constructor initializes GameMechs with default values
GameMechs::GameMechs()
{
    input = 0; // Initialize input to default value
    score = 0; // Initialize score to default value
    exitFlag = false; // Initialize exit flag to false by default
    loseFlag = false; // Initialize lose flag to false by default
    boardSizeX = 30; // Set default board size X
    boardSizeY = 15; // Set default board size Y
}

// Parameterized constructor initializes GameMechs with provided board size
GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0; // Initialize input to default value
    score = 0; // Initialize score to default value
    exitFlag = false; // Initialize exit flag to false by default
    loseFlag = false; // Initialize lose flag to false by default
    boardSizeX = boardX; // Set board size X
    boardSizeY = boardY; // Set board size Y
}

// No destructor needed as there's no dynamic memory allocation

// Function to get the exit flag status
bool GameMechs::getExitFlagStatus()
{
    return exitFlag;
}

// Function to set the exit flag to true
void GameMechs::setExitTrue()
{
    exitFlag = true;
}

// Function to get the lose flag status
bool GameMechs::getLoseFlagStatus()
{
    return loseFlag;
}

// Function to set the lose flag to true
void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

// Function to get the current score
int GameMechs::getScore()
{
    return score;
}

// Function to increment the score by a fixed amount
void GameMechs::incrementScore()
{
    int n = 1; // Increment value
    score += n; // Increase score by 'n'
}

// Function to get the current level
int GameMechs::getGameLevel()
{
    return gameLevel;
}

// Function to increment the level by a fixed amount
void GameMechs::incrementGame()
{
    int n = 1; // Increment value
    gameLevel+= n; // Increase score by 'n'
}

// Function to get user input
char GameMechs::getInput()
{
    if(MacUILib_hasChar())
    {
        input = MacUILib_getChar(); // Fetch user input from MacUILib
    }

    return input;
}

// Function to get the board size in the X dimension
int GameMechs::getBoardSizeX()
{
    return boardSizeX;
}

// Function to get the board size in the Y dimension
int GameMechs::getBoardSizeY()
{
    return boardSizeY;
}

// Function to set input to a specific character
void GameMechs::setInput(char this_input)
{
    input = this_input;
}

// Function to clear the input
void GameMechs::clearInput()
{
    input = '\0'; // Set input to null character to clear
}
