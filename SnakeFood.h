#ifndef SNAKEFOOD_H
#define SNAKEFOOD_H

#include "GameMechs.h" // Include necessary classes
#include "objPos.h"
#include "objPosArrayList.h"

class SnakeFood {
private:
    objPos foodPos; // Private member holding the position of the food

public:
    // Constructor: initializes the SnakeFood object with a GameMechs reference
    SnakeFood(GameMechs* thisgmref);

    // Destructor: no dynamic memory allocation in this class, so empty
    ~SnakeFood();

    // Function to generate a new position for food without overlapping with the player's positions
    void generateFood(objPosArrayList* playerPosList);

    // Function to retrieve the current food position
    void getFoodPos(objPos &returnPos);
};

#endif // SNAKEFOOD_H
