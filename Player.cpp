#include "Player.h"
#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"

Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2, mainGameMechsRef->getBoardSizeY()/2, '*');

}

Player::~Player()
{
    // delete any heap members here
}

void Player::getPlayerPos(objPos &returnPos)
{
    // return the reference to the playerPos arrray list
    returnPos.setObjPos(playerPos.x,playerPos.y,playerPos.symbol);

}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic   
    char input = mainGameMechsRef -> getInput();

    switch (input)
    {
        case 'w':
            if (myDir != UP && myDir!= DOWN)
                myDir = UP;
            break;
        case 'a':
            if (myDir != LEFT && myDir!= RIGHT)
                myDir = LEFT;
            break;
        case 's':
            if (myDir != UP && myDir!= DOWN)
                myDir = DOWN;
            break;
        case 'd':
            if (myDir != LEFT && myDir!= RIGHT)
                myDir = RIGHT;
            break;
        case ' ':  //exit using space bar
            myDir= STOP;
            break;

        default:
            break;
        
    } 

}

void Player::movePlayer()
{
    switch (myDir) {
        case UP:
            playerPos.y--;
            break;
        case DOWN:
            playerPos.y++;
            break;
        case LEFT:
            playerPos.x--;
            break;
        case RIGHT:
            playerPos.x++;
            break;
        case STOP:
           // myGame1 ->setExitTrue(); 
            break;
    }

    if (playerPos.x < 0) playerPos.x = mainGameMechsRef->getBoardSizeX() - 1;
    if (playerPos.x >= mainGameMechsRef->getBoardSizeX()) playerPos.x = 0;
    if (playerPos.y < 0) playerPos.y = mainGameMechsRef->getBoardSizeY() - 1;
    if (playerPos.y >= mainGameMechsRef->getBoardSizeY()) playerPos.y = 0;
    // PPA3 Finite State Machine logic
}

