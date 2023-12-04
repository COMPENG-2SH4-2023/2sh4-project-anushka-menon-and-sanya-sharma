#include <iostream>    // Input/output stream objects
#include "MacUILib.h"  // MacUILib header file
#include "objPos.h"    // Header file for objPos class
#include "GameMechs.h" // Header file for GameMechs class
#include "Player.h"    // Header file for Player class
#include "SnakeFood.h" // Header file for SnakeFood class

using namespace std;

int DELAY_CONST= 70000; // Constant for delay

GameMechs* myGame;   // Pointer to GameMechs object
Player* myPlayer;  // Pointer to Player object
SnakeFood* myFood;   // Pointer to SnakeFood object

// Function prototypes
void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

// Main function
int main()
{
    Initialize(); // Initialization of the game

    // Main game loop
    while (myGame->getExitFlagStatus() == false)
    {
        GetInput();   // Get user input
        RunLogic();   // Execute game logic
        DrawScreen(); // Render game screen
        LoopDelay();  // Introduce delay
    }

    CleanUp(); // Cleanup resources
    return 0;
}

// Initialize function
void Initialize(void)
{
    MacUILib_init();     // Initialize MacUILib
    MacUILib_clearScreen(); // Clear the screen

    myGame = new GameMechs(30, 15); // Create GameMechs object
    myFood = new SnakeFood(myGame);   // Create SnakeFood object with GameMechs reference
    myPlayer = new Player(myGame, myFood); // Create Player object with GameMechs and SnakeFood references

    objPosArrayList* playerPosList = myPlayer->getPlayerPosList(); // Get the player's position list
    objPos random; // Random object

    myFood->generateFood(playerPosList); // Generate food for the game
}

// GetInput function to retrieve user input
void GetInput(void)
{
    myGame->getInput(); // Retrieve user input using GameMechs object
}

// RunLogic function to execute game logic
void RunLogic(void)
{
    myPlayer->updatePlayerDir(); // Update player's direction based on input
    myPlayer->movePlayer();      // Move the player
    myGame->clearInput();          // Clear input for the next iteration
}

// DrawScreen function to render the game screen
void DrawScreen(void)
{
    MacUILib_clearScreen(); // Clear the screen

    objPos tempPos; // Temporary position object
    myPlayer->getPlayerPos(tempPos); // Get player's position

    objPos foodPos; // Food position object
    myFood->getFoodPos(foodPos); // Get food position

    // Loop to draw the game board and elements
    for (int i = 0; i < myGame->getBoardSizeY(); i++)
    {
        for (int j = 0; j < myGame->getBoardSizeX(); j++)
        {
            // Drawing the game board boundaries and player elements
            if (i == 0 || i == myGame->getBoardSizeY() - 1 || j == 0 || j == myGame->getBoardSizeX() - 1)
            {
                printf("%c", '#'); // Draw the boundary
            }
            else
            {
                objPos playerPos;
                myPlayer->getPlayerPos(playerPos); // Get player's position

                bool isSnakeSegment = false;
                objPosArrayList* playerPosList = myPlayer->getPlayerPosList(); // Get player's position list
                for (int k = 0; k < playerPosList->getSize(); k++)
                {
                    objPos snakeSegment;
                    playerPosList->getElement(snakeSegment, k); // Get snake segments from the list

                    // Draw snake segments
                    if (snakeSegment.x == j && snakeSegment.y == i)
                    {
                        printf("%c", snakeSegment.symbol); // Draw snake segment
                        isSnakeSegment = true;
                        break;
                    }
                }

                // Draw food or empty space
                if (!isSnakeSegment && j == foodPos.x && i == foodPos.y)
                {
                    printf("%c", foodPos.symbol); // Draw food symbol
                }
                else if (!isSnakeSegment)
                {
                    printf("%c", ' '); // Draw empty space
                }
            }
        }
        printf("\n"); // Move to the next line
    }

    // Display game information for debugging
    printf("Your Score: %d\n", myGame->getScore());
    printf("Board Size 30 x 15\n");
    printf("Player Position: %d, %d", tempPos.x, tempPos.y);
    
    if((myGame->getScore())>-1 && (myGame->getScore())<5){
        printf("\nLevel 1\n");
    }
    else if((myGame->getScore())>5 && (myGame->getScore())<10){
        printf("\nLevel 2. Higher Speed\n");
    }
    else{
        printf("\nLevel 3. Higher Speed\n");
    }
}

// LoopDelay function to introduce delay in the game
void LoopDelay(void)
{
    // PPA3 input processing logic
    if((myGame->getScore())>0 && (myGame->getScore())<5){
        myGame->incrementGame();
        MacUILib_Delay(100000); // Introduce delay (0.1 seconds)

    }
    else if((myGame->getScore())>5 && (myGame->getScore())<10){
        myGame->incrementGame();
        MacUILib_Delay(150000); // Introduce delay (0.1 seconds)


    }
    else{
        myGame->incrementGame();
        MacUILib_Delay(200000); // Introduce delay (0.1 seconds)

    }
}

// CleanUp function to free resources
void CleanUp(void)
{
    MacUILib_clearScreen(); // Clear the screen
    MacUILib_uninit();      // Uninitialize MacUILib

    delete myGame;    // Free GameMechs object
    delete myPlayer; // Free Player object
    delete myFood;     // Free SnakeFood object
}
