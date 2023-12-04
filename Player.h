#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"      // Include GameMechs class header
#include "objPos.h"         // Include objPos class header
#include "objPosArrayList.h"// Include objPosArrayList class header
#include "SnakeFood.h"      // Include SnakeFood class header

class Player
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

public:
    enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // Enumeration for player's direction

    // Constructor and Destructor
    Player(GameMechs* thisGMRef, SnakeFood* food);
    ~Player();

    // Functions for player movement and position
    void getPlayerPos(objPos &returnPos); // Get the position of the player
    objPosArrayList* getPlayerPosList(); // Get the player's position list
    void updatePlayerDir();              // Update the player's direction based on input
    void movePlayer();                   // Move the player based on direction

private:
    objPosArrayList* playerPosList; // List to store the player's position
    enum Dir myDir;                 // Player's current direction
    char input;                     // Player's input for movement
    SnakeFood* food;                // Reference to SnakeFood object for interaction
    GameMechs* mainGameMechsRef;    // Reference to the Main Game Mechanisms
};

#endif
