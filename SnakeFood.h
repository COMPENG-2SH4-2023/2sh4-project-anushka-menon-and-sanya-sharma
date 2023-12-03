// SnakeFood.h
#ifndef SNAKEFOOD_H
#define SNAKEFOOD_H

#include "objPos.h"
#include "GameMechs.h"

class SnakeFood {
private:
    objPos foodPos;

public:
    SnakeFood(GameMechs* thisgmref);
    ~SnakeFood();

    void generateFood(objPos blockOff);
    void getFoodPos(objPos &returnPos);
};

#endif // SNAKEFOOD_H
