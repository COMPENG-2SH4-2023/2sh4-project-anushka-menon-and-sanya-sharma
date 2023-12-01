#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"


using namespace std;

#define DELAY_CONST 100000

GameMechs* myGame;
Player* myPlayer;

bool exitFlag;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);


int main(void)
{

    Initialize();

    while(myGame->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    myGame= new GameMechs(30, 15);
    myPlayer= new Player(myGame);

    exitFlag = false;
}

void GetInput(void)
{
    myGame -> getInput();
   
}

void RunLogic(void)
{
    myPlayer-> updatePlayerDir();
    myPlayer -> movePlayer();
    myGame ->clearInput();
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();
        
        objPos tempPos;
        myPlayer ->getPlayerPos(tempPos);

        for(int i = 0; i < myGame->getBoardSizeY(); i++){

            for(int j =0; j < myGame->getBoardSizeX(); j++){

                if(i == 0 || i == myGame->getBoardSizeY() - 1 || j == 0 || j == myGame->getBoardSizeX() - 1){
                    printf("%c", '#');
                }

                else if(j == tempPos.x && i == tempPos.y){
                    printf("%c", tempPos.symbol);
                }

                else{
                    printf("%c", ' ');
                }
            }
            printf("\n");
        }

    printf("score: %d, player pos: <%d,%d>\n", myGame->getScore(), tempPos.x, tempPos.y);

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();

    delete myGame;
    delete myPlayer;
}
