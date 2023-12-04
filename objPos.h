#ifndef OBJPOS_H
#define OBJPOS_H

class objPos
{
public:
    int x;          // X-coordinate of the object position
    int y;          // Y-coordinate of the object position
    char symbol;    // Symbol representing the object

    // Constructors
    objPos();                                   // Default constructor
    objPos(objPos &o);                          // Copy constructor
    objPos(int xPos, int yPos, char sym);       // Parameterized constructor

    // Methods to set and get object position and symbol
    void setObjPos(objPos o);                   // Set object position and symbol using another object
    void setObjPos(int xPos, int yPos, char sym);// Set object position and symbol using individual values
    void getObjPos(objPos &returnPos);          // Get object position

    char getSymbol();                           // Get the symbol of the object

    // Methods to compare object positions and symbols
    bool isPosEqual(objPos* refPos);            // Check if positions are equal
    char getSymbolIfPosEqual(objPos* refPos);   // Get symbol if positions are equal
};

#endif // OBJPOS_H
