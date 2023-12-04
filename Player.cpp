#include "Player.h" // Include Player class header
#include "SnakeFood.h" // Include SnakeFood class header

// Constructor for Player class
Player::Player(GameMechs* thisGMRef, SnakeFood* food)
{
    mainGameMechsRef = thisGMRef; // Set a reference to the main game mechanics
    myDir = STOP; // Initialize the direction to STOP

    playerPosList = new objPosArrayList(); // Create a new objPosArrayList for player positions

    // Initialize the player's initial position in the middle of the board
    objPos initialPos(mainGameMechsRef->getBoardSizeX() / 2, mainGameMechsRef->getBoardSizeY() / 2, '*');
    playerPosList->insertHead(initialPos); // Insert the initial position at the head of the list

    this->food = food; // Set a reference to the SnakeFood object
}

// Destructor for Player class
Player::~Player()
{
    delete playerPosList; // Deallocate memory for the player's position list
}

// Get the position of the player
void Player::getPlayerPos(objPos &returnPos)
{
    objPos headPos;
    playerPosList->getHeadElement(headPos); // Get the head element from the player's position list

    // Assign the head position to the return position
    returnPos.setObjPos(headPos);
}

// Get the player's position list
objPosArrayList* Player::getPlayerPosList()
{
    return playerPosList; // Return the player's position list
}

// Update the direction of the player based on input
void Player::updatePlayerDir()
{
    char input = mainGameMechsRef->getInput(); // Get input from game mechanics

    // Update direction based on input
    switch (input)
    {
        case 'w':
            if (myDir != UP && myDir != DOWN)
                myDir = UP;
            break;
        case 'a':
            if (myDir != LEFT && myDir != RIGHT)
                myDir = LEFT;
            break;
        case 's':
            if (myDir != UP && myDir != DOWN)
                myDir = DOWN;
            break;
        case 'd':
            if (myDir != LEFT && myDir != RIGHT)
                myDir = RIGHT;
            break;
        default:
            break;    
    }
    // PPA3 input processing logic
}

// Move the player based on their current direction
void Player::movePlayer()
{
    objPos currentPos;
    playerPosList->getHeadElement(currentPos); // Get the current head position
    objPos newPos = currentPos;

    // Update the new position based on the current direction
    switch (myDir) {
        case UP:
            newPos.y--;
            break;
        case DOWN:
            newPos.y++;
            break;
        case LEFT:
            newPos.x--;
            break;
        case RIGHT:
            newPos.x++;
            break;
        case STOP:
            break;
    }

    // Handle boundary conditions for the game board
    if (newPos.x < 0) newPos.x = mainGameMechsRef->getBoardSizeX() - 1;
    if (newPos.x >= mainGameMechsRef->getBoardSizeX()) newPos.x = 0;
    if (newPos.y < 0) newPos.y = mainGameMechsRef->getBoardSizeY() - 1;
    if (newPos.y >= mainGameMechsRef->getBoardSizeY()) newPos.y = 0;

    objPos headPos;
    playerPosList->getHeadElement(headPos); // Get the head position of the player
    objPos foodPos;
    food->getFoodPos(foodPos); // Get the position of the food

    // Check for collision with the player's body segments
    for (int i = 1; i < playerPosList->getSize(); ++i) {
        objPos bodySegment;
        playerPosList->getElement(bodySegment, i); // Get each body segment

        // Check for collision with body segment
        if (headPos.x == bodySegment.x && headPos.y == bodySegment.y) {
            mainGameMechsRef->setLoseFlag(); // Set the lose flag in the game mechanics
            mainGameMechsRef->setExitTrue(); // Set the exit flag in the game mechanics
            return; // Exit function if collision detected
        }
    }

    // Handle food collision and movement
    if (headPos.x == foodPos.x && headPos.y == foodPos.y)
    {
        playerPosList->insertHead(newPos); // Insert new position at head
        food->generateFood(playerPosList); // Generate new food
        mainGameMechsRef->incrementScore(); // Increment the score in game mechanics
    }
    else
    {
        playerPosList->insertHead(newPos); // Insert new position at head
        playerPosList->removeTail(); // Remove the last element (tail)
    }

    // PPA3 Finite State Machine logic
}
