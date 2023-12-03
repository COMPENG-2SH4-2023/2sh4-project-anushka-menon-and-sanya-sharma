#include <iostream>
#include "GameMechs.h"
#include "SnakeFood.h"
#include <cstdlib>
#include <ctime>

// SnakeFood.cpp
SnakeFood::SnakeFood(GameMechs* thisGMRef) {
    // Seed the random number generator only once
    srand(time(nullptr));

    int initialX = thisGMRef->getBoardSizeX() / 2;  // Set initial X position as the center
    int initialY = thisGMref->getBoardSizeY() / 2;  // Set initial Y position as the center
    foodPos.setObjPos(initialX, initialY, 'o');
}

SnakeFood::~SnakeFood() {
    // Implement any necessary cleanup or deallocation here if needed
}

void SnakeFood::generateFood(objPos blockOff) {
    srand(static_cast<unsigned int>(time(nullptr)));

    // Do not seed the random number generator here

    do {
        foodPos.x = rand() % 20;
        foodPos.y = rand() % 10;

        std::cout << "Generated food at: " << foodPos.x << ", " << foodPos.y << std::endl;
    } while (foodPos.isPosEqual(&blockOff)); // Ensure isPosEqual() works as intended

    foodPos.symbol = 'o';
}

void SnakeFood::getFoodPos(objPos &returnPos) {
    returnPos = foodPos;
}
