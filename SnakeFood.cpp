#include <iostream> // Include for std::cout
#include "SnakeFood.h"
#include <cstdlib> // Standard library for general utilities
#include <ctime> // Header providing date and time functions

// Constructor: initializes the food position at the center of the board
SnakeFood::SnakeFood(GameMechs* thisgmref) {
    srand(time(nullptr)); // Seed for generating random numbers
    int initialX = thisgmref->getBoardSizeX() / 2; // X-coordinate at the center
    int initialY = thisgmref->getBoardSizeY() / 2; // Y-coordinate at the center
    foodPos.setObjPos(initialX, initialY, 'o'); // Set initial food position
}

// Destructor
SnakeFood::~SnakeFood() {
    // Destructor is empty as there's no dynamic memory allocation
}

// Generate new food position that does not overlap with the player
void SnakeFood::generateFood(objPosArrayList* playerPosList) {
    srand(static_cast<unsigned int>(time(nullptr))); // Seed for generating random numbers
    bool playerOverlap;

    do {
        // Generate random coordinates for food within the board boundaries
        foodPos.x = (rand() % 20) + 1; // X-coordinate (1 to 20)
        foodPos.y = (rand() % 10) + 1; // Y-coordinate (1 to 10)

        // Overlapping check with the player's position list
        playerOverlap = false;
        objPos playerPos;

        for (int i = 0; i < playerPosList->getSize(); ++i) {
            playerPosList->getElement(playerPos, i); // Get a position from the list
            if (foodPos.isPosEqual(&playerPos)) { // Check if food position overlaps with player
                playerOverlap = true;
                break;
            }
        }
    } while (playerOverlap); // Repeat until food position does not overlap

    foodPos.symbol = 'O'; // Set symbol for food
}

// Return the current food position
void SnakeFood::getFoodPos(objPos &returnPos) {
    returnPos = foodPos;
}
