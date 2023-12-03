#ifndef PLAYER_H
#define PLAYER_H

#include "objPos.h"       // Include necessary headers
#include "GameMechs.h"    // Include necessary headers
#include "objPosArrayList.h"

class objPos;//THIS IS FOR FORWARD HANDLING. DO NOT REMOVE
class GameMechs; //THIS IS FOR FORWARD HANDLING. DO NOT REMOVE


class Player {
public:
    enum Dir { UP, DOWN, LEFT, RIGHT, STOP };  // This is the direction state

    Player(GameMechs* thisGMRef);
    ~Player();

    void getPlayerPos(objPos &returnPos); // Upgrade this in iteration 3.
    void updatePlayerDir();
    void movePlayer();

private:
    objPos playerPos;          // Upgrade this in iteration 3.
    enum Dir myDir;
    char input;

    // Need a reference to the Main Game Mechanisms
    GameMechs* mainGameMechsRef;
};

#endif // PLAYER_H
