#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include "SnakeFood.h"

using namespace std;

#define DELAY_CONST 100000

    GameMechs* myGame;
    Player* myPlayer;
    SnakeFood* myFood;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);


int main() {

    Initialize();

    while (myGame && !myGame->getExitFlagStatus()) {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();
    
    return 0;
}

void Initialize(void) {
    MacUILib_init();
    MacUILib_clearScreen();

    myGame = new GameMechs(30, 15);
    myPlayer = new Player(myGame);

    myFood = new SnakeFood(myGame);
    objPos random;
    myFood->generateFood(random);
}

void GetInput(void) {
    myGame->getInput();
}

void RunLogic(void) {
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();
    myGame->clearInput();
}

void DrawScreen(void) {
    MacUILib_clearScreen();

    objPos tempPos;
    myPlayer->getPlayerPos(tempPos);

    MacUILib_printf("Board Size: %dx%d, Player Position: <%d, %d> + %c\n", myGM->getBoardSizeX(), 
    //                                                                       myGM->getBoardSizeY(), 
    //                                                                       tempPos.x, tempPos.y, tempPos.symbol); 
    // DrawScreen function

    for (int i = 0; i < myGame->getBoardSizeY(); i++) {
        for (int j = 0; j < myGame->getBoardSizeX(); j++) {
            if (i == 0 || i == myGame->getBoardSizeY() - 1 || j == 0 || j == myGame->getBoardSizeX() - 1) {
                cout << '#';
            } else if (j == tempPos.x && i == tempPos.y) {
                cout << tempPos.symbol;
            } else {
                cout << ' ';
            }
        }
        cout << endl;
    }

    printf("score: %d, player pos: <%d,%d>\n", myGM->getScore(), tempPos.x, tempPos.y);

    objPos foodPos;
    myFood->getFoodPos(foodPos);

    cout << "food position: <" << foodPos.x << ", " << foodPos.y << "> + " << foodPos.symbol << endl;
}

void LoopDelay() {
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}

void CleanUp(GameMechs*& myGame, Player*& myPlayer, SnakeFood*& Food) {
    MacUILib_clearScreen();
    MacUILib_uninit();

    delete myGame;
    delete myPlayer;
    delete Food;
}
